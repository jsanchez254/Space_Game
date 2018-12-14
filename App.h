#ifndef App_h
#define App_h

#include <iostream>
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
        //indicates game is over
    gameScene(){
        shipList.push_back(new Enemy(-0.9f, 1.0f));
        shipList.push_back(new Enemy(-0.7f, 1.0f));
        shipList.push_back(new Enemy(-0.5f, 1.0f));
        shipList.push_back(new Enemy(-0.3f, 1.0f));
        shipList.push_back(new Enemy(-0.1f, 1.0f));
        shipList.push_back(new Enemy(0.1f, 1.0f));
        shipList.push_back(new Enemy(0.3f, 1.0f));
        shipList.push_back(new Enemy(0.5f, 1.0f));
        shipList.push_back(new Enemy(0.7f, 1.0f));
        shipList.push_back(new Enemy(0.9f, 1.0f));
        
    }

    void action(){
        if(arwing->endGame){
            check->ifHit(arwing->weapon, shipList, arwing);
        }
        else{
            stop();
             cout<<"TRUE MY FRIEND"<<endl;
            cout<<"BULLET COUNT: "<<arwing->weapon.size()<<endl;
        }
    }

    //DISPLAY GAME OVER ADD MORE TO IT
    void draw(){
            glColor3f(1, 0.0, 0.0);
            
            glBegin(GL_POLYGON);
            glVertex3f(0.2, 0.5, 0.15);
            glVertex3f(0.5, 0.5, 0.15);
            glVertex3f(0.5, -0.5, 0.15);
            glVertex3f(0.2, -0.5, 0.15);
            
            glEnd();
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
