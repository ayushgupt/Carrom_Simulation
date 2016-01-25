#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "gamestate.h"
#include "renderstate.h"

extern renderstate_t g_rstate;
extern gamestate_t g_gstate;

gamestate_t::gamestate_t() 
{
  srand (time(NULL));
  double delta = rand()/(double)RAND_MAX;
  double force = (rand() % 25)+30;
  
  striker.pos.x = -0.65 + delta;
  striker.pos.y = -0.8;
  striker.type = STRIKER;
  striker.is_visible = true;
  
  delta = rand()/(double)RAND_MAX;
  coin.pos.x = delta*0.1;
  coin.pos.y = -1*delta*0.4;
  coin.vel.dx = 0.0;
  coin.vel.dy = 0.0;
  coin.type = WHITE;
  coin.is_visible = true;
    
  striker.vel.dx = (coin.pos.x - striker.pos.x)/force;
  striker.vel.dy = (coin.pos.y - striker.pos.y)/force;

}

void gamestate_t::update()
{
  // TODO: 
  // find out next position (using velocity)
  // detect collision of striker and coin (may assume perfect collision)
  // detect collision with the board, and make the coin bounce off the board
  // NOTE: After the striker has collided with the coin, set 'is_visible' of striker to false
  //      This will make the striker disappear from the board

  // Example code to move the striker
  // Begin Example (code)
  striker.pos.x += striker.vel.dx;
  striker.pos.y += striker.vel.dy;
  // End Example

}

void gamestate_t::render_game() 
{
  // copy gamestate to renderstate for rendering
  g_rstate.copy_state();
  g_rstate.render();  
}

void gamestate_t::loopstep() 
{
  update();
  render_game();
}


void gamestate_t::c_loopstep() {
    g_gstate.loopstep();
}


