/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-2: Bouncing Ball, with Vectors! Loc () and PhysLoc ()
 Set up for g-speak Felds in space instead of directly accessing x and y coordinates. 
 - Translation uses ProjectOnto to account for Felds not perfectly aligned to the x and y axis
 - Border detection using .Dot product instead of specific x and y values.

 
 **/

class Box  :  public Thing
{ public:
  
  float width;
  Vect velocity;
  
  Vect loc;
  Vect over;
  Vect up;
  Vect norm;
  float wid;
  float hei;

  Box ()  :  Thing ()
  { // initial positions and speeds reduced (compared to the Processing values)
    width = 10.0;
    velocity = Vect(1.5, .75, 0);
    
    // store feld dimenions and orientation
    SpaceFeld *f = Feld ();
    loc = f -> Loc ();
    over = f -> Over ();
    up = f -> Up ();
    norm = f -> Norm ();
    wid = f -> Width ();
    hei = f -> Height ();
    
    SlapOnFeld ();
  }

  
  void Travail ()
  { // update position, translating velocity onto Feld size and orientation
    IncTranslation (MapToFeld (velocity));
        
    // detect bounds
    Vect v = Translation();
    if (v . Dot (over) > (loc + over * wid / 2.0) . Dot (over) || v . Dot (over) < (loc - over * wid / 2.0) . Dot (over))
      velocity.x *= -1;
    if (v . Dot (up) > (loc + up * hei / 2.0) . Dot (up) || v . Dot (up) < (loc - up * hei / 2.0) . Dot (up))
      velocity.y *= -1;
  }
  
  void DrawSelf ()
  { // draw a box with a half-width offset, drawn from the center
    SetGLColor (Color (1, 1, 1));
    DrawQuad (Vect (-width/2, -width/2, 0), Vect (width, 0, 0), Vect (0, width, 0));
  }
  
  Vect MapToFeld (Vect v)
  { return Vect(v . ProjectOnto (over) + v . ProjectOnto (up) + v . ProjectOnto (norm)); }
  
};


void Setup ()
{ // color the background
  SetFeldsColor (Color ("#A8BBBA"));
  // add the box
  new Box ();
}