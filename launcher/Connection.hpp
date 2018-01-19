/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_MATCHMAKING_HPP
#define RTYPE_MATCHMAKING_HPP

#include <string>
#include <SFML/Graphics/Text.hpp>
#include <network/Socket.hpp>
#include "Room.hpp"
class Connection {
 public:
  Connection();
  virtual ~Connection();

  std::vector<Room> getRoomsFound();
 public:
  void addRoomFound(const std::string &name, int nbPlayers);
  void emptyRoomsFound();
  bool connect(const std::string &ip, int port);
  std::string getList();
  std::string createAndJoin(const std::string &str);

 private:
  std::string             _ip;
  int                     _port;
  engine::Network::Socket *sok;
  std::vector<Room>       _roomsFound;
};

#endif //RTYPE_MATCHMAKING_HPP
