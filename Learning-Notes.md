Thoughts on Greenhouse from a Processing perspective
===========================

Using Dan Shiffman's Nature of Code Examples. 


NOC_1_1_bouncingball_novectors
===========================

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


NOC_1_2_bouncingball_vectors
===========================

- what's the difference between Loc () and PhysLoc () ? (av: They are the same)
- JC pointed me to IncTranslation. I think I'm making some assumptions about respiration that are causing problems with my logic? (av: nope, I was setting bounds that didn't account for the Feld's Loc () in a broader context.)

OLD METHOD

	travail
		x += xspeed
		if (x > xmax) speed *= -1;
	drawself		
		draw using x

NEW METHOD (this gets stuck on the edge of the bounds)

	travail
		IncTranslation ( velocity );
		if (Loc().x > xmax) velocity.x *= -1;
	drawself		
		draw at (0,0,0)

FIX: In the non-vector example, I initially set my bounds relative to the Felds Loc (), which was correct, but later removed the relative positioning because I noticed it worked using hard numbers and the code was more compact. This was because I was using numbers relative to the object anyway, so the big outter world made no difference. Using Loc () and vectors for positioning, and not accounting for the Felds Loc (), broke my boundary checking in the vector example.

Also– I needed to use Translation ().x in the boundary comparison instead of Loc ().x. 
I don't know why this is.


NOC_1_3_vector_subtraction
===========================

This was pretty easy. All it took was checking out the Pointing Events sample, finding PointingMove, and then looking up IntersectionDiff from the example which led me to Intersection. 

Didn't get it immediately. Had to use INFORM to realize I'd forgotten to substract Loc () from the Intersection value when drawing my line. 




