#include "../inc/Scene.hpp"
void Scene::start()
{
    float timer, delay=0.1;
    Clock clock;
    sf::RenderWindow window(sf::VideoMode(width,height), "SNAKE");
    
    while(window.isOpen())
    {
        Event e;
        float time=clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        while(window.pollEvent(e)){
            if(e.type==Event::Closed){
                window.close();
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::Left) && snake->getDirection()!=2) {snake->setDirection(1);}
        if(Keyboard::isKeyPressed(Keyboard::Right)&& snake->getDirection()!=1) {snake->setDirection(2);}
        if(Keyboard::isKeyPressed(Keyboard::Up)&& snake->getDirection()!=3) {snake->setDirection(3);}
        if(Keyboard::isKeyPressed(Keyboard::Down)&& snake->getDirection()!=0) {snake->setDirection(0);}

        if(timer>delay) {
            timer=0;
            tick();
        }
        if(ifFault())
        {
            while(!Keyboard::isKeyPressed(Keyboard::Space)){
                window.draw(text);
                window.display();
            }
            restart();
        }
        window.clear();

       
        for(int i=0;i<snake->getLength();i++){
            snake->getSnakeSprite().setPosition(snake->getBlock(i).x*SIZE_OF_PIXEL,snake->getBlock(i).y*SIZE_OF_PIXEL);
            window.draw(snake->getSnakeSprite());
        }
        
        window.display();
    }           
}
Scene::Scene():width(W*SIZE_OF_PIXEL),height(H*SIZE_OF_PIXEL),score(0)
{
    board.loadFromFile("../images/white.png");
    board_sprite.setTexture(board);
    font.loadFromFile("../fonts/OpenSans-Bold.ttf");
    text.setString("You lose, press space to try again.");
    text.setFont(font);
    snake=std::make_unique<Snake>();
}
void Scene::tick()
{

    for (int  i = snake->getLength(); i >0; --i){
        snake->setBlock(i,snake->getBlock(i-1).x,snake->getBlock(i-1).y);
    }

    if(snake->getDirection()==0) {snake->setBlock(0,snake->getBlock(0).x,snake->getBlock(0).y+1);}
    if(snake->getDirection()==1) {snake->setBlock(0,snake->getBlock(0).x-1,snake->getBlock(0).y);}
    if(snake->getDirection()==2) {snake->setBlock(0,snake->getBlock(0).x+1,snake->getBlock(0).y);}
    if(snake->getDirection()==3) {snake->setBlock(0,snake->getBlock(0).x,snake->getBlock(0).y-1);}
}