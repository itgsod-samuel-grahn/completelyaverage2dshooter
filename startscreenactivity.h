#ifndef STARTSCREENACTIVITY_H
#define STARTSCREENACTIVITY_H

#include <../../home/grahnen/projects/2DShooter/activity.h>


class StartScreenActivity : public Activity
{

public:
virtual void Draw();
virtual void Handle(SDL_Event event);
virtual void Update();
StartScreenActivity(Game* g);
private:
  SDL_Surface* image;
};

#endif // STARTSCREENACTIVITY_H
