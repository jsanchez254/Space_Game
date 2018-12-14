#include "Timer.h"
#include <vector>
#include "bullets.h"
#include "Enemy.h"
#include "Player.h"

using namespace std;

class checkHit{
    public: 
    checkHit(){}    // Default Constructor

    void ifHit(vector<bullets*> &weapons, vector<Enemy*> &enemies, player * arwing){
        if(weapons.empty()){    // Safety to avoid segmentation fault
            //DO NOTHING
            cout<<arwing->positionY1<<endl;
        }

        else if (enemies.size() != 0){

        arwing->gameStart = false;
        int size = weapons.size() - 1;
            vector<Enemy*>::iterator it;
            vector<bullets*>::iterator it2;

            for(it = enemies.begin(); it < enemies.end(); it++){  // The upper bound won't die even with the lower bound killed off; find a more efficient way
                for(it2 = weapons.begin(); it2 < weapons.end(); it2++){
                     if((*it)->dieDie){
                         arwing->die = false;
                        arwing->endGame = false;
                    }
                    
                    if((withinBounds((*it2)->positionY1, (*it2)->positionX1, 
                    (*it2)->positionX2, (*it)->x-0.05f, (*it)->x+0.05f, (*it)->y-0.02f ))){
                            (*it2)->shooting = false;
                            // weapons.pop_back(); // Delete the first bullet on the back
                            (*it)->die = false;
                            enemies.erase(it);
                            weapons.erase(it2);   
                            cout<<"TRUE MY FRIEND"<<endl;
                            arwing->createEnemy = true;
                            arwing->score += 1;
                    }
                    
                }
            }

            for(it = enemies.begin(); it < enemies.end(); it++){
                if(checkIfPlayerDies(arwing->positionY1, arwing->positionY2, arwing->positionX1, arwing->positionX2,
                    (*it)->x-0.05f, (*it)->x+0.05f, (*it)->y-0.02f)){
                        arwing->die = false;
                        arwing->endGame = false;
                }       
            }
        }

        else{
            cout<<"GAME OVER"<<endl;
            arwing->endGame = false;
        }
    }

    bool withinBounds(float y1, float x1, float  x2, float xx1, float  xx2, float yy1){
        // cout<<xx1<<" "<<xx2<<" "<< yy1<<endl;
        //needs fix on dying
        if((y1 >= yy1) && (x1 >= xx1) && (x2 <= xx2)){
            return true;
        }

        else{
            return false;
        }

    }

    bool checkIfPlayerDies(float Y1, float Y2, float X1, float X2, 
                        float enemyX1, float enemyX2, float enemyY2){
        // cout<<"PLAYER Y1: "<< Y1 << "   ENEMY Y2: "<< enemyY2<<endl;
        cout<<Y1<<" "<<enemyY2<<endl;
        //add more logic
        if((Y1 >= (enemyY2- 0.18)) && (X1 >= (enemyX1 - 0.18)) && (X2 <= (enemyX2 + 0.18))){
            cout<<"HELLO THERE"<<endl;
            return true;
        }

        else{
            // cout<<"YES I WAS CALLED"<<endl;
            return false;
        }
    }

};