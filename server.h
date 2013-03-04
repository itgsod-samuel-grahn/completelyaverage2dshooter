#ifndef SERVER_H
#define SERVER_H
#include "netmanager.h"
#include <map>

class Server :public NetManager
{

public:
Server();
void Update();
void SendData(PlayerData* data);
private:
    
private:
void SendDataToClients();
};

#endif // SERVER_H
