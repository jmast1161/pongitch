#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

class player
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
        void initPlayer(string objFile, int x, int y);
        void showPlayer(RenderWindow& Window);
        void updatePlayerPos(void);
        void getPlayerInput(void);
        void movePlayer(int left, int right);
        int shoot(void);
};
