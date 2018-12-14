#ifndef player_h
#define player_h

#include "bullets.h"
#include <SOIL.h>
#include <string>

class player{
    public:
    
        GLuint texture_id;

        bool endGame = true;
        //GAME START
        bool gameStart = true;

        bool shoot = false;
        bool die =true;
        //score of player
        int score = 0;
        vector <bullets*> weapon;
        float positionY1 = -0.6f;
        float positionY2 = -0.8f;
        float positionX1 = -0.1f;
        float positionX2 = 0.1f;

        player(){
            glClearColor (1.0, 1.0, 1.0, 1.0);
            glShadeModel(GL_FLAT);
            glEnable(GL_DEPTH_TEST);
            
            texture_id = SOIL_load_OGL_texture (
                                        "destroyer.png",
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

        //MAKE SURE PLAYER IS WITHIN BOUNDS
        bool checkWithinBox(string action){
            if(action == "UP" && (positionY1 + 0.03) < 1.0f){
                return true;
            }
            else if(action == "RIGHT" && (positionX2 + 0.03) < 1.0f){
               return true;
            }
            else if(action == "DOWN" && (positionY2 - 0.03) > -1.0f){
                return true;
            }
            else if(action == "LEFT" && (positionX1 - 0.03) > -1.0f){
                return true;
            }
            else{
                return false;
            }
        }

        //POSITION
        void positionManage(string type){
            if(type == "UP" && checkWithinBox("UP")){
                if(positionY1 )
                positionY1 += 0.03f;
                positionY2 += 0.03f;
            }
            else if(type == "RIGHT" && checkWithinBox("RIGHT")){
                positionX1 += 0.03f;
                positionX2 += 0.03f;
            }
            else if(type == "DOWN" && checkWithinBox("DOWN")){
                positionY1 -= 0.03f;
                positionY2 -= 0.03f;
            }
            else if(type == "LEFT" && checkWithinBox("LEFT")){
                positionX1 -= 0.03f;
                positionX2 -= 0.03f;
            }
        }

        void draw(){
            if(die){
                glBindTexture( GL_TEXTURE_2D, texture_id );
                glEnable(GL_TEXTURE_2D);
                glBegin(GL_QUADS);
                // glColor3f(1, 1, 0.2);
                // glBegin(GL_POLYGON);
                
                 glTexCoord2f(0, 1);
                glVertex3f(positionX1, positionY1, 0.16);
                 glTexCoord2f(1, 1);
                glVertex3f(positionX2, positionY1, 0.16);
                glTexCoord2f(1, 0);
                glVertex3f(positionX2, positionY2, 0.16);
                 glTexCoord2f(0, 0);
                glVertex3f(positionX1, positionY2, 0.16);
                
                glEnd();

              
                 glColor3f(0.7, 0.5, 0.1);
                glRasterPos3f(0.60f, 0.1f, 0.80f);

                string string2 = to_string(score);
                string score1 = "SCORE: " + string2;


                for(int i = 0; i < score1.length(); i++){
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score1[i]);
                }

                glEnd();
            }

        }

};

#endif