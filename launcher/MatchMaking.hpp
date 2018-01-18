/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 18/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_MATCHMAKING_HPP
#define RTYPE_MATCHMAKING_HPP

#include <string>
class MatchMaking {
 public:
  MatchMaking();
  virtual ~MatchMaking();

 public:
  bool connect(const std::string &ip);
};

#endif //RTYPE_MATCHMAKING_HPP
