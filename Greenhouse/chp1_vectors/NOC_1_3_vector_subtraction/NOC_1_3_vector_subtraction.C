/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-3: Vector subtraction
 
 **/


class PointingTracker  :  public Thing
{ public:
  
  Vect pointerLoc;
  Vect vertex;
  
  PointingTracker ()  :  Thing ()
    { SlapOnFeld ();
    }
  
  void PointingMove (PointingEvent *e)
    { // pointer location
      pointerLoc = Intersection (e, Loc ());
      
      // subtract the feld location
      vertex = pointerLoc - Loc ();
    }
  
  void DrawSelf ()
    { // draw line
      SetGLColor (Color (1, 1, 1));
      glLineWidth(2.0);
      glBegin (GL_LINES);
      glVertex (Vect (0, 0, 0));
      glVertex (vertex);
      glEnd ();
    }
  
};


void Setup ()
{ SetFeldsColor (Color ("#A8BBBA"));
  new PointingTracker ();
}
