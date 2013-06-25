/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-10: Motion 101 Acceleration
 A "Mover" object stores velocity, and acceleration as vectors
 The motion is controlled by affecting the acceleration (in this case towards the mouse)
 
 **/

class Mover  :  public Sketch
{ public:
  
  float width;
  Vect velocity;
  Vect acceleration;
  Vect pointer_loc;
  float top_speed;
  
  Vect over;
  Vect up;
  Vect norm;
  
  Mover ()  :  Sketch ()
  { width = 8.0;
    velocity = Vect (0, 0, 0);
    acceleration = Vect (0, 0, 0);
    top_speed = 3.0;
    
    // store feld dimenions and orientation
    SpaceFeld *f = Feld ();
    over = f -> Over ();
    up = f -> Up ();
    norm = f -> Norm ();
    
    SlapOnFeld ();
    
    // draw
    SetStroked (false);
    SetFillColor (Color (1, 1, 1));
    DrawEllipse (Vect (0, 0, 0), width, width);
  }
  
  void Travail ()
  { // Compute a vector that points from Translation to Pointer
    acceleration = pointer_loc - Translation ();
    acceleration = acceleration.Norm ();
    acceleration.Scale (.1);

    // add acceleration
    velocity += acceleration;
    // limit the speed, see Limit method below
    velocity = Limit (velocity, top_speed);
    // update position, translating velocity onto Feld size and orientation
    IncTranslation (MapToFeld (velocity));
  }
                         
  void PointingMove (PointingEvent *e)
  { pointer_loc = Intersection (e); }
  
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
  // generate a new random seed for unique results each time
  SeedRandomizer ();
  // add the Mover
  new Mover ();
}