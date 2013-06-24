/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-7: Motion 101
 This is essentially the same as Example 1-2 with some Greenhouse-specific modifications:
    - using the Sketch class instead of Thing
    - this provides handy drawing methods, like DrawEllipse ().
    - DrawSelf () is removed.
    - drawing happens instead in the constructor. 
    
 **/

class Mover  :  public Sketch
{ public:
  
  // initial positions and speeds reduced (compared to the Processing values)
  float width = 8.0;
  Vect velocity = Vect(1.5, .75, 0);
  
  // store feld dimenions and orientation
  SpaceFeld *f = Feld ();
  Vect loc = f -> Loc ();
  Vect over = f -> Over ();
  Vect up = f -> Up ();
  Vect norm = f -> Norm ();
  float wid = f -> Width ();
  float hei = f -> Height ();
  
  Mover ()  :  Sketch ()
  { SlapOnFeld ();
    SetStroked (false);
    SetFillColor (Color (1, 1, 1));
    DrawEllipse (Vect (0, 0, 0), width, width);
  }
  
  void Travail ()
  { // update position, translating velocity onto Feld size and orientation
    IncTranslation (MapToFeld(velocity));
    
    // detect bounds
    Vect v = Translation();
    if (v.Dot(over) > (loc + over * wid / 2.0).Dot(over))
      IncTranslation (MapToFeld(Vect (-wid, 0, 0)));
    if (v.Dot(over) < (loc - over * wid / 2.0).Dot(over))
      IncTranslation (MapToFeld(Vect (wid, 0, 0)));
    if (v.Dot(up) > (loc + up * hei / 2.0).Dot(up))
      IncTranslation (MapToFeld(Vect (0, -hei, 0)));
    if (v.Dot(up) < (loc - up * hei / 2.0).Dot(up))
      IncTranslation (MapToFeld(Vect (0, hei, 0)));
  }
  
  Vect MapToFeld (Vect v) {
    return Vect(v . ProjectOnto (over) + v . ProjectOnto (up) + v . ProjectOnto (norm));
  }
  
};


void Setup ()
{ // color the background
  SetFeldsColor (Color ("#A8BBBA"));
  // add the box
  new Mover ();
}