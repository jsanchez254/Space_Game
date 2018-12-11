#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "Rect.h"
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "player.h"
#include "checkHit.h"

using namespace std;

//whole game scene and logic of game
class gameScene: public Timer{
    public:
        vector<Enemy*> shipList;
        player* arwing = new player();
        checkHit* check = new checkHit();
    gameScene(){
        // shipList.push_back(new Enemy(-0.9f, 1.0f));
        // shipList.push_back(new Enemy(-0.8f, 1.0f));
        shipList.push_back(new Enemy(-0.7f, 1.0f));
        // shipList.push_back(new Enemy(-0.6f, 1.0f));
        shipList.push_back(new Enemy(-0.5f, 1.0f));
        // shipList.push_back(new Enemy(-0.4f, 1.0f));
        shipList.push_back(new Enemy(-0.3f, 1.0f));
        // shipList.push_back(new Enemy(-0.2f, 1.0f));
        shipList.push_back(new Enemy(-0.1f, 1.0f));
        shipList.push_back(new Enemy(0.0f, 1.0f));
        shipList.push_back(new Enemy(0.1f, 1.0f));
        shipList.push_back(new Enemy(0.3f, 1.0f));
        shipList.push_back(new Enemy(0.5f, 1.0f));
        // shipList.push_back(new Enemy(0.6f, 1.0f));
        shipList.push_back(new Enemy(0.7f, 1.0f));
        // shipList.push_back(new Enemy(0.8f, 1.0f));
        // shipList.push_back(new Enemy(0.9f, 1.0f));
        
    }

    void action(){
        check->ifHit(arwing->weapon, shipList);
    }

};


class App: public GlutApp {
    //position of arwing
    public:
    bool shoot = false;
    gameScene * game = new gameScene();
    float y = 0.0f;
    AnimatedRect* explosion;
    AnimatedRect* fastExplosion;
    TexRect* background;
    // Timer * bullet = new Timer();
    
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);

    ~App();
    
};



#endif
