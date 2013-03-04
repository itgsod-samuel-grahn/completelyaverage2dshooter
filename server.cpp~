#include "server.h"
#include <map>
#include <iostream>
#include <arpa/inet.h>

Server::Server():NetManager()
{
  if (!(socket = SDLNet_UDP_Open(2005)))
	{
		fprintf(stderr, "SDLNet_UDP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
  
}

void Server::SendData(PlayerData* data)
{
  this->localPlayer = data;
}


void Server::Update()
{
  if(SDLNet_UDP_Recv(socket, packet))
  {
    
    Uint8 host = packet->address.host;
    
    uint32_t array[2] = {0,0};
    memcpy(&array, packet->data, sizeof(array));
    
    int x = array[0];
    int y = array[1];

    players[host] = new PlayerData(x,y,WEAPON);
    playerAddress[players[host]] = packet->address;
    
    std::cout << x << ":" << y << std::endl;
    
  }
  

  
  //TODO: FIX SENDING DATA TO CLIENTS.
  
  //SendDataToClients();
  
  
  
  
}

void Server::SendDataToClients()
{
  UDPpacket** packArray=SDLNet_AllocPacketV(players.size() + 1, 2048);
  int id = 0; 
  
  for(std::map<Uint8, PlayerData*>::iterator iter = players.begin(); iter != players.end(); iter++)
  {
    IPaddress ipa = playerAddress[iter->second];
    std::vector<PlayerData*> playerstosend;
    playerstosend.push_back(localPlayer);
    
    for(std::map<Uint8, PlayerData*>::iterator inner = players.begin(); inner != players.end(); inner++)
    {
      playerstosend.push_back(inner->second);
    }
    
    uint32_t count = playerstosend.size();
    uint32_t array[playerstosend.size()*2 + 1];
    array[0] = count;
    for(int i = 0; i < count; i++)
    {
      array[1+i*2] = playerstosend[i]->x;
      array[2+i*2] = playerstosend[i]->y;
    }
    
    memcpy(packArray[id]->data, array, sizeof(array));
    
    packArray[id]->address = ipa;
    
    
    
    
    id++;
    
  }
  SDLNet_UDP_SendV(socket,packArray, players.size() + 1);
}




