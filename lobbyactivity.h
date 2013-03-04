#ifndef LOBBYACTIVITY_H
#define LOBBYACTIVITY_H

#include "menuactivity.h"


class LobbyActivity : public MenuActivity
{

protected:
void MenuItemSelected();

public:
LobbyActivity(Game* g);

};

#endif // LOBBYACTIVITY_H
