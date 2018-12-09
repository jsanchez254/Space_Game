#include <iostream>
#include "App.h"

using namespace std;

App::App(int argc, char** argv): GlutApp(argc, argv){
    //explosion = new AnimatedRect("fireball.bmp", 6, 6, 100, -0.5, 0.5, 0.5, 0.5);
    //fastExplosion = new AnimatedRect("fireball.bmp", 6, 6, 10, 0.5, 0.5, 0.5, 0.5);
    background = new TexRect("background.png", -1.0, 1.0, 2.0, 2.0);
     shipList.push_back(new Enemy(0.5f, 1.0f));
    shipList.push_back(new Enemy(0.0f, 1.0f));
    shipList.push_back(new Enemy(-0.5f, 1.0f));

    for (int i = 0; i < shipList.size(); i++)
    {
        if (shipList[i]->getMoveDown())
        {
            glutIdleFunc(shipList[i]->moveDown);
        }
    }
}

void App::draw() {
    //explosion->draw(0.15);
    //fastExplosion->draw(0.15);
    for (int i = 0; i < shipList.size(); i++)
    {
        shipList[i]->draw();
    }
    arwing->draw();
    background->draw(0.0);
    // test->draw();
    if(shoot){
        for(int i = 0; i < arwing->weapon.size(); i++){
            arwing->weapon[i]->draw();
        }
    }
}

void App::keyDown(unsigned char key, float x, float y){
    
    if (key == 27){
        exit(0);
    }

     if (key == 115)
    {
        for (int i = 0; i < shipList.size(); i++)
        {
            glutIdleFunc(shipList[i]->moveDown);
        }
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
    
    // Note: The enemies stop as soon as the ship fires; we need to use multithreading to resolve this issue
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
    for (int i = 0; i < shipList.size(); i++)
    {
        delete shipList[i];
    }
    delete background;
}
