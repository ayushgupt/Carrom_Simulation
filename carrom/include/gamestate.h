#pragma once

#include "piece.h"
#include "renderstate.h"

class gamestate_t 
{
  public: 
    carrompiece_t striker;
    carrompiece_t coin;
    
    gamestate_t();
    void update();
    void idle();
    void render_game();
    void loopstep();
    static void c_loopstep();
};


