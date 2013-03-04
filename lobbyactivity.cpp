#include "lobbyactivity.h"

void LobbyActivity::MenuItemSelected()
{
  switch(Selected())
  {
    case 0:
      this->game->SetActivity(HOSTGAME);
      break;
    case 1:
      this->game->SetActivity(JOINGAME);
      break;
    case 2:
      this->game->SetActivity(MAINMENU);
  }
  
}

LobbyActivity::LobbyActivity(Game* g): MenuActivity(g)
{
  background = SDL_MapRGB(this->game->GetScreen()->format, 255, 0, 255);
  AddItem("Host Game");
  AddItem("Join by IP");
  AddItem("Back");

}

