#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "Rect.h"
#include <iostream>
#include "bullets.h"
#include <vector>

using namespace std;

class player{
    public:
    
        bool shoot = false;
        vector <bullets*> weapon;
        float positionY1 = -0.6f;
        float positionY2 = -0.8f;
        float positionX1 = -0.1f;
        float positionX2 = 0.1f;

        player(){
            cout<<"default me"<<endl;
        }

        //POSITION
        void positionManage(string type){
            if(type == "UP"){
                positionY1 += 0.03f;
                positionY2 += 0.03f;
            }
            else if(type == "RIGHT"){
                positionX1 += 0.03f;
                positionX2 += 0.03f;
            }
            else if(type == "DOWN"){
                positionY1 -= 0.03f;
                positionY2 -= 0.03f;
            }
            else if(type == "LEFT"){
                positionX1 -= 0.03f;
                positionX2 -= 0.03f;
            }
        }

        void draw(){
            glColor3f(1, 1, 0.2);
            glBegin(GL_POLYGON);
            
            glVertex2f(positionX1, positionY1);
            glVertex2f(positionX2, positionY1);
            glVertex2f(positionX2, positionY2);
            glVertex2f(positionX1, positionY2);
            
            glEnd();

        }

};


class App: public GlutApp {
    //position of arwing
    public:

    float y = 0.0f;
    AnimatedRect* explosion;
    AnimatedRect* fastExplosion;
    TexRect* background;
    bullets *test = new bullets(); 
    player * arwing = new player();
    
public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);

    ~App();
    
};



#endif
