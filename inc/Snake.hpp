#ifndef SNAKE_SNAKE_HPP
#define SNAKE_SNAKE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#define W 40
#define H 30
#define SPEED 10
#define START_LENGTH 9
using namespace sf;

class Snake
{
    struct block{
        int x,y;
    }s[W*H];
    float time_of_play;
    int direction,length;
    float speed;
    Font font;
    Texture texture_of_snake;
    Sprite snake_sprite;

    public:
    Snake():speed(SPEED),length(START_LENGTH),direction(2),time_of_play(0.00f)
    {
        for (int  i = 0; i < length; i++)
        {
            s[i].x=W/2;
            s[i].y=H/2;
        }
        texture_of_snake.loadFromFile("../images/green.png");
        snake_sprite.setTexture(texture_of_snake);

    }
    Sprite& getSnakeSprite(){ return snake_sprite;}
    void setSnakeSprite(int x, int y){
        snake_sprite.setPosition(x,y);
    }
    const int getDirection() const {return direction;}
    void setDirection(int x){direction=x;}
    const int getLength() const{return length;}
    void setLength(int x) {length=x;}
    const float getTime()const {return time_of_play;}
    void setTime(float x){time_of_play=x;}
    block getBlock(int i) const {return s[i];}
    void setBlock(int i ,int x,int y) {this->s[i].x=x; this->s[i].y=y;}

};

#endif