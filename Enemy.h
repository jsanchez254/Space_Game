#ifndef Enemy_h
#define Enemy_h

#include "GlutApp.h"
#include "Rect.h"
#include "AnimatedRect.h"
#include <math.h>
#include <vector>
#include "Timer.h"

#include <SOIL.h>


using namespace std;

class Enemy: public Rect, public Timer {  // Use AnimatedRect to include pictures

    float z;

    bool movingDown;
    
public:
    float y;
    float x;
    bool die = true;
    GLuint texture_id;

    // Default Constructor
    Enemy(): x(0.0f), z(1.0f) {
        y = 1.5f;
        this->movingDown = true;
    }
    
    Enemy(float x, float z): x(x), z(z) {
        y = 1.5f;
        this->movingDown = true;
            glClearColor (0.0, 0.0, 0.0, 0.0);
                glShadeModel(GL_FLAT);
                glEnable(GL_DEPTH_TEST);
                
                texture_id = SOIL_load_OGL_texture (
                                            "alien1.png",
                                            SOIL_LOAD_AUTO,
                                            SOIL_CREATE_NEW_ID,
                                            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                            );
                
                if(0 == texture_id){
                    std::cout <<"SOIL loading error: " << SOIL_last_result() << std::endl;
        
                }

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

              glBindTexture( GL_TEXTURE_2D, texture_id );
                glEnable(GL_TEXTURE_2D);
                glBegin(GL_QUADS);
            // glColor3d(1.0f, 1.0f, 1.0f);

            glTexCoord2f(0, 1);
            glVertex3f(x-0.05f, y, 1.0f);
            glTexCoord2f(1, 1);
            glVertex3f(x+0.05f, y, 1.0f);
            glTexCoord2f(1, 0);
            glVertex3f(x+0.05f, y-0.2f, 1.0f);
            glTexCoord2f(0, 0);
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