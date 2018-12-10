#include "bullets.h"

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
            glColor3f(1, 1, 0.2);
            glBegin(GL_POLYGON);
            
            glVertex3f(positionX1, positionY1, 0.16);
            glVertex3f(positionX2, positionY1, 0.16);
            glVertex3f(positionX2, positionY2, 0.16);
            glVertex3f(positionX1, positionY2, 0.16);
            
            glEnd();

        }

};