/* FREE SOFTWARE FOR YOU TO ENJOY */

#ifndef GAME_H
#define GAME_H
#include "SDL/SDL.h"

class Activity;

enum ActivityType
  {
    MAINMENU, 
    LOBBY,
    JOINGAME,
    ENTERIP,
    OPTIONSMENU,
    HOSTGAME
    
  };

class Game
{
public:
  Game();
  SDL_Surface* GetScreen();
  void Quit();
  void SetActivity(ActivityType type);
  void SetFullscreen();
  void Host();
private:
  SDL_Surface* screen;
  Activity *currentActivity;
  Activity *switchActivity;
  bool quit;
  void Update();
  void Unload();
};

#endif // GAME_H
