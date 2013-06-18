/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-2: Bouncing Ball, with Vectors! Loc () and PhysLoc ()
 Set up for g-speak Felds in space instead of directly accessing x and y coordinates.
 
 **/


class Mover  :  public Thing
{ public:
  
  // initial positions and speeds reduced (compared to the Processing values)
  float width = 10.0;
  Vect velocity = Vect(1.5, .75, 0);
  
  Mover ()  :  Thing ()
  { SlapOnFeld ();
  }
  
  void Travail ()
  { // update position
    IncTranslation( velocity );
    
    // store feld dimenions and orientation
    SpaceFeld *f = Feld ();
    
    Vect v = Translation();
    Vect over = f -> Over ();
    Vect up = f -> Up ();
    Vect loc = f -> Loc ();
    float wid = f -> Width ();
    float hei = f -> Height ();
    
    // detect bounds
    if (v.Dot(over) > (loc + over * wid / 2.0).Dot(over) || v.Dot(over) < (loc - over * wid / 2.0).Dot(over))
      velocity.x = velocity.x * -1;
    if (v.Dot(up) > (loc + up * hei / 2.0).Dot(up) || v.Dot(up) < (loc - up * hei / 2.0).Dot(up))
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
  new Mover ();
}