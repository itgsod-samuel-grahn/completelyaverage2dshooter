#include "activity.h"
#include <SDL/SDL_ttf.h>

Activity::Activity(Game* g)
{
  this->game = g;
  font = TTF_OpenFont("font.ttf", 46);
}
Activity::~Activity()
{
}

bool Activity::KeyIsPressed(Uint8 key)
{
  if(pressedKeys[key] == true)
  {
    return true;
  }
  return false;
}

void Activity::Handle(SDL_Event event)
{
  switch(event.type){
        case SDL_KEYDOWN:
            pressedKeys[event.key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            pressedKeys[event.key.keysym.sym] = false;
            break;
  }
}
void Activity::Update()
{

}

void Activity::Draw()
{

}

void Activity::ApplySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(source, NULL, destination, &offset);
}


