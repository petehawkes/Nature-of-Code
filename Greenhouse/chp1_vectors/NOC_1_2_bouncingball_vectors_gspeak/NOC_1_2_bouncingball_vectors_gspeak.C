/* (c)  oblong industries */


#include "Greenhouse.h"

/**
 
 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman
 
 Example 1-2: Bouncing Ball, with Vectors! Loc () and PhysLoc ()
 Set up for g-speak Felds in space instead of directly accessing x and y coordinates. 
 
 **/


class Box  :  public Thing
{ public:
  
  // initial positions and speeds reduced (compared to the Processing values)
  float width = 10.0;
  Vect velocity = Vect(1.5, .75, 0);
  
  
  Box ()  :  Thing ()
  { SlapOnFeld ();
  }
  
  void Travail ()
  { // update position and detect bounds
    IncTranslation( velocity );
    //INFORM ( ToStr (Loc ()) );
    
    SpaceFeld *f = Feld ();
    
    Vect v = Translation();
    Vect o = f -> Over ();
    Vect u = f -> Up ();
    
    float v_o = v.Dot(o);
    //float v_u = v.Dot(Feld () -> Up ());
    
    float xEdge = (f -> Loc () + o * f -> Width () / 2.0).Dot(o);
    float yEdge = (f -> Loc () + u * f -> Height () / 2.0).Dot(u);
    
    if (v_o > xEdge ) {
      INFORM ( "HIT xEdge" );
      velocity.x = velocity.x * -1;
    }
    
    /*if (v_u > yEdge || v_u < -yEdge) {
     INFORM ( "HIT yEdge" );
     velocity.y = velocity.y * -1;
     }
     */
    
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