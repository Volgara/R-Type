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
    namespace graphics {

        class GraphicsTests: public ::testing::Test{
        protected:
            virtual void SetUp() {
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

                //engine::graphics::GraphicSystem *graphicSystem = new engine::graphics::GraphicSystem();

                //gc->play("mommy");

                //graphicSystem->Update(1);
            }

            engine::graphics::GraphicsComponent *gc = new engine::graphics::GraphicsComponent();
            engine::graphics::SpriteSheet shipSheet = engine::graphics::SpriteSheet("assets/mummy.png", 185, 225, 5, 5);
            engine::graphics::Animation *mommy = new engine::graphics::Animation("mommy", &shipSheet);
            engine::graphics::Animation *mommy2 = new engine::graphics::Animation("mommy2", &shipSheet);
        };


        TEST_F(GraphicsTests, checkAnimationsSizeNotEmpty) {
            ASSERT_EQ(1, gc->getAnimations().size());
        }

        TEST_F(GraphicsTests, animationCannotAddTwoTimesSame) {
            ASSERT_THROW(gc->addAnimation(mommy), std::runtime_error);
        }

        TEST_F(GraphicsTests, checkAnimationsSizeAfterAddingOneAnim) {
            mommy2->addFrame(0, 0);
            gc->addAnimation(mommy2);
            ASSERT_EQ(2, gc->getAnimations().size());
        }

        TEST_F(GraphicsTests, checkFirstAnimationNumberOfFramesNotEmpty) {
            ASSERT_EQ(18, gc->getAnimations()[0]->getFrames().size());
        }

        TEST_F(GraphicsTests, checkCurrentAnimationIs0EvenIfNotDefined) {
            ASSERT_EQ(0, gc->getCurrentAnimationIndex());
        }

        TEST_F(GraphicsTests, checkCurrentFrameUpdate) {
            //By default current animation is 0

            std::cout << "There are " << gc->getCurrentAnimation()->getFrames().size() << " frames" << std::endl;
            ASSERT_EQ(0, gc->getAnimations()[gc->getCurrentAnimationIndex()]->getCurrenFrame());
            //gc->update(1);
            ASSERT_EQ(1, gc->getAnimations()[gc->getCurrentAnimationIndex()]->getCurrenFrame());
        }

        TEST_F(GraphicsTests, checkCurrentFrameUpdateWhenOverflowNoLoop) {
            //By default current animation is 0

            std::cout << "There are " << gc->getCurrentAnimation()->getFrames().size() << " frames" << std::endl;
            gc->getCurrentAnimation()->setCurrentFrame(17);
            ASSERT_EQ(17, gc->getCurrentAnimation()->getCurrenFrame());
            gc->update(1);
            ASSERT_EQ(17, gc->getCurrentAnimation()->getCurrenFrame());
        }

        TEST_F(GraphicsTests, checkCurrentFrameUpdateWhenOverflowPingpong) {
            //By default current animation is 0

            std::cout << "There are " << gc->getCurrentAnimation()->getFrames().size() << " frames" << std::endl;
            gc->getCurrentAnimation()->setCurrentFrame(17);
            gc->getCurrentAnimation()->setPingPong(true);
            ASSERT_EQ(17, gc->getCurrentAnimation()->getCurrenFrame());
            gc->update(1);
            ASSERT_EQ(16, gc->getCurrentAnimation()->getCurrenFrame());
        }

        TEST_F(GraphicsTests, checkCurrentFrameUpdateWhenOverflowLoop) {
            //By default current animation is 0

            std::cout << "There are " << gc->getCurrentAnimation()->getFrames().size() << " frames" << std::endl;
            gc->getCurrentAnimation()->setCurrentFrame(17);
            gc->getCurrentAnimation()->setLoop(true);
            ASSERT_EQ(17, gc->getCurrentAnimation()->getCurrenFrame());
            gc->update(1);
            ASSERT_EQ(0, gc->getCurrentAnimation()->getCurrenFrame());
        }

       /**
        * Reverse
        */

        TEST_F(GraphicsTests, checkCurrentFrameUpdateWhenOverflowReverse) {
            //By default current animation is 0

            std::cout << "There are " << gc->getCurrentAnimation()->getFrames().size() << " frames" << std::endl;
            gc->getCurrentAnimation()->setCurrentFrame(17);
            ASSERT_EQ(5, gc->getCurrentAnimation()->getCurrenFrame());
            gc->update(1);
            ASSERT_EQ(4, gc->getCurrentAnimation()->getCurrenFrame());
        }

        TEST_F(GraphicsTests, checkCurrentFrameUpdateWhenOverflowNoLoopReverse) {
            //By default current animation is 0

            std::cout << "There are " << gc->getCurrentAnimation()->getFrames().size() << " frames" << std::endl;
            gc->getCurrentAnimation()->setCurrentFrame(17);
            ASSERT_EQ(0, gc->getCurrentAnimation()->getCurrenFrame());
            gc->update(1);
            ASSERT_EQ(0, gc->getCurrentAnimation()->getCurrenFrame());
        }

        TEST_F(GraphicsTests, checkCurrentFrameUpdateWhenOverflowLoopReverse) {
            //By default current animation is 0

            std::cout << "There are " << gc->getCurrentAnimation()->getFrames().size() << " frames" << std::endl;
            gc->getCurrentAnimation()->setCurrentFrame(17);
            ASSERT_EQ(0, gc->getCurrentAnimation()->getCurrenFrame());
            gc->update(1);
            ASSERT_EQ(17, gc->getCurrentAnimation()->getCurrenFrame());
        }

        TEST_F(GraphicsTests, checkCurrentFrameUpdateWhenOverflowPingpongReverse) {
            //By default current animation is 0

            std::cout << "There are " << gc->getCurrentAnimation()->getFrames().size() << " frames" << std::endl;
            gc->getCurrentAnimation()->setCurrentFrame(17);
            gc->getCurrentAnimation()->setPingPong(true);
            ASSERT_EQ(0, gc->getCurrentAnimation()->getCurrenFrame());
            gc->update(1);
            ASSERT_EQ(1, gc->getCurrentAnimation()->getCurrenFrame());
        }

        //TODO missing some tests, need cleanup
    }
}