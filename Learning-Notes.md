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
		if (Loc ().x > xmax) velocity.x *= -1;
	drawself		
		draw at (0,0,0)

FIX: In the non-vector example, I initially set my bounds relative to the Felds Loc (), which was correct, but later removed the relative positioning because I noticed it worked using hard numbers and the code was more compact. This was because I was using numbers relative to the object anyway, so the big outter world made no difference. Using Loc () and vectors for positioning, and not accounting for the Felds Loc (), broke my boundary checking in the vector example.

Also– I needed to use Translation ().x in the boundary comparison instead of Loc ().x. 
I don't know why this is.


NOC_1_3_vector_subtraction
===========================

This was pretty easy. All it took was checking out the Pointing Events sample, finding PointingMove, and then looking up IntersectionDiff from the example which led me to Intersection. 

Didn't get it immediately. Had to use INFORM to realize I'd forgotten to substract Loc () from the Intersection value when drawing my line. 

Note: would be nice if Seedpod allowed you to paste text into the project name field. Also, would be nice if it saved your last Project Directory instead of defaulting to ~.


NOC_1_4_vector_multiplication
===========================

Straightforward.


NOC_1_5_vector_magnitude
===========================

Also straightforward. Was reminded that when using DrawQuad, that it draws from the bottom left-corner, not the top-right that I'm familiar with.


NOC_1_6_vector_normalize
===========================

Straightforward.


NOC_1_7_motion101
===========================

This took some time, primarily because I converted rewrote boundary detection so that it doesn't assume that the Feld is exactly perpendicular to the camera and aligned on the x and y axis. I understand the concept of using Feld -> Up () / Over () and Norm (), but the big breakthrough was learning about ProjectOnto. I created a convenience method that orients relative vectors to the Feld.

  Vect MapToFeld (Vect v) 
  { return Vect(v . ProjectOnto (over) + v . ProjectOnto (up) + v . ProjectOnto (norm)); }

Also assumed that my Feld's initial Translation value was (0, 0, 0), but understand now that it's the same as Loc--positioned in space.

Random () seemed broken until I realized that I needed to call SeedRandomizer (). Processing does this by default because it's such a common iterative need for artists and designers. 

Started using the Sketch class so I could use DrawEllipse (). I had absolutely no idea that I needed to move my drawing methods into the constructor (or use them in Travail () in case of the need to Clear ()) and remove DrawSelf () entirely. DrawSelf overrides drawing structures defined in the constructor. It was counter-intuitive, but Nick explained the reason and it made sense. Just a new way of thinking about things.


NOC_1_8_motion101_acceleration
===========================

Can't find a Limit () method for vectors. Might be nice to add to Greenhosue, especially for velocity limits in particle systems.


NOC_1_9_motion101_acceleration
===========================

Straightforward. Got schooled on ob-styling. Also wondered why I'm able to define custom class methods after I use them in Travail without errors. This works:

	void Travail ()
	  { IncTranslation (MapToFeld (velocity)); }
	  
	Vect MapToFeld (Vect v)
	  { return Vect (v . ProjectOnto (over) + v . ProjectOnto (up) + v . ProjectOnto (norm)); }


NOC_1_10_motion101_acceleration
===========================

It's confusing that Norm () is used for normalizing a vector since it has a completely different meaning in the context of Feld -> Norm ().

Also, looked for sine and cosine but found only PI under Math in the reference (can't browse the full reference). Discovered through trial and error that sin () and cos () are available.






