#include "Timer.h"
#include <vector>
#include "bullets.h"
#include "Enemy.h"

using namespace std;

class checkHit{
    public: 
    checkHit(){}

    void ifHit(vector<bullets*> weapons, vector<Enemy*> enemies ){
        if(weapons.empty()){
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
            int i = 0;
            int j = 0;
            for(i = 0; i < enemies.size(); i++){
                for(j = 0; j < weapons.size(); j++){
                    if(withinBounds(weapons[j]->positionY1, weapons[j]->positionX1, 
                    weapons[j]->positionX2, enemies[i]->x-0.05f, enemies[i]->x+0.05f, enemies[i]->y-0.02f )){
                            weapons[j]->shooting = false;
                            cout<<"TRUEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<endl;
                            weapons.pop_back();
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