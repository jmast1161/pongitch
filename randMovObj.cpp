#include "randMovObj.h"

void randMovObj::initRandMovObj(string objFile, int x, int y)
{
    elapsedTime = (float) clock.getElapsedTime().asSeconds();
    texture.loadFromFile(objFile.c_str());
    sprite.setTexture(texture);
    bounds = sprite.getLocalBounds();
    xPos = x;
    yPos = y;
    sprite.setPosition(xPos, yPos);
    speed = 500;
    srand(time(NULL));
    _angle = (float) (rand() % 360);
    if(_angle < 10 || (_angle > 80 && _angle < 100) || (_angle > 170 && _angle < 190) || (_angle > 260 && _angle < 280) || _angle > 350)
        _angle += 30;
    posRect = sf::FloatRect(xPos, yPos, bounds.width, bounds.height);
    rightRect = sf::FloatRect(xPos + bounds.width, yPos + 2, 5, bounds.height - 4);
    leftRect = sf::FloatRect(xPos - 5, yPos + 2, 5, bounds.height - 4);
}

void randMovObj::showRandMovObj(RenderWindow& Window)
{
    Window.draw(sprite);
}

void randMovObj::updateRMOPos(void)
{
    elapsedTime = (float)clock.restart().asSeconds();
    moveAmount = elapsedTime * speed;
    xPos += newXPos(_angle) * moveAmount;
    yPos += newYPos(_angle) * moveAmount;
    sprite.setPosition(xPos, yPos);
    detectScreenCollision();
    posRect = sf::FloatRect(xPos, yPos, bounds.width, bounds.height);
    rightRect = sf::FloatRect(xPos + bounds.width, yPos + 2, 5, bounds.height - 4);
    leftRect = sf::FloatRect(xPos - 5, yPos + 2, 5, bounds.height - 4);
}

void randMovObj::detectScreenCollision(void)
{
    if(xPos <= 0)
    {
        _angle = 360 - _angle;
        xPos++; //add 1 so ball does not get stuck on wall
    }
    else if(xPos + bounds.width >= 1024)
        _angle = 360.0 - _angle;

    if(yPos < 0)
    {
        resetPos();
        //_angle = 180 - _angle;
        //yPos++;  //add 1 so ball does not get stuck on wall
    }
    else if(yPos + bounds.height >= 768)
    {
        resetPos();
        //_angle = 180.0 - _angle;
    }
}

void randMovObj::detectObjCollision(FloatRect objRect)
{
    if(posRect.intersects(objRect))
        if(yPos + (int)bounds.height/2.0f < objRect.top)
        {
            _angle = 180 - _angle;
            yPos -= 5;
        }
        else if(yPos + (int)bounds.height/2.0f > objRect.top + objRect.height)
        {
            _angle = 180 - _angle;
            yPos += 5;
        }
        else if(xPos + (int)bounds.width/2.0f < objRect.left)
        {
            _angle = 360 - _angle;
            xPos -= 5;
        }
        else if(xPos + (int)bounds.width/2.0f > objRect.left + objRect.width)
        {
            _angle = 360 - _angle;
            xPos += 5;
        }
        
}

float randMovObj::newXPos(float angle)
{
    angle -= 90;
    if (angle < 0) angle = 360 + angle;
    return (float)cos(angle * ( 3.1415926 / 180.0f ));
}

float randMovObj::newYPos(float angle)
{
    angle -= 90;
    if (angle < 0) angle = 360 + angle;
    return (float)sin(angle * ( 3.1415926 / 180.0f ));
}

void randMovObj::resetPos(void)
{
    xPos = 1024/2;
    yPos = 768/2;
    sprite.setPosition(xPos, yPos);
    _angle = (float) (rand() % 360);
    if(_angle < 10 || (_angle > 80 && _angle < 100) || (_angle > 170 && _angle < 190) || (_angle > 260 && _angle < 280) || _angle > 350)
        _angle += 30;
}
