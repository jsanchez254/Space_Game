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
        game->shipList[i]->setRate(10); // Set the speed of an enemy ship
        game->shipList[i]->start();
    }
}

void App::Menu()
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to (not) black
    glClearColor(1.0, 1.0, 1.0, 0.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    //this loads the menu, with text
    glRasterPos2f(-0.85f, 0.1f);
    glColor3f(1.0f, 0.0f, 0.0f);
    string message1 = "PewPew";
    string message4 = "START:";
    
    //display the message on the menu
    glRasterPos2f(-0.5f, 0.0f);
    for(int i = 0; i < message1.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message1[i]);
    
    glRasterPos2f(-0.5f, -0.1f);
    for(int i = 0; i < message4.length(); i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, message4[i]);
    
    glFlush();
    glutSwapBuffers();
}

void App::draw() {
    // explosion->draw(0.15);
    // fastExplosion->draw(0.15);
    if(game->arwing->endGame && !game->arwing->gameStart){
        for (int i = 0; i < game->shipList.size(); i++)
        {
            game->shipList[i]->draw();
        }
    }
    if(!game->arwing->gameStart){
        game->arwing->draw();
    }
    
    background->draw(0.0);
    if(shoot && game->arwing->endGame && !game->arwing->gameStart){
        for(int i = 0; i < game->arwing->weapon.size(); i++){
            game->arwing->weapon[i]->draw();
        }
    }

    if(!game->arwing->endGame){
        game->draw();
    }

    if(game->arwing->gameStart){
             
                 glColor3f(0.7, 0.5, 0.1);
                glRasterPos3f(-0.30f, 0.1f, 0.80f);

                string score1 = "START GAME, PRESS SPACE!!!!!!!!!!!!!: ";


                for(int i = 0; i < score1.length(); i++){
                    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score1[i]);
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
        // glutIdleFunc(game->arwing->positionManage("UP")); 
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

    for (int i = 0; i < game->shipList.size(); i++)
    {
        delete game->shipList[i];
    }

    for(int i = 0; i < game->arwing->weapon.size(); i++){
        delete game->arwing->weapon[i];
    }


    delete background;
}
