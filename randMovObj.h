#include <SFML/Graphics.hpp>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
using namespace sf;
using namespace std;

class randMovObj
{
    public:
        FloatRect posRect;
    protected:
        sf::Clock clock;
        Texture texture;
        Sprite sprite;
        int speed, xPos, yPos;
        float _angle, elapsedTime, moveAmount;
        FloatRect bounds;
        FloatRect leftRect, rightRect;
    public:
        void initRandMovObj(string objFile, int x, int y);
        void showRandMovObj(RenderWindow& Window);
        void updateRMOPos(void);
        void detectScreenCollision(void);
        void detectObjCollision(FloatRect objRect);
        float newXPos(float angle);
        float newYPos(float angle);
        void resetPos(void);
};
