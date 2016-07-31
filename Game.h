#pragma once
#define windowWidth 1024
#define windowHeight 768
#include <iostream>
//#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "background.h"
#include "randMovObj.h"
#include "player.h"
#include "aiMovObj.h"
#include "bullet.h"
#include "gameObject.h"

using namespace std;
using namespace sf;

class Game
{
    public:
        static void Start(void);
};
