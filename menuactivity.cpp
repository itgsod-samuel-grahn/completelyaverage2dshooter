#include "menuactivity.h"
#include "activity.h"
#include <SDL/SDL_ttf.h>
  
MenuActivity::MenuActivity(Game* g):Activity(g)
{
  selected = 0;
  texts = new SDL_Surface*[items.size()];
}

MenuActivity::~MenuActivity()
{
  delete [] texts;
}



void MenuActivity::AddItem(char* str)
{
  items.push_back(str);
}

void MenuActivity::Draw()
{
    SDL_FillRect(this->game->GetScreen(), &this->game->GetScreen()->clip_rect, background);
    SDL_Color sel = {0,255,0};
    SDL_Color unsel = {0,0,0};
    for(int i = 0; i < items.size(); i++) 
    {
      if(i == selected){
	texts[i] = TTF_RenderText_Solid( font, items[i], sel );
      }
      else
      {
	texts[i] = TTF_RenderText_Solid( font, items[i], unsel );
      }
      
      ApplySurface((this->game->GetScreen()->clip_rect.w/2) -(texts[i]->clip_rect.w/2), 100 + 45*i, texts[i], this->game->GetScreen() );
    }

}

void MenuActivity::Handle(SDL_Event event)
{
  Activity::Handle(event);
  switch(event.type)
  {
    case SDL_KEYDOWN:
      if(event.key.keysym.sym == SDLK_UP) selected--;
      else if(event.key.keysym.sym == SDLK_DOWN) selected++;
      else if(event.key.keysym.sym == SDLK_RETURN)
      {
	MenuItemSelected();
      }
      if(selected < 0) selected = items.size()-1;
      else if(selected > (items.size()-1)) selected = 0;
  }
  
}
void MenuActivity::Update()
{
  Activity::Update();
  
}

int MenuActivity::Selected()
{
  return selected;
}


