#include "client.h"
#include <iostream>
#include <arpa/inet.h>
#include <SDL/SDL_net.h>


Client::Client():NetManager()
{
  if (!(socket = SDLNet_UDP_Open(0)))
	{
		fprintf(stderr, "SDLNet_UDP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
  SDLNet_ResolveHost(&serverAddress, "127.0.0.1", 2005);
}

void Client::SendData(PlayerData* data)
{
  SendPlayerUDP(data, serverAddress);
  localPlayer = data;
}


void Client::Update()
{
    if(SDLNet_UDP_Recv(socket, packet))
    {
      //TODO: FIX RECIEVING DATA FROM SERVER. ADD IDENTIFIER OF PACKET-TYPE...
      uint32_t count;
      
      memcpy(&count, packet->data, sizeof(uint32_t));
      for(int i = 0; i < count; i++)
      {
	uint32_t x,y;
	memcpy(&x, packet->data + sizeof(uint32_t)*(1+2*i), sizeof(uint32_t));
	memcpy(&y, packet->data + sizeof(uint32_t)*(2+2*i), sizeof(uint32_t));
      }
    }
}

