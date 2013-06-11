Thoughts on Greenhouse from a Processing perspective
===========================

Using Dan Shiffman's Nature of Code Examples. 

NOC_1_1_bouncingball_novectors

Initial setup. 
- Looking for something like setup() and loop(). 
- I see Setup(), but needed to understand that travail (update) and other events happen within objects, so I need to define a class for everything.

Looking for something like width and height to know my window size and don't immediately understand how to change the feld size. 
- Feld size is defined in a .protein. Immediate concerns about all my files sharing a single size condifuration in /etc/oblong/feld.protein
- Feld () -> Width () is useful
- Feld () -> PhysLoc() needed for objects to know where they are relative to the space they're in

- Reference > Thing () code example here is useful since I want to draw like I do in Processing. Simple openGL examples are good.
- Drah () object name in reference is odd. Why not Circle or Ball or MyShape or even MyThing?

Drawing a circle.
- Remembering that in c++ this is not built-in. Need to use a for loop. 
- Looking for sine and cosine functions in greenhouse. Don't see them in the reference. 
- Using DrawQuad() instead. 
- DrawQuad documentation talks about one leg and the other leg. Why not width and height? 

- Needed to understand INFORM (); and ToStr() immediately. Very helpful.

- Unsure why I need to add PhysLoc().x to my bounds, since it's 0 by default. 
	feldBoundRight = PhysLoc().x + (Feld () -> Width () / 2);  // this works
	feldBoundRight = Feld () -> Width () / 2;  // this doesn't

- Not sure how to change feld background color. 
- Found it: SetFeldsColor (Color ("#A8BBBA"));