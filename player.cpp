#include "player.h"

void player::initPlayer(string objFile, int x, int y)
{
    texture.loadFromFile(objFile.c_str());
    sprite.setTexture(texture);
    bounds = sprite.getLocalBounds();
    xPos = x;
    yPos = y;
    sprite.setPosition(xPos, yPos);
    speed = 400;
    elapsedTime = (float) clock.getElapsedTime().asSeconds();
    posRect = sf::FloatRect(xPos, yPos, bounds.width, bounds.height);
}

void player::showPlayer(RenderWindow& Window)
{
    Window.draw(sprite);
}

void player::updatePlayerPos(void)
{
    elapsedTime = (float)clock.restart().asSeconds();
    getPlayerInput();
    posRect = sf::FloatRect(xPos, yPos, bounds.width, bounds.height);
}

void player::getPlayerInput(void)
{
    if(Keyboard::isKeyPressed(Keyboard::Left))
        movePlayer(1, 0);
    else if(Keyboard::isKeyPressed(Keyboard::Right))
        movePlayer(0, 1);
}

void player::movePlayer(int left, int right)
{

    if(left && xPos >= 0)
    {
        moveAmount = elapsedTime * (float)speed;
        xPos -= moveAmount;
        sprite.setPosition(xPos, yPos);
    }
    else if(right && xPos + bounds.width <= 1024)
    {
        moveAmount = elapsedTime * (float)speed;
        xPos += moveAmount;
        sprite.setPosition(xPos, yPos);
    }

}

int player::shoot(void)
{
    if(Keyboard::isKeyPressed(Keyboard::Space))
        return 1;
    return 0;
}
