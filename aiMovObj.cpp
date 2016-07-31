#include "aiMovObj.h"

void aiMovObj::initAIMovObj(string objFile, int x, int y)
{
    texture.loadFromFile(objFile.c_str());
    sprite.setTexture(texture);
    bounds = sprite.getLocalBounds();
    xPos = x;
    yPos = y;
    sprite.setPosition(xPos, yPos);
    speed = 200;
    elapsedTime = (float) clock.getElapsedTime().asSeconds();
    posRect = sf::FloatRect(xPos, yPos, bounds.width, bounds.height);
}

void aiMovObj::showAIMovObj(RenderWindow& Window)
{
    Window.draw(sprite);
}

void aiMovObj::updateAIMovObjPos(void)
{
    elapsedTime = (float)clock.restart().asSeconds();
    posRect = sf::FloatRect(xPos, yPos, bounds.width, bounds.height);
    sprite.setPosition(xPos, yPos);
}

void aiMovObj::ai(FloatRect objRect)
{
    if(objRect.left + (int)objRect.width/2.0f < posRect.left + (int)posRect.width/2.0f && xPos >= 0)
    {
        moveAmount = elapsedTime * (float)speed;
        xPos -= moveAmount;
        sprite.setPosition(xPos, yPos);
    }
    else if(objRect.left + (int)objRect.width/2.0f > posRect.left + (int)posRect.width/(2.0f) && xPos + posRect.width <= 1024)
    {
        moveAmount = elapsedTime * (float)speed;
        xPos += moveAmount;
        sprite.setPosition(xPos, yPos);
    }
}
