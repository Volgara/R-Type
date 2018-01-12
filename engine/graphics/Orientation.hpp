/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 12/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#ifndef RTYPE_ORIENTATION_HPP
#define RTYPE_ORIENTATION_HPP


namespace RType {
    class Orientation {
    public:
        Orientation();

        virtual ~Orientation();

    public:
        int angle;

        int getAngle() const;

        void setAngle(int angle);
    };
}


#endif //RTYPE_ORIENTATION_HPP
