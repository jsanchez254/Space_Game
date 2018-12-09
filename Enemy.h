#ifndef Enemy_h
#define Enemy_h

#include "GlutApp.h"
#include "Rect.h"
#include "AnimatedRect.h"
#include <math.h>
#include <vector>

using namespace std;

class Enemy: public Rect {  // Use AnimatedRect to include pictures

    float x;
    float z;

    bool movingDown;
    
public:
    static float y;

    // Default Constructor
    Enemy(): x(0.0f), z(1.0f) {
        y = 1.5f;
        this->movingDown = true;
    }
    
    Enemy(float x, float z): x(x), z(z) {
        y = 1.5f;
        this->movingDown = true;
    }

    bool getMoveDown()
    {
        return this->movingDown;
    }
   
   static void moveDown()
   {
        if (y > -1.1f)
        {
            y -= 0.001f;
        }

        glutPostRedisplay();
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

float Enemy::y = 1.5f;

#endif