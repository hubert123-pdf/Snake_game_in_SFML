#ifndef SNAKE_SCENE_HPP
#define SNAKE_SCENE_HPP


#include "Snake.hpp"

#define SIZE_OF_PIXEL 16

class Scene
{
    private:
        int width,height;
        Texture board;
        Sprite board_sprite; 
        unsigned score;
        Font font;
        Text text;
        std::unique_ptr<Snake> snake;
    public:
        Scene();
        void start();
        bool ifFault(){
            if(snake->getBlock(0).x<0 || snake->getBlock(0).x>=W) {return true;}
            if(snake->getBlock(0).y<0 || snake->getBlock(0).y>=H) {return true;}
            return false;
        }
        void restart(){
          snake=std::make_unique<Snake>();
        }
        void tick();
};

#endif