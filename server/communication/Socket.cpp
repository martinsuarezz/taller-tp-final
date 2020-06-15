#include "Socket.h"

#include <unistd.h>
#include <cstring>
#include <netdb.h>
#include <vector>

typedef struct addrinfo addrinfo_t;

Socket::Socket() {}

Socket::Socket(int skt) {
  this->skt = skt;
}

Socket::Socket(Socket &&other) {
  this->skt = other.skt;
  other.skt = -1;
}

addrinfo_t *get_addr_info(const char* hostname,
                          const char* port, int flags) {
  addrinfo_t hints;
  addrinfo_t *addr_info;

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;       /* IPv4 (or AF_INET6 for IPv6)     */
  hints.ai_socktype = SOCK_STREAM; /* TCP  (or SOCK_DGRAM for UDP)    */
  hints.ai_flags = flags;          /* None (or AI_PASSIVE for server) */

  int s = getaddrinfo(hostname, port, &hints, &addr_info);

  if (s != 0) {
    freeaddrinfo(addr_info);
    throw SocketConnectionException();
  }

  return addr_info;
}

void Socket::connect(const std::string& host, const std::string& port) {
  bool is_connected = false;
  int s = 0;
  int skt = 0;

  addrinfo_t *addr_info = get_addr_info(host.c_str(), port.c_str(), 0);

  if (addr_info == NULL) {
    this->close();
    throw SocketConnectionException();
  }

  for (addrinfo_t *ptr = addr_info; ptr != NULL && !is_connected;
       ptr = ptr->ai_next) {
    skt = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

    if (skt == -1) {
      throw SocketConnectionException();
    }

    s = ::connect(skt, ptr->ai_addr, ptr->ai_addrlen);

    if (s == -1) {
      ::close(skt);
      freeaddrinfo(addr_info);
      throw SocketConnectionException();
    }

    is_connected = (s != -1);
  }

  this->skt = skt;

  freeaddrinfo(addr_info);
}

void Socket::bind(const std::string& port) {
  int skt = 0;
  int s = 0;
  bool is_connected = false;

  addrinfo_t *addr_info = get_addr_info(NULL, port.c_str(), AI_PASSIVE);

  if (addr_info == NULL) {
    this->close();
  }

  for (addrinfo_t *ptr = addr_info; ptr != NULL && !is_connected;
       ptr = ptr->ai_next) {
    skt = socket(addr_info->ai_family,
                 addr_info->ai_socktype,
                 addr_info->ai_protocol);

    if (skt == -1) {
      freeaddrinfo(addr_info);
      throw SocketConnectionException();
    }

    s = ::bind(skt, addr_info->ai_addr, addr_info->ai_addrlen);

    if (s == -1) {
      this->close();
      freeaddrinfo(addr_info);
      throw SocketConnectionException();
    }

    is_connected = (s != -1);
  }

  this->skt = skt;

  freeaddrinfo(addr_info);
}

void Socket::listen(int maxPendingConnections) {
  ::listen(skt, maxPendingConnections);
}

void Socket::close() {
  ::shutdown(skt, SHUT_RDWR);
  ::close(skt);
}

Socket Socket::accept() {
  int s = ::accept(skt, NULL, NULL);

  if (s == -1) {
    close();
    throw SocketConnectionException();
  }

  Socket acceptSocket(s);

  return acceptSocket;
}

void Socket::send(const std::string &message) {
  int sent = 0;
  int s = 0;
  int size = message.size();

  while (sent < size) {
    s = ::send(this->skt, &message[sent], size - sent, SO_NOSIGPIPE);

    if (s <= 0) {
      throw SocketConnectionException();
    } else {
      sent += s;
    }
  }
}

std::string Socket::recv(int size) {
  std::vector<char> buffer(size);
  int received = 0;
  int s = 0;

  while (received < size) {
    s = ::recv(this->skt, buffer.data(), size - received, 0);

    if (s <= 0) {
      throw SocketConnectionException();
    } else {
      received += s;
    }
  }

  std::string str(buffer.begin(), buffer.end());

  return str;
}
