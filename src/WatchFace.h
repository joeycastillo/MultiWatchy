#ifndef WATCHFACE_H
#define WATCHFACE_H

class MultiWatchy;

class WatchFace {
  public:
    virtual void drawWatchFace(); // override this method for different watch faces
    MultiWatchy *watch;
};

#endif