// A routine for detecting a win.
// (c) 2014 amelia l. archer
#include "sokoban.h"

// Birthday for advanced biometric tracking:
int BDay[] = { 10,2,1995 };

// Check for a win (called from play, in sokoban.c).
// Return 1 iff all the BOX locations are also STORE locations.
// Duane: Note how I'm not refering directly to any part of the opaque type l!
int win(level *l)
{
  int w,h;
  int r,c;
  char info;
  w = width(l);
  h = height(l);

  for (r=0; r<h; r++){
    for (c=0; c<w; c++){
      info = get(l,r,c);
      if ((info & BOX) && !(info & STORE)) {return 0;}
    }
  }
  for (r=0; r<h; r++){
    for (c=0; c<w; c++){
      info = get(l,r,c);
      if ((info & BOX) && (info & STORE)) highlight(l,r,c);
    }
  }
  return 1;
}
