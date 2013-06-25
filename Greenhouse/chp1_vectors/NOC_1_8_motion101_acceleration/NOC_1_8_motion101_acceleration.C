/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-8: Motion 101 Acceleration
 Apply an acceleration vector and limit the velocity
 
 **/

class Mover  :  public Sketch
{ public:
  
  float width;
  Vect velocity;
  Vect acceleration;
  float top_speed;
  
  Vect loc;
  Vect over;
  Vect up;
  Vect norm;
  float wid;
  float hei;
  
  Mover ()  :  Sketch ()
  { width = 8.0;
    velocity = Vect (0, 0, 0);
    acceleration = Vect (-0.003, -0.01, 0);
    top_speed = 10.0;
    
    // store feld dimenions and orientation
    SpaceFeld *f = Feld ();
    loc = f -> Loc ();
    over = f -> Over ();
    up = f -> Up ();
    norm = f -> Norm ();
    wid = f -> Width ();
    hei = f -> Height ();
  
    SlapOnFeld ();
    
    // draw
    SetStroked (false);
    SetFillColor (Color (1, 1, 1));
    DrawEllipse (Vect (0, 0, 0), width, width);
  }
  
  void Travail ()
  { // add acceleration
    velocity += acceleration;
    // limit the speed, see Limit method below
    velocity = Limit (velocity, top_speed);
    // update position, translating velocity onto Feld size and orientation
    IncTranslation (MapToFeld (velocity));
    
    // detect bounds
    Vect v = Translation ();
    if (v . Dot (over) > (loc + over * wid / 2.0) . Dot (over))
      IncTranslation (MapToFeld (Vect (-wid, 0, 0)));
    if (v . Dot (over) < (loc - over * wid / 2.0) . Dot (over))
      IncTranslation (MapToFeld (Vect (wid, 0, 0)));
    if (v . Dot (up) > (loc + up * hei / 2.0) . Dot (up))
      IncTranslation (MapToFeld (Vect (0, -hei, 0)));
    if (v . Dot (up) < (loc - up * hei / 2.0) . Dot (up))
      IncTranslation (MapToFeld (Vect (0, hei, 0)));
  }
  
  Vect MapToFeld (Vect v)
  { return Vect (v . ProjectOnto (over) + v . ProjectOnto (up) + v . ProjectOnto (norm)); }
  
  Vect Limit (Vect v, float max)
  { if (v . Mag () > max)
      return v *= max / v . Mag ();
    else 
      return v;
  }
  
};


void Setup ()
{ // color the background
  SetFeldsColor (Color ("#A8BBBA"));
  // add the Mover
  new Mover ();
}