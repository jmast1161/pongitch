#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

class background
{
    protected:
        Texture texture;
        Sprite background;
    public:
        void initBackground(string bgFile);
        void showBackground(RenderWindow& Window);
};
