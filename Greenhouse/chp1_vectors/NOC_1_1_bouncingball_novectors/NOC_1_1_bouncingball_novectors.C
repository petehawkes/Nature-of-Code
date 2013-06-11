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
  float xspeed = 1.5;
  float yspeed = .75;
  
  // bounds
  float feldBoundRight;
  float feldBoundLeft;
  float feldBoundTop;
  float feldBoundBottom;

  Box ()  :  Thing ()
    { SlapOnFeld ();
      // setting bounds to keep things readable
      feldBoundRight = Feld () -> Width () / 2;
      feldBoundLeft = -(Feld () -> Width () / 2);
      feldBoundTop = Feld () -> Height () / 2;
      feldBoundBottom = -(Feld () -> Height () / 2);
    }
  
  void Travail ()
    { // update position and detect bounds
      x += xspeed;
      y += yspeed;
      INFORM( "feldLoc:" + ToStr( Feld () -> Loc () ));

      if ( x > feldBoundRight || x < feldBoundLeft )
        xspeed = xspeed * -1;
      if ( y > feldBoundTop || y < feldBoundBottom )
        yspeed = yspeed * -1;
    }
  
  void DrawSelf ()
    { // draw a box with a half-width offset, using x and y
      SetGLColor (Color (1, 1, 1));
      DrawQuad (Vect (x-width/2, y-width/2, 0), Vect (width, 0, 0), Vect (0, width, 0));
    }
};


void Setup ()
{ // color the background
  SetFeldsColor (Color ("#A8BBBA"));
  // add the box
  new Box ();
}
