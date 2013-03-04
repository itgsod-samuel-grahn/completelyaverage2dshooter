#ifndef CLIENT_H
#define CLIENT_H

#include "netmanager.h"

class Client : public NetManager
{

public:
Client();
void Update();
void SendData(PlayerData* data);
private:
  IPaddress serverAddress;
};

#endif // CLIENT_H
