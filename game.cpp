#include "game.h"
#include "menuactivity.h"
#include "gameactivity.h"
#include "mainmenuactivity.h"
#include "optionsmenuactivity.h"
#include "pugixml.hpp"
#include "startscreenactivity.h"
#include "lobbyactivity.h"
#include "server.h"
#include "client.h"
#include <iostream>


Game::Game()
{
  
  screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
  SDL_Init(SDL_INIT_EVERYTHING);
  freopen("/dev/tty", "a", stdout); // redirects stdout
  freopen("/dev/tty", "a", stderr); // redirects stderr
  std::cout << "HELLO"<<std::endl;
  TTF_Init();
  
  quit = false;
  currentActivity = new StartScreenActivity(this);
  int framerate = 60;
  double frameTime = 1000/framerate;
  int startms;
  int endms;
  int delayms;
  while(!this->quit)
  {
    startms = SDL_GetTicks();
    this->Update();
    endms = SDL_GetTicks();
    delayms = frameTime - (endms - startms);
    SDL_Delay(delayms);
  }
  Unload();  
}

void Game::SetFullscreen()
{
  //TODO:FIX
  Uint32 flags = SDL_HWSURFACE;
  screen = SDL_SetVideoMode(800,600,32,flags);
}


void Game::SetActivity(ActivityType type)
{
  switch(type)
  {
    case MAINMENU:
      
      switchActivity = new MainMenuActivity(this);
      break;
    case OPTIONSMENU:
      switchActivity = new OptionsMenuActivity(this);
      break;
    case JOINGAME:
      switchActivity = new GameActivity(this, new Client());
      break;
    case LOBBY:
      switchActivity = new LobbyActivity(this);
      break;
    case HOSTGAME:
      switchActivity = new GameActivity(this, new Server());
      break;
      
  }
}



void Game::Quit()
{
  this->quit = true;
}

SDL_Surface* Game::GetScreen()
{
  return screen;
}

void Game::Update()
{
  SDL_Event event;
  while(SDL_PollEvent(&event))
  {
    if(event.type == SDL_QUIT)
    {
      quit = true;
    }
    else
    {
      currentActivity->Handle(event);
    }
  }
  
  
  if(switchActivity != NULL)
  {
    //delete currentActivity;
    currentActivity = switchActivity;
    switchActivity = NULL;
  }
  else
  {
    SDL_FillRect(screen, &screen->clip_rect, (0,0,0));
    currentActivity->Update();
    currentActivity->Draw();
    SDL_Flip(GetScreen());
  }
}
void Game::Unload()	
{
  TTF_Quit();
  SDL_Quit();
}






