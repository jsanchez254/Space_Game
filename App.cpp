#include <iostream>
#include "App.h"

using namespace std;

App::App(int argc, char** argv): GlutApp(argc, argv){
    explosion = new AnimatedRect("fireball.bmp", 6, 6, 100, -0.5, 0.5, 0.5, 0.5);
    fastExplosion = new AnimatedRect("fireball.bmp", 6, 6, 10, 0.5, 0.5, 0.5, 0.5);
    

}

void App::draw() {
    explosion->draw(0.15);
    fastExplosion->draw(0.15);
    arwing->draw();
    test->draw();
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
        // fastExplosion->playOnce();
        // explosion->playOnce();

        // arwing->shoot = true;
        // int i = 0;
        // while(i < 50){
        //     test->upbullet();
        //     redraw();
        //     i++;
        //     cout<<"okay"<<endl;
        // }
        // y= 0.0f;
        glutIdleFunc(NULL);
        glutPostRedisplay();
    }



}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    // delete explosion;
    // delete fastExplosion;
}
