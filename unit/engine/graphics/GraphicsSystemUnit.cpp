//
// Created by Hamza Hammouche on 15/01/2018.
//

#include <gtest/gtest.h>
#include "graphics/GraphicsComponent.hpp"
#include "graphics/GraphicsSystem.hpp"
#include "graphics/Animation.hpp"
#include "graphics/SpriteSheet.hpp"
#include <SFML/Graphics/Sprite.hpp>

namespace engine {
    namespace physics {
        TEST(GraphicSystemTest, InitTest) {
            //engine::graphics::GraphicSystem *graphicSystem = new engine::graphics::GraphicSystem();

            engine::graphics::GraphicsComponent *gc = new engine::graphics::GraphicsComponent();
            engine::graphics::SpriteSheet shipSheet = engine::graphics::SpriteSheet("assets/mummy.png", 185, 225, 5, 5);
            engine::graphics::Animation *mommy = new engine::graphics::Animation("mommy", &shipSheet);
            mommy->addFrame(0, 0);
            mommy->addFrame(0, 1);
            mommy->addFrame(0, 2);
            mommy->addFrame(0, 3);
            mommy->addFrame(0, 4);

            mommy->addFrame(1, 0);
            mommy->addFrame(1, 1);
            mommy->addFrame(1, 2);
            mommy->addFrame(1, 3);
            mommy->addFrame(1, 4);

            mommy->addFrame(2, 0);
            mommy->addFrame(2, 1);
            mommy->addFrame(2, 2);
            mommy->addFrame(2, 3);
            mommy->addFrame(2, 4);

            mommy->addFrame(3, 0);
            mommy->addFrame(3, 1);
            mommy->addFrame(3, 2);

            mommy->setLoop(true);
            mommy->setPingPong(true);
            mommy->setCurrentFrame(0);

            gc->addAnimation(mommy);

            //gc->play("mommy");

            //graphicSystem->Update(1);

            ASSERT_EQ(1, gc->getAnimations().size());
            ASSERT_EQ(18, gc->getAnimations()[0]->getFrames().size());
        }
    }
}