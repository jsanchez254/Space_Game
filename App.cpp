#include <iostream>
#include "App.h"

using namespace std;

App::App(int argc, char** argv): GlutApp(argc, argv){
    explosion = new AnimatedRect("fireball.bmp", 6, 6, 100, -0.5, 0.5, 0.5, 0.5);
    fastExplosion = new AnimatedRect("fireball.bmp", 6, 6, 10, 0.5, 0.5, 0.5, 0.5);
    background = new TexRect("background.png,", -1.0, 1.0, 2.0, 2.0);
    

}

void App::draw() {
    explosion->draw(0.15);
    fastExplosion->draw(0.15);
    arwing->draw();
    // test->draw();
    if(shoot){
        for(int i = 0; i < arwing->weapon.size(); i++){
            arwing->weapon[i]->draw();
        }
    }
    background->draw(0.0);
}

void App::keyDown(unsigned char key, float x, float y){
    
    if (key == 27){
        exit(0);
    }


    /*ARWING MOVEMENTS*/
    //UP
    if(key == 115){
        arwing->positionManage("UP");
        redraw();
    }
    //RIGHT
    if(key == 99){
        arwing->positionManage("RIGHT");
        redraw();
    }
    //DOWN
    if(key == 120){
        arwing->positionManage("DOWN");
        redraw();
    }
    //LEFT
    if(key == 122){
        arwing->positionManage("LEFT");
        redraw();
    }
    /*-----------*/
    
    if (key == 32){
        arwing->weapon.push_back(new bullets(arwing->positionY1, arwing->positionY2, arwing->positionX1, arwing->positionX2));
        shoot = true;
        for(int i = 0; i < arwing->weapon.size(); i++){
            glutIdleFunc(arwing->weapon[i]->upbullet);
        }

    }



}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    // delete explosion;
    // delete fastExplosion;
    delete background;
}
