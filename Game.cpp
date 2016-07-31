#include "Game.h"

void Game::Start(void)
{
    VideoMode VMode(windowWidth, windowHeight, 32);
    RenderWindow Window(VMode, "Pongitch");
    Window.setFramerateLimit(60);
    Window.setPosition(Vector2i(300,40));

    gameObject bg;
    bg.initGameObject("Images/black.png", 0, 0);

    randMovObj ball;
    ball.initRandMovObj("Images/Ball.png", windowWidth/2, windowHeight/2);

    player p1;
    p1.initPlayer("Images/Player.png", 300, 600);

    aiMovObj aiPlayer;
    aiPlayer.initAIMovObj("Images/Player.png", 300, 100);

    //player bullets
    int bulletCount = 10;
    bullet b[bulletCount];
    bullet* bPtr;
    for(int i = 0; i < bulletCount; i++)
        b[i].initBullet("Images/bullet.png", 50, 50);
    bPtr = b;

    //ai bullets
    int bulletCountAI = 5;
    bullet bAI[bulletCountAI];
    bullet* bPtrAI;
    for(int i = 0; i < bulletCountAI; i++)
        bAI[i].initBullet("Images/bulletAI.png", 50, 100);
    bPtrAI = bAI;

    Event event;
    while (Window.isOpen())
    {
        while (Window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    Window.close();
                    break;
                default:
                    break;
            }
        }

        ball.detectObjCollision(p1.posRect);
        aiPlayer.ai(ball.posRect);
        ball.detectObjCollision(aiPlayer.posRect);
        ball.updateRMOPos();
        p1.updatePlayerPos();
        aiPlayer.updateAIMovObjPos();
        for(int i = 0; i < bulletCount; i++)
            b[i].updateBulletPos(1,0);
        for(int i = 0; i < bulletCountAI; i++)
            bAI[i].updateBulletPos(0,1);

        if(p1.shoot() && !bPtr->shoot && !bPtr->next)
        {
            bPtr->shoot = 1;
            bPtr->setBulletPos(p1.posRect.left + (int)p1.posRect.width/2.0f,
                           p1.posRect.top - (int)p1.posRect.height/2.0f);
        }
        else if(bPtr->shoot && p1.shoot())
            bPtr->next = 1;
        else if(bPtr->next && !p1.shoot())
        {
            bPtr->next = 0;
            bPtr->shoot = 0;
            bPtr++;
            if(bPtr >= b + bulletCount)
                bPtr = b;
        }

        if((p1.posRect.left + (int)p1.posRect.width/2.0f > aiPlayer.posRect.left &&
            p1.posRect.left + (int)p1.posRect.width/2.0f < aiPlayer.posRect.left + aiPlayer.posRect.width) &&
            !bPtrAI->shoot && !bPtrAI->next)
        {
            bPtrAI->shoot = 1;
            bPtrAI->setBulletPos(aiPlayer.posRect.left + (int)aiPlayer.posRect.width/2.0f,
                           aiPlayer.posRect.top + (int)aiPlayer.posRect.height/2.0f);
        }
        else if(bPtrAI->shoot && bPtrAI->posRect.top >= windowHeight/2)
        {
            bPtrAI->shoot = 0;
            bPtrAI++;
            if(bPtrAI >= bAI + bulletCountAI)
                bPtrAI = bAI;
        }

        bg.showGameObject(Window);
        for(int i = 0; i < bulletCount; i++)
            b[i].showBullet(Window);
        for(int i = 0; i < bulletCountAI; i++)
            bAI[i].showBullet(Window);
        ball.showRandMovObj(Window);
        p1.showPlayer(Window);
        aiPlayer.showAIMovObj(Window);


        Window.display();
    }
}
