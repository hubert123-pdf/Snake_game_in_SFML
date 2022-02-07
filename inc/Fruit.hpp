#ifndef SNAKE_FRUIT_HPP
#define SNAKE_FRUIT_HPP

#include "Snake.hpp"


class Fruit
{
    struct fruit_position
    {
        int x,y;
    }fruit_pos;

    public:
    Texture fruit_texture;
    Sprite fruit_sprite;
    Fruit()
    {
        fruit_pos.x=rand()%W;
        fruit_pos.y=rand()%H;
        fruit_texture.loadFromFile("../images/red.png");
        fruit_sprite.setTexture(fruit_texture);
    }
    const fruit_position getPosition()const{ return fruit_pos;} 
    void setPosition(int x, int y) { fruit_pos.x=x; fruit_pos.y=y;}
};
#endif