cmake_minimum_required(VERSION 3.15)
project(argentum)

set(CMAKE_CXX_STANDARD 11)

add_executable(server server/main.cpp server/Game.cpp server/Game.h server/World.cpp server/World.h
        server/entities/Player.cpp server/entities/Player.h server/entities/Creature.cpp
        server/entities/Creature.h server/entities/Character.cpp server/entities/Character.h
        server/entities/Entity.cpp server/entities/Entity.h server/entities/Entity.cpp server/entities/Entity.h
        server/Map.cpp server/Map.h server/entities/Item.cpp server/entities/Item.h server/Inventory.cpp
        server/Inventory.h server/Server.cpp server/Server.h server/communication/Socket.cpp
        server/communication/Socket.h server/communication/Listener.cpp server/communication/Listener.h
        server/Thread.cpp server/Thread.h server/communication/Queue.cpp server/communication/Queue.h
        server/communication/ClientPeer.cpp server/communication/ClientPeer.h
        server/Command.cpp server/Command.h server/communication/GameLoop.cpp server/communication/GameLoop.h
        server/communication/ClientSender.cpp server/communication/ClientSender.h server/communication/ClientReceiver.cpp
        server/communication/ClientReceiver.h server/EventManager.cpp server/EventManager.h common/Clock.cpp
        common/Clock.h server/state/State.cpp server/state/State.h server/state/WalkingState.cpp server/state/WalkingState.h
        server/state/IdleState.cpp server/state/IdleState.h)