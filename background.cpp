#include "background.h"

void background::initBackground(string bgFile)
{
    texture.loadFromFile(bgFile.c_str());
    background.setTexture(texture);
}

void background::showBackground(RenderWindow& Window)
{
    Window.draw(background);
}
