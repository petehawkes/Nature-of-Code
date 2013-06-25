/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-7: Motion 101
 This is essentially the same as Example 1-2 with some Greenhouse-specific modifications:
    - using the Sketch class instead of Thing
    - this provides handy drawing methods, like DrawEllipse ()
    - DrawSelf () is removed, drawing is defined in the constructor
    
 **/

class Mover  :  public Sketch
{ public:
  
  float width = 8.0;
  // speeds randomized
  Vect velocity = Vect(Random(-2, 2), Random(-2, 2), 0);;
  
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
    // draw
    SetStroked (false);
    SetFillColor (Color (1, 1, 1));
    DrawEllipse (Vect (0, 0, 0), width, width);
    INFORM( ToStr (Translation()));
    INFORM( ToStr (Random(-100, 100)) );
    // start at random position
    SetTranslationHard(Translation () + MapToFeld(Vect (Random(-wid/2, wid/2), Random(-hei/2, hei), 0)));
  }
  
  void Travail ()
  { // update position, translating velocity onto Feld size and orientation
    IncTranslation (MapToFeld(velocity));
    
    // detect bounds
    Vect v = Translation();
    if (v . Dot(over) > (loc + over * wid / 2.0) . Dot(over))
      IncTranslation (MapToFeld(Vect (-wid, 0, 0)));
    if (v . Dot(over) < (loc - over * wid / 2.0) . Dot(over))
      IncTranslation (MapToFeld(Vect (wid, 0, 0)));
    if (v . Dot(up) > (loc + up * hei / 2.0) . Dot(up))
      IncTranslation (MapToFeld(Vect (0, -hei, 0)));
    if (v . Dot(up) < (loc - up * hei / 2.0) . Dot(up))
      IncTranslation (MapToFeld(Vect (0, hei, 0)));
  }
  
  Vect MapToFeld (Vect v) {
    return Vect(v . ProjectOnto (over) + v . ProjectOnto (up) + v . ProjectOnto (norm));
  }
  
};


void Setup ()
{ // color the background
  SetFeldsColor (Color ("#A8BBBA"));
  // generate a new random seed for unique results each time
  SeedRandomizer ();
  // add the Mover
  new Mover ();
}