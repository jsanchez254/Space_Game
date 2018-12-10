#include <iostream>
#include <thread>
#include "App.h"

using namespace std;

App::App(int argc, char** argv): GlutApp(argc, argv){
    //explosion = new AnimatedRect("fireball.bmp", 6, 6, 100, -0.5, 0.5, 0.5, 0.5);
    //fastExplosion = new AnimatedRect("fireball.bmp", 6, 6, 10, 0.5, 0.5, 0.5, 0.5);
    background = new TexRect("background.png", -1.0, 1.0, 2.0, 2.0);
    
    game->setRate(0.1);
    game->start();

    for (int i = 0; i < game->shipList.size(); i++)
    {
        game->shipList[i]->setRate(10);
        game->shipList[i]->start();
    }
}

void App::draw() {
    // explosion->draw(0.15);
    // fastExplosion->draw(0.15);
    for (int i = 0; i < game->shipList.size(); i++)
    {
        game->shipList[i]->draw();
    }
    game->arwing->draw();
    background->draw(0.0);
    if(shoot){
        for(int i = 0; i < game->arwing->weapon.size(); i++){
            game->arwing->weapon[i]->draw();
        }
    }
}

void App::keyDown(unsigned char key, float x, float y){
    
    if (key == 27){
        exit(0);
    }

    /*ARWING MOVEMENTS*/
    //UP
    if(key == 115){
        game->arwing->positionManage("UP");
        redraw();
    }
    //RIGHT
    if(key == 99){
        game->arwing->positionManage("RIGHT");
        redraw();
    }
    //DOWN
    if(key == 120){
        game->arwing->positionManage("DOWN");
        redraw();
    }
    //LEFT
    if(key == 122){
        game->arwing->positionManage("LEFT");
        redraw();
    }
    /*-----------*/
    
    // Note: The enemies stop as soon as the ship fires; we need to use multithreading to resolve this issue
    if (key == 32){
        shoot = true;
        // for(int i = 0; i < game->arwing->weapon.size(); i++){
        //     glutIdleFunc(game->arwing->weapon[i]->upbullet);   
        // }
        game->arwing->weapon.push_back(new bullets(game->arwing->positionY1, game->arwing->positionY2, game->arwing->positionX1, game->arwing->positionX2));
        int last = game->arwing->weapon.size() - 1;
        game->arwing->weapon[last]->setRate(1);
        game->arwing->weapon[last]->start();

    }



}

App::~App(){
    std::cout << "Exiting..." << std::endl;
    // delete explosion;
    // delete fastExplosion;
    // for (int i = 0; i < game->shipList.size(); i++)
    // {
    //     delete game->shipList[i];
    // }

    // for(int i = 0; i < game->arwing->weapon.size(); i++){
    //     delete game->arwing->weapon[i];
    // }


    delete background;
}
