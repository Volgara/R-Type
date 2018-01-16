/*****************************************************************
** Created by Quentin GOINAUD <armaldio@gmail.com> on 11/01/2018.*
** Copyright (c) 2018 Armaldio - All rights reserved.            *
*****************************************************************/

#include <iostream>
#include "RTypeGraphics.hpp"

/**
 * How to add frames
 *
 * shipAnimIdle.setAnimationFrames(0, 5);
    // - or -
    shipAnimIdle.addFrame(0, 0, 0);
    shipAnimIdle.addFrame(1, 0, 1);
    shipAnimIdle.addFrame(2, 0, 2);
    shipAnimIdle.addFrame(3, 0, 3);
    shipAnimIdle.addFrame(4, 0, 4);
 */

int main() {

    // Load a spritesheet
    RType::SpriteSheet shipSheet = RType::SpriteSheet("./ship.png", 192, 16, 6, 1);

    // Create an animation based on the spritesheet
    RType::Animation shipAnimIdle = RType::Animation("idle", shipSheet);
    shipAnimIdle.addFrame(0, 0, 2); // image in the middle

    RType::Animation shipAnimGoDown = RType::Animation("down", shipSheet);
    shipAnimGoDown.addFrame(0, 0, 1);
    shipAnimGoDown.addFrame(1, 0, 0);

    RType::Animation shipAnimGoUp = RType::Animation("up", shipSheet);
    shipAnimGoUp.addFrame(0, 0, 2);
    shipAnimGoUp.addFrame(0, 0, 3);


    // Create a Game object and add to it the animation
    RType::GameObject ship;
    ship.addAnimation(shipAnimIdle);
    ship.addAnimation(shipAnimGoDown);
    ship.addAnimation(shipAnimGoUp);

    ship.play("idle", false);

    return 0;
}