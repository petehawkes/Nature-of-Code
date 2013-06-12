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


class PointingTracker  :  public Thing
{ public:
  
  Vect pointerLoc;
  
  PointingTracker ()  :  Thing ()
    { SlapOnFeld ();
    }
  
  void PointingMove (PointingEvent *e)
    { pointerLoc = Intersection (e, Loc ());
    }
  
  void DrawSelf ()
    { SetGLColor (Color (1, 1, 1));
      glLineWidth(2.0);
      glBegin (GL_LINES);
      glVertex (Vect (0, 0, 0));
      glVertex (pointerLoc - Loc ());
      glEnd ();

    }
  
};


void Setup ()
{ SetFeldsColor (Color ("#A8BBBA"));
  new PointingTracker ();
}
