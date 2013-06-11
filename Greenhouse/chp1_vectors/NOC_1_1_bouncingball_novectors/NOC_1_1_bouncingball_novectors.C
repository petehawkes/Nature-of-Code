/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman

 Example 1-1: Bouncing Ball, no vectors
 Using a Box for now to keep drawing simple. 
 
**/


class Box  :  public Thing
{ public:
  
  // initial positions and speeds reduced (compared to the Processing values)
  float x = 10.0;
  float y = 10.0;
  float width = 10.0;
  float xspeed = .75;
  float yspeed = .5;
  
  // bounds
  float feldBoundRight;
  float feldBoundLeft;
  float feldBoundTop;
  float feldBoundBottom;

  
  Box ()  :  Thing ()
    { SlapOnFeld ();
      // setting my bounds to keep things readable
      // unsure why I need to add PhysLoc().x to each, since it's 0 by default. 
      feldBoundRight = PhysLoc().x + (Feld () -> Width () / 2);
      feldBoundLeft = PhysLoc().x - (Feld () -> Width () / 2);
      feldBoundTop = PhysLoc().y + (Feld () -> Height () / 2);
      feldBoundBottom = PhysLoc().y - (Feld () -> Height () / 2);
    }
  
  void Travail ()
  { x += xspeed;
    y += yspeed;
    if ( x > feldBoundRight || x < feldBoundLeft ) {
      xspeed = xspeed * -1;
    }
    if ( y > feldBoundTop || y < feldBoundBottom ) {
      yspeed = yspeed * -1;
    }
  }
  
  void DrawSelf ()
  { // draw a box with a half-width offset
    SetGLColor (Color (0, 1, 0));
    DrawQuad (Vect (x-width/2, y-width/2, 0), Vect (width, 0, 0), Vect (0, width, 0));
  }
};


void Setup ()
{ new Box ();
}
