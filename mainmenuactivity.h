#ifndef MAINMENUACTIVITY_H
#define MAINMENUACTIVITY_H

#include "menuactivity.h"
#include "activity.h"


class MainMenuActivity : public MenuActivity
{

public:
  MainMenuActivity(Game* g);
  void MenuItemSelected();
};

#endif // MAINMENUACTIVITY_H
