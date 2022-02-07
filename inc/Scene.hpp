#ifndef SNAKE_SCENE_HPP
#define SNAKE_SCENE_HPP


#include "Snake.hpp"
#include "Fruit.hpp"
#include<math.h>

#define SIZE_OF_PIXEL 16

class Scene
{
    private:
        int width,height; 
        unsigned score;
        std::unique_ptr<Snake> snake;
        std::unique_ptr<Fruit> fruit;
        Texture board;
        Sprite board_sprite;
        Font font;
        Text lose,points,time_s;
        std::string points_str,time_str;
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
          fruit=std::make_unique<Fruit>();
          score=0;
        }
        void tick();
        void display(sf::RenderWindow& window);
};

#endif