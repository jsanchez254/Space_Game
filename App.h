#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "Rect.h"
#include <iostream>
#include "bullets.h"

using namespace std;

class player{
    public:
        //position
        float x = 0.0f;
        float y = 0.0f;
        bool shoot = false;

        player(){
            cout<<"default me"<<endl;
        }

        bool withinFrame(string action){
            if((-0.1f + x) > -1.0f && ((0.1f + x + 0.03f) < 1.0f) && ((-0.6f + y) > -1.0f) && ((0.6f + y) < 1.0f)) {
                return true;
            }
            else{
                return false;
            } 
        }

        //POSITION
        void positionManage(string type){
            if(type == "UP"){
                y += 0.03f;
            }
            else if(type == "RIGHT"){
                x += 0.03f;
            }
            else if(type == "DOWN"){
                y -= 0.03f;
            }
            else if(type == "LEFT"){
                x -= 0.03f;
            }
        }

        void draw(){
            glColor3f(1, 1, 0.2);
            glBegin(GL_POLYGON);
            
            glVertex2f(-0.1f + x, -0.6f + y);
            glVertex2f(0.1f + x, -0.6f+ y);
            glVertex2f(0.1f + x, -0.8f+ y);
            glVertex2f(-0.1f+ x, -0.8f + y);

            cout<<"BOUNDS: "<<0.1f + x<<endl;
            
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
    player * arwing = new player();
    bullets * test = new bullets();
    
    

public:
    App(int argc, char** argv);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);

    ~App();
    
};



#endif
