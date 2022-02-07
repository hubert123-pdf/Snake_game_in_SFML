#include "../inc/Scene.hpp"
void Scene::start()
{
    float timer, delay=0.1;
    Clock clock;
    sf::RenderWindow window(sf::VideoMode(width+250,height), "SNAKE");
    while(window.isOpen())
    {
        Event e;
        float time=clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        snake->setTime(time+snake->getTime());

        while(window.pollEvent(e)){
            if(e.type==Event::Closed){
                window.close();
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::Left) && snake->getDirection()!=2) {snake->setDirection(1);}
        if(Keyboard::isKeyPressed(Keyboard::Right)&& snake->getDirection()!=1) {snake->setDirection(2);}
        if(Keyboard::isKeyPressed(Keyboard::Up)&& snake->getDirection()!=0) {snake->setDirection(3);}
        if(Keyboard::isKeyPressed(Keyboard::Down)&& snake->getDirection()!=3) {snake->setDirection(0);}

        if(timer>delay) {
            timer=0;
            tick();
        }
        if(ifFault())
        {
            while(!Keyboard::isKeyPressed(Keyboard::Space)){
                window.draw(lose);
                window.display();
            }
            restart();
            clock.restart();
        }
        window.clear();

       
        for(int i=0;i<snake->getLength();i++){
            snake->getSnakeSprite().setPosition(snake->getBlock(i).x*SIZE_OF_PIXEL,snake->getBlock(i).y*SIZE_OF_PIXEL);
            fruit->fruit_sprite.setPosition(fruit->getPosition().x*SIZE_OF_PIXEL,fruit->getPosition().y*SIZE_OF_PIXEL);
            window.draw(snake->getSnakeSprite());
            window.draw(fruit->fruit_sprite);
        }
        
        time_str="Time: "+std::to_string(snake->getTime())+"s";
        points_str="Points: "+std::to_string(score);
        display(window);
    }           
}
Scene::Scene():width(W*SIZE_OF_PIXEL),height(H*SIZE_OF_PIXEL),score(0)
{
    board.loadFromFile("../images/white.png");
    board_sprite.setTexture(board);
    font.loadFromFile("../fonts/OpenSans-Bold.ttf");

    lose.setString("You lose, press space to try again.");
    lose.setFont(font);
    lose.setPosition(W/10*SIZE_OF_PIXEL,H/2*SIZE_OF_PIXEL);

    points.setFont(font);
    points.setPosition(width+10,10);

    time_s.setFont(font);
    time_s.setPosition(width+10,height-40);
    snake=std::make_unique<Snake>();
    fruit=std::make_unique<Fruit>();
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

    if(snake->getBlock(0).x==fruit->getPosition().x &&snake->getBlock(0).y==fruit->getPosition().y)
    {
        score++;
        snake->setLength(snake->getLength()+1);
        fruit->setPosition(rand()%W,rand()%H);
    }
}
void Scene::display(sf::RenderWindow& window)
{
    sf::RectangleShape rectangle(sf::Vector2f(250, height));
    rectangle.setFillColor(sf::Color(0, 255, 0));
    rectangle.setPosition(width,0);

    points.setString(points_str);
    time_s.setString(time_str);
    window.draw(rectangle);
    window.draw(points);
    window.draw(time_s);
    window.display();
}
