#include "gameactivity.h"

void GameActivity::Draw()
{
  std::vector<PlayerData*> players = manager->GetPlayers();
  for(int i = 0; i <players.size(); i++)
  {
    SDL_Rect rect;
    rect.x = players[i]->x;
    rect.y = players[i]->y;	
    rect.w = 10 * sizeof(players)/sizeof(players[0]);
    rect.h = 10 * sizeof(players)/sizeof(players[0]);
    SDL_FillRect(this->game->GetScreen(), &rect, (255,255,255));
  }
  
}

void GameActivity::Handle(SDL_Event event)
{
  Activity::Handle(event);
}

void GameActivity::Update()
{
  if(KeyIsPressed('w'))
  {
    myData->y--;
  }
  if(KeyIsPressed('s'))
  {
    myData->y++;
  }
  if(KeyIsPressed('a'))
  {
    myData->x--;
  }
  if(KeyIsPressed('d'))
  {
    myData->x++;
  }
  
  
  manager->SendData(myData);
  manager->Update();
  
}

GameActivity::GameActivity(Game* g, NetManager* manager):Activity(g)
{
  this->manager = manager;
  myData = new PlayerData(0,0,WEAPON);
}
void GameActivity::SetGameType(GameTypeName g)
{
  switch(g)
  {
    case DEATHMATCH:
      break;
  }
}


