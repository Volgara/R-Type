/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 19/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_ROOM_HPP
#define RTYPE_ROOM_HPP

#include <string>
class Room {
 public:
  Room(const std::string &name, int nbPlayers);
  virtual ~Room();

 private:
  std::string _name;
  int         _nbPlayers;
};

#endif //RTYPE_ROOM_HPP
