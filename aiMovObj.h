#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

class aiMovObj
{
    public:
        FloatRect posRect;
    protected:
        sf::Clock clock;
        Texture texture;
        Sprite sprite;
        int speed, xPos, yPos;
        float elapsedTime, moveAmount;
        FloatRect bounds;
    public:
        void initAIMovObj(string objFile, int x, int y);
        void showAIMovObj(RenderWindow& Window);
        void updateAIMovObjPos(void);
        void ai(FloatRect objRect);
};
