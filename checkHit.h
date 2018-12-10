#include "Timer.h"
#include <vector>
#include "bullets.h"
#include "Enemy.h"

using namespace std;

class checkHit{
    public: 
    checkHit(){}    // Default Constructor

    void ifHit(vector<bullets*> weapons, vector<Enemy*> enemies ){
        if(weapons.empty()){    // Safety to avoid segmentation fault
            cout<<"IT IS EMPTY"<<endl;
        }
        else{
        int size = weapons.size() - 1;
        // cout<<weapons[size]->positionY1<<endl;
            // int ii = 0;
            // while(ii < 5){
            //     cout<<"hello"<<endl;
            //     ii++;
            // }
            // int i = 0;
            // int j = 0;
            // for(i = 0; i < enemies.size(); i++){
            //     for(j = 0; j < weapons.size(); j++){
            //         if(withinBounds(weapons[j]->positionY1, weapons[j]->positionX1, 
            //         weapons[j]->positionX2, enemies[i]->x-0.05f, enemies[i]->x+0.05f, enemies[i]->y-0.02f )){
            //                 weapons[j]->shooting = false;
            //                 cout<<"TRUEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<endl;
            //                 weapons.pop_back(); // Delete the first bullet on the back

            //                 // Results in a segmentation fault: we need to resolve this issue!
            //                 // enemies.erase(enemies.begin()+i);
            //                 delete enemies[i];
                          
            //         }

            vector<Enemy*>::iterator it;
            vector<bullets*>::iterator it2;
            for(it = enemies.begin(); it < enemies.end(); it++){
                for(it2 = weapons.begin(); it2 < weapons.end(); it2++){
                    if(withinBounds((*it2)->positionY1, (*it2)->positionX1, 
                    (*it2)->positionX2, (*it)->x-0.05f, (*it)->x+0.05f, (*it)->y-0.02f )){
                            (*it2)->shooting = false;
                            cout<<"TRUEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<endl;
                            weapons.pop_back(); // Delete the first bullet on the back

                            // Results in a segmentation fault: we need to resolve this issue!
                            // enemies.erase(enemies.begin()+i);
                            (*it)->die = false;
                            // delete *it;
                          
                    }
                    cout<<"hello1"<<endl;
                }
            }
            
         
        }

    }

    bool withinBounds(float y1, float x1, float  x2, float xx1, float  xx2, float yy1){
        cout<<xx1<<" "<<xx2<<" "<< yy1<<endl;
        if(y1 >= yy1 && x1 >= xx1 && x2 <= xx2){
            return true;
        }

        else{
            return false;
        }

    }

};