#include <iostream>
#include <SDL/SDL.h>
#include "game.h"

int main(int argc, char **argv) {
  Game* g = new Game();
  delete g;
  return 0;
}
