#include "startscreenactivity.h"

void StartScreenActivity::Draw()
{
  ApplySurface(0,0,this->image, this->game->GetScreen());
}

void StartScreenActivity::Handle(SDL_Event event)
{
  if(event.type == SDL_KEYDOWN)
  {
    this->game->SetActivity(MAINMENU);
   
  }
}

void StartScreenActivity::Update()
{

}

StartScreenActivity::StartScreenActivity(Game* g):Activity(g)
{
  image = SDL_LoadBMP("startscreen.bmp");
}

