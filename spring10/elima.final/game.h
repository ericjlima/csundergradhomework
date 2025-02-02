/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: game.h                                     */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#ifndef GAME_H
#define GAME_H

#include "drawEngine.h"
#include "level.h"
#include "character.h"
#include "mage.h"

class Game {

 public: 

  Game(int width, int height) : drawArea(width, height) {timer = 30, enemynum =0, levelnum = 0 ;}
  bool run(int, int, int) ;


 private:

  Level *level ;

  long frameCount ;
  double lastTime ;

  int timer ;
  int enemynum ;
  int levelnum ;

  DrawEngine drawArea ;

 protected:

  Mage *player ;

  bool getInput( char* key ) ;
  void timerUpdate(void) ;

} ;

#endif 
