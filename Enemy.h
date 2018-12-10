#ifndef Enemy_h
#define Enemy_h

#include "GlutApp.h"
#include "Rect.h"
#include "AnimatedRect.h"
#include <math.h>
#include <vector>
#include "Timer.h"

using namespace std;

class Enemy: public Rect, public Timer {  // Use AnimatedRect to include pictures

 
    float z;

    bool movingDown;
    
public:
    float y;
    float x;
    bool die = true;

    // Default Constructor
    Enemy(): x(0.0f), z(1.0f) {
        y = 1.5f;
        this->movingDown = true;
    }
    
    Enemy(float x, float z): x(x), z(z) {
        y = 1.5f;
        this->movingDown = true;
    }

    ~Enemy(){
        
    }


    bool getMoveDown()
    {
        return this->movingDown;
    }
   
   void action()
   {
        if (y > -0.6f && die)
        {
            y -= 0.001f;
            glutPostRedisplay();
        }

        else{
            stop();
        }

   }

    void draw() const {

        if (movingDown && die)
        {
            glColor3d(1.0f, 1.0f, 1.0f);

            glBegin(GL_POLYGON);

            glVertex3f(x-0.05f, y, 1.0f);
            glVertex3f(x+0.05f, y, 1.0f);
            glVertex3f(x+0.05f, y-0.2f, 1.0f);
            glVertex3f(x-0.05f, y-0.2f, 1.0f);

            glEnd();
        }
        else
        {
            glBegin(GL_POLYGON);

            glEnd();
        }
    }

    void reset()
    {
        y = 1.5;
        glutPostRedisplay();
    }
    
};

// float Enemy::y = 1.5f;

#endif