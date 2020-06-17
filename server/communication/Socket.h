#ifndef ARGENTUM_COMMON_SOCKET_H_
#define ARGENTUM_COMMON_SOCKET_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <string>

struct SocketConnectionException : public std::exception {
  const char *what() const throw() {
    return "Cannot establish connection";
  }
};

class Socket {
 public:
  Socket();
  Socket(Socket&& other);
  Socket &operator=(Socket &&other);

  explicit Socket(int skt);

  void connect(const std::string &host, const std::string &port);
  void bind(const std::string &port);
  void listen(int maxPendingConnections);
  void send(const std::string &message);
  std::string recv(int size);
  void close();
  Socket accept();
 private:
  int skt;
};

#endif
