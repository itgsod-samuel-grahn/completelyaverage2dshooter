#include "mainmenuactivity.h"
#include "activity.h"

MainMenuActivity::MainMenuActivity(Game* g): MenuActivity(g)
{
    background = SDL_MapRGB(this->game->GetScreen()->format, 255, 0, 255);
    
    AddItem("PLAY");
    AddItem("OPTIONS");
    AddItem("QUIT");
}
void MainMenuActivity::MenuItemSelected()
{
  switch(Selected())
  {
    case 0:
      this->game->SetActivity(LOBBY);
      break;
    case 2:
      this->game->Quit();
      break;
    case 1:
      this->game->SetActivity(OPTIONSMENU);
  }
}



