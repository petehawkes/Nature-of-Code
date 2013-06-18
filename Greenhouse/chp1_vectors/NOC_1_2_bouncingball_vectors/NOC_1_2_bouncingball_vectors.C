/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-2: Bouncing Ball, with Vectors! Loc () and PhysLoc ()
 Using a Box for now to keep drawing simple.
 
 **/


class Box  :  public Thing
{ public:
  
  // initial positions and speeds reduced (compared to the Processing values)
  float width = 10.0;
  Vect velocity = Vect(1.5, .75, 0);
  
  // bounds
  float feldBoundRight;
  float feldBoundLeft;
  float feldBoundTop;
  float feldBoundBottom;
  
  Box ()  :  Thing ()
  { SlapOnFeld ();
    // setting bounds to keep things readable
    // * * Bounds here are set relative to the Feld's Loc () * *
    feldBoundRight = Feld () -> Loc ().x + (Feld () -> Width () / 2);
    feldBoundLeft = Feld () -> Loc ().x - (Feld () -> Width () / 2);
    feldBoundTop = Feld () -> Loc ().y + (Feld () -> Height () / 2);
    feldBoundBottom = Feld () -> Loc ().y - (Feld () -> Height () / 2);
  }
  
  void Travail ()
  { // update position and detect bounds
    IncTranslation( velocity );
    INFORM ( ToStr (Loc ()) );
    // * * Use Translation () instead of Loc () to check the bounds * *
    if ( Translation ().x > feldBoundRight || Translation ().x < feldBoundLeft )
      velocity.x = velocity.x * -1;
    if ( Translation ().y > feldBoundTop || Translation ().y < feldBoundBottom ) 
      velocity.y = velocity.y * -1;
  }
  
  void DrawSelf ()
  { // draw a box with a half-width offset, drawn from the center
    SetGLColor (Color (1, 1, 1));
    DrawQuad (Vect (-width/2, -width/2, 0), Vect (width, 0, 0), Vect (0, width, 0));
  }
};


void Setup ()
{ // color the background
  SetFeldsColor (Color ("#A8BBBA"));
  // add the box
  new Box ();
}