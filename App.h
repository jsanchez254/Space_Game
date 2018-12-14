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
#include <string>
#include <stdlib.h>

using namespace std;

//whole game scene and logic of game
class gameScene: public Timer{
    public:
        vector<Enemy*> shipList;
        player* arwing = new player();
        checkHit* check = new checkHit();
        int speed = 2;
        float moveDownSpeed = 0.001;
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
            if(arwing->createEnemy){
                callDownEnemy();
                arwing->createEnemy = false;
            }
        }
        else{
            stop();
             cout<<"TRUE MY FRIEND"<<endl;
            cout<<"BULLET COUNT: "<<arwing->weapon.size()<<endl;
        }
    }

    float RandomX()
    {
        /*
        float random = ((float)rand()) / (float)RAND_MAX;
        float diff = b - a;
        float result = random * diff;

        return a + result;
        */

        
        float x;
        int i = rand() % 10;
        
        if (i == 0)
        {
            x = -0.9;
        }
        else if (i == 1)
        {
            x = -0.7;
        }
        else if (i == 2)
        {
            x = -0.5;
        }
        else if (i == 3)
        {
            x = -0.3;
        }
        else if (i == 4)
        {
            x = -0.1;
        }
        else if (i == 5)
        {
            x = 0.1;
        }
        else if (i == 6)
        {
            x = 0.3;
        }
        else if (i == 7)
        {
            x = 0.5;
        }
        else if (i == 8)
        {
            x = 0.7;
        }
        else
        {
            x = 0.9;
        }

        return x;
    }

    void callDownEnemy()
   {
        // float x = RandomX();   
        float x = RandomX();
        cout<<"I WAS CALLED HERE"<<endl;
        //shipList.push_back(new Enemy());
        shipList.push_back(new Enemy(x, 1.0f));
        shipList[shipList.size()-1]->speed += speed;
        shipList[shipList.size()-1]-> moveDownSpeed += moveDownSpeed;
        shipList[shipList.size()-1]->setRate(shipList[shipList.size()-1]->speed);  // Set the speed of an enemy ship
        shipList[shipList.size()-1]->start();
        if(speed >= 0.5){
            speed -= 0.5;
        }
        if(moveDownSpeed <= 0.5){
            moveDownSpeed+=0.00002;
        }
   }

    //DISPLAY GAME OVER ADD MORE TO IT
    void draw(){
            // glColor3f(1, 0.0, 0.0);
            
            // glBegin(GL_POLYGON);
            // glVertex3f(0.2, 0.5, 0.15);
            // glVertex3f(0.5, 0.5, 0.15);
            // glVertex3f(0.5, -0.5, 0.15);
            // glVertex3f(0.2, -0.5, 0.15);
            
            // glEnd();
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            glRasterPos3f(-0.85f, 0.2f, 0.30f);
            glColor3f(1.0f, 0.0f, 0.0f);
            string hello  ="GAME OVER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            // string num  = to_string(arwing->score);
            // hello += num;
            for(int i = 0; i < hello.length(); i++){
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, hello[i]);
            }
    }

};


class App: public GlutApp {
    //position of arwing
    public:
    void Menu();
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

    void keyUp(unsigned char key, float x, float y);

    void idle();

    ~App();
    
};



#endif
