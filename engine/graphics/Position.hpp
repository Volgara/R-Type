/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_POSITION_HPP
#define RTYPE_POSITION_HPP

namespace RType {
    class Position {
    public:
        Position();

        Position(int x, int y);

        virtual ~Position();

    public:
        int x;
        int y;
    };
}

#endif //RTYPE_POSITION_HPP
