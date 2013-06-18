/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-5: Vector magnitude
 
 **/


class PointingTracker  :  public Thing
{ public:
  
  Vect pointerLoc;
  Vect vertex;
  float m; // magnitude
  float h; // bar height
  
  PointingTracker ()  :  Thing ()
  { SlapOnFeld ();
    h = 3.0;
  }
  
  void PointingMove (PointingEvent *e)
  { // pointer location
    pointerLoc = Intersection (e, Loc ());
    
    // subtract the feld location
    vertex = pointerLoc - Loc ();
    
    // get the magnitude
    m = vertex.Mag();
  }
  
  void DrawSelf ()
  { // draw line
    SetGLColor (Color (1, 1, 1));
    glLineWidth(2.0);
    glBegin (GL_LINES);
    glVertex (Vect (0, 0, 0));
    glVertex (vertex);
    glEnd ();
    
    // draw bar (DrawQuad draws from the bottom left corner)
    DrawQuad (Vect (-Feld () -> Width () / 2, Feld () -> Height () / 2 - h, 0), Vect (m, 0, 0), Vect (0, h, 0));
  }
  
};


void Setup ()
{ SetFeldsColor (Color ("#A8BBBA"));
  new PointingTracker ();
}
