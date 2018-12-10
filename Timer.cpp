#include "Timer.h"

using namespace std;

void Timer::repeat(Timer* self){
    // cout<<self->interval<<endl;
    if (self->running){
        int delay = self->interval;
        self->action();
        std::this_thread::sleep_for (std::chrono::milliseconds(delay));
        repeat(self);
    }
}

Timer::Timer() {
    interval = 1000;
    running = false; 
    
}

Timer::~Timer(){
    if (running) timerThread.detach();
}

void Timer::stop(){
    running = false;
    cout<<"stop"<<endl;
}

void Timer::setRate(int mills){
    interval = mills;
}

void Timer::start(){
    running = true;
    timerThread = std::thread(repeat, this);
}
