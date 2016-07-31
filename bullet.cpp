#include "bullet.h"

void bullet::initBullet(string objFile, int x, int y)
{
    texture.loadFromFile(objFile.c_str());
    sprite.setTexture(texture);
    bounds = sprite.getLocalBounds();
    xPos = x;
    yPos = y;
    sprite.setPosition(xPos, yPos);
    speed = 500;
    elapsedTime = (float)clock.getElapsedTime().asSeconds();
    posRect = sf::FloatRect(xPos, yPos, bounds.width, bounds.height);
    shoot = 0;
    next = 0;
}

void bullet::showBullet(RenderWindow& Window)
{
    Window.draw(sprite);
}

void bullet::updateBulletPos(int up, int down)
{
    elapsedTime = (float)clock.restart().asSeconds();
    moveAmount = elapsedTime * (float)speed;
    if(up)
        yPos -= moveAmount;
    if(down)
        yPos += moveAmount;
    sprite.setPosition(xPos, yPos);
    posRect = sf::FloatRect(xPos, yPos, bounds.width, bounds.height);
    destroyBullet();
}

void bullet::setBulletPos(int x, int y)
{
    xPos = x;
    yPos = y;
    sprite.setPosition(xPos, yPos);
}

void bullet::destroyBullet(void)
{
    //if(yPos <= 0)
    //    exists--;
}
