/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-7: Motion 101
 This is the same as Example 1-2. We were already using objects. 
 
 **/

class Box  :  public Thing
{ public:
  
  // initial positions and speeds reduced (compared to the Processing values)
  float width = 10.0;
  Vect velocity = Vect(1.5, .75, 0);
  
  // store feld dimenions and orientation
  SpaceFeld *f = Feld ();
  Vect loc = f -> Loc ();
  Vect over = f -> Over ();
  Vect up = f -> Up ();
  Vect norm = f -> Norm ();
  float wid = f -> Width ();
  float hei = f -> Height ();
  
  
  Box ()  :  Thing ()
  { SlapOnFeld ();
  }
  
  void Travail ()
  { // update position, translating velocity onto Feld size and orientation
    IncTranslation (velocity . ProjectOnto (over) + velocity . ProjectOnto (up) + velocity . ProjectOnto (norm));\
    
    // detect bounds
    Vect v = Translation();
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
  new Box ();
}