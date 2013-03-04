#ifndef MENUACTIVITY_H
#define MENUACTIVITY_H
#include <SDL/SDL.h>
#include "string"
#include "activity.h"
#include <SDL/SDL_ttf.h>
#include <vector>
#define STR_LEN 255

class MenuActivity :public Activity
{
  int selected;
public:
  MenuActivity(Game* g);
  ~MenuActivity();
  Uint32 background;
  void Update();
  void Draw();
  void Handle(SDL_Event event);
  
  int Selected();
  
  void AddItem(char* str);
  std::vector<char*> items;
  
private:
  SDL_Surface** texts;
  
protected:
  virtual void MenuItemSelected() = 0;
  
  
};

#endif // MENUACTIVITY_H
