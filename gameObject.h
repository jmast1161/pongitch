#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

class gameObject
{
    protected:
        Texture texture;
        Sprite sprite;
        int xPos, yPos;
    public:
        void initGameObject(string objFile, int x, int y);
        void showGameObject(RenderWindow& Window);
};
