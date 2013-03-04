#include "netmanager.h"
#include <iostream>

NetManager::NetManager()
{
  SDLNet_Init();
  packet = SDLNet_AllocPacket(1024);
}

std::vector<PlayerData*> NetManager::GetPlayers()
{
  std::vector<PlayerData*> myPlayers;
  for(std::map<Uint8, PlayerData*>::iterator iter = players.begin(); iter != players.end(); iter++)
  {
    myPlayers.push_back(iter->second);
  }
  myPlayers.push_back(localPlayer);
  return myPlayers;
}

void NetManager::SendPlayerUDP(PlayerData* data, IPaddress serverAddress)
{
  uint32_t array[2] = {data->x, data->y};
  memcpy(packet->data, &array, sizeof(array));
  
  
  packet->address = serverAddress;
  
  packet->len = sizeof(packet->data) + 1;
  
  SDLNet_UDP_Send(socket, -1, packet);

}
