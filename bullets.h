#ifndef bullets_h
#define bullets_h

#include "Timer.h"
#include <SOIL.h>

using namespace std;

class bullets: public Timer{
    public:
        GLuint texture_id;
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
            glClearColor (0.0, 0.0, 0.0, 0.0);
                glShadeModel(GL_FLAT);
                glEnable(GL_DEPTH_TEST);
                
                texture_id = SOIL_load_OGL_texture (
                                            "bullet.png",
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
            // glColor3f(1, 0.6, 0.2);
            
            // glBegin(GL_POLYGON);
            // glVertex3f(positionX1 , positionY1 + y, 0.15);
            // glVertex3f(positionX2, positionY1 + y, 0.15);
            // glVertex3f(positionX2, positionY2 + y, 0.15);
            // glVertex3f(positionX1 , positionY2 + y, 0.15);
            
            // glEnd();


            glBindTexture( GL_TEXTURE_2D, texture_id );
            glEnable(GL_TEXTURE_2D);
            glBegin(GL_QUADS);
            
            
                glTexCoord2f(0, 1);
            glVertex3f(positionX1 , positionY1 + y, 0.15);
                glTexCoord2f(1, 1);
            glVertex3f(positionX2, positionY1 + y, 0.15);
            glTexCoord2f(1, 0);
            glVertex3f(positionX2, positionY2 + y, 0.15);
                glTexCoord2f(0, 0);
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