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
        if (y > -0.6f)
        {
            y -= 0.001f;
            glutPostRedisplay();
        }

        else{
            stop();
        }

   }

    void draw() const {

        glColor3d(1.0f, 1.0f, 1.0f);

        glBegin(GL_POLYGON);

        glVertex2f(x-0.05f, y);
        glVertex2f(x+0.05f, y);
        glVertex2f(x+0.05f, y-0.2f);
        glVertex2f(x-0.05f, y-0.2f);

        glEnd();
    }
    
};

// float Enemy::y = 1.5f;

#endif