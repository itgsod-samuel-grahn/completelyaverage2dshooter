#include "optionsmenuactivity.h"

OptionsMenuActivity::OptionsMenuActivity(Game* g): MenuActivity(g)
{
  background = SDL_MapRGB(this->game->GetScreen()->format, 0,255,255);
  
  AddItem("Nothing here yet");
  AddItem("Back");

}

void OptionsMenuActivity::MenuItemSelected()
{
  switch(Selected())
  {
    case 0:
      this->game->SetFullscreen();
      break;
    case 1:
      this->game->SetActivity(MAINMENU);
      break;
  }
}
