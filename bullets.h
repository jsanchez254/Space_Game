#ifndef bullets_h
#define bullets_h

#include "Timer.h"

using namespace std;

class bullets: public Timer{
    public:
        float y = 0.0f;
        float positionY1;
        float positionY2;
        float positionX1;
        float positionX2;

        int interval = 1;
        bool shooting = true;


    public: 
        bullets(float positionY1x ,  float positionY2x , float positionX1x , float positionX2x ){
            y = 0.0f;
            positionY1 = positionY1x -0.1f;
            positionY2 = positionY2x;
            positionX1 = positionX1x + 0.075f;
            positionX2 = positionX2x - 0.075f;

        }

        bullets(){

        } 

    void action(){
        if(positionY1 < 2.5f && shooting){
            positionY1 += 0.01f;
            positionY2 += 0.01f;
            glutPostRedisplay();
        }
        else{
            stop();
        }
    }
    

    void draw(){
        if(shooting){
            glColor3f(1, 0.6, 0.2);
            
            glBegin(GL_POLYGON);
            glVertex3f(positionX1 , positionY1 + y, 0.15);
            glVertex3f(positionX2, positionY1 + y, 0.15);
            glVertex3f(positionX2, positionY2 + y, 0.15);
            glVertex3f(positionX1 , positionY2 + y, 0.15);
            
            glEnd();
        }
        else{
            glBegin(GL_POLYGON);
          
            
            glEnd();
        }
    }
};

// float bullets::y = 0.0f;
// float bullets::positionY1;
// float bullets::positionY2;
// float bullets::positionX1;
// float bullets::positionX2;

#endif