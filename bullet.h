#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

class bullet
{
    public:
        FloatRect posRect;
        int shoot, next;
    protected:
        sf::Clock clock;
        Texture texture;
        Sprite sprite;
        int speed, xPos, yPos;
        float elapsedTime, moveAmount;
        FloatRect bounds;
    public:
        void initBullet(string objFile, int x, int y);
        void showBullet(RenderWindow& Window);
        void updateBulletPos(int up, int down);
        void setBulletPos(int x, int y);
        void destroyBullet(void);
};
