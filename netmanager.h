#ifndef NETMANAGER_H
#define NETMANAGER_H


#include "SDL/SDL_net.h"
#include <vector>
#include <map>



enum Equipped
{
  WEAPON,
  SPELL
};
struct PlayerData
{
  uint32_t x, y;
  Equipped equipped;
  
  IPaddress clientAddress;
  PlayerData(int x, int y, Equipped equipped)
  {
    this->x = x;
    this->y = y;
    this->equipped = equipped;
  }
  PlayerData();
};

class NetManager
{

public:
NetManager();
virtual void Update() = 0;
virtual void SendData(PlayerData* data) = 0;
virtual std::vector<PlayerData*> GetPlayers();

protected:
  PlayerData* localPlayer;
  UDPsocket socket;
  UDPpacket* packet;
  std::map<Uint8, PlayerData*> players;
  std::map<PlayerData*, IPaddress> playerAddress;

  void SendPlayerUDP(PlayerData* data, IPaddress serverAddress);
};

#endif // NETMANAGER_H
