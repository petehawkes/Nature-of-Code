/* (c)  oblong industries */


#include "Greenhouse.h"

/**
  When using new resource files please be sure to do the following in order to
  ensure that your application can find those resources:

    - Place all resource files in:

        /opt/oblong/greenhouse/share

    - OR if you'd like to keep your resource files separated from the installed
         resources:

      Create a folder for your personal resource files and add the following
      line to your ~/.bash_profile (Mac) or ~/.bashrc (Linux) file:

        export OB_SHARE_PATH=[/path/to/new/share]:$OB_SHARE_PATH
**/


class Box  :  public Thing
{ public:
  
  // initial positions and speeds reduced (compared to the Processing values)
  float width = 10.0;
  Vect velocity = Vect(1.5, .75, 0);
  
  // bounds
  float feldBoundRight;
  float feldBoundLeft;
  float feldBoundTop;
  float feldBoundBottom;
  
  Box ()  :  Thing ()
  { SlapOnFeld ();    
  }
  
  void Travail ()
  { // update position and detect bounds
    IncTranslation( velocity );
    //INFORM ( ToStr (Loc ()) );
    
    Vect v = Translation();
    
    float v_o = v.Dot(Feld () -> Over ());
    float v_u = v.Dot(Feld () -> Up ());
    
    SpaceFeld *f = Feld ();
    
    float xEdge = (f -> Loc () + f -> Over () * f -> Width () / 2.0).Dot(f -> Over ());
    float yEdge = (f -> Loc () + f -> Up () * f -> Height () / 2.0).Dot(f -> Up ());

    if (v_o > xEdge || v_o < -xEdge) {
      INFORM ( "HIT xEdge" );
      velocity.x = velocity.x * -1;
    }
    
    if (v_u > yEdge || v_u < -yEdge) {
      INFORM ( "HIT yEdge" );
      velocity.y = velocity.y * -1;
    }
    

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