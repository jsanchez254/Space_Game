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
    int speed = 10;
    float moveDownSpeed = 0.002;
    float y;
    float x;
    bool dieDie = false;
    bool die = true;
    bool boundaryTouch = false;
    GLuint texture_id;

    

    //Default Constructor
    Enemy(): x(0.0f), z(1.0f) {
        y = 1.5f;
        this->movingDown = true;
        this->boundaryTouch = false;
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

                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    }
    
    Enemy(float x, float z): x(x), z(z) {
        y = 1.5f;
        this->movingDown = true;
        this->boundaryTouch = false;
            // glClearColor (0.0, 0.0, 0.0, 0.0);
            // glShadeModel(GL_FLAT);
            // glEnable(GL_DEPTH_TEST);
    
            // texture_id = SOIL_load_OGL_texture (
            //                             "bomb.png",
            //                             SOIL_LOAD_AUTO,
            //                             SOIL_CREATE_NEW_ID,
            //                             SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
            //                             );
    
            // if(0 == texture_id){
            //     std::cout <<"SOIL loading error: " << SOIL_last_result() << std::endl;
            // }

    
            // glEnable(GL_BLEND);
            // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                
            // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                
            // glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

            

    }

    ~Enemy(){
        
    }


    bool getMoveDown()
    {
        return this->movingDown;
    }
   
   void action()
   {
        if (y > -1.5f && die)
        {
            y -= moveDownSpeed;
            glutPostRedisplay();
        }

        else{
            dieDie = true;
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

        glDisable(GL_TEXTURE_2D);
        
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