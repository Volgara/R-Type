/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_MATCHMAKING_HPP
#define RTYPE_MATCHMAKING_HPP

#include <string>
#include <SFML/Graphics/Text.hpp>
#include <network/Socket.hpp>
class Connection {
 public:
  Connection(const std::string &ip, int port);
  virtual ~Connection();

 public:
  bool connect();
  std::string getList();
  std::string createAndJoin(const std::string &str);

 private:
  std::string _ip;
  int _port;
  engine::Network::Socket *sok;
};

#endif //RTYPE_MATCHMAKING_HPP
