Requirements:
	Needs python3

Game:

* To run level 1:
	python3 main1.py

* To run level 2:
 	python3 main2.py

* To run level 3:
 	python3 main3.py

* Frame generates per user input

* 'W', 'S', 'A', 'D' to control the Bomberman, 'B' to place bomb

* Bomb has a ticker:
		
		/--\			/--\			/--\			/- \
		\--/	=>		\- /	=>		\  /	=>		\  /

* Enemy dies instantly if in bomb explosion radius. Bomberman can be killed to.

* Kill all enemies to win the level. Breakable bricks give 20 pts, enemies give 100pts.


Bonuses Implemented:

* Implemented ticker for the bomb

* Implementation of 3 levels

* Color given to different objects


ASCII ART:

Bomberman:
[^^]
 ][ 			

Horizontal enemy:
@@@@
====
(Note the horizontal legs)

Vertical enemy:
@@@@
||||
(Note the vertical legs)

Bomb:
/--\
\--/

Bricks:
####
####

Walls:
XXXX
XXXX