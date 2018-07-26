Snek
===
**University of Costa Rica**   
**Programming project, first semmester, 2018**  

---

Snek is a game inspired in oldfashioned snake-like videogames where the player controls a snake around a map picking up food that makes it grow in size, if the snake bites itself in its quest to pick up food, the game's over.

The objective of those snake games is to survive as long as posible through the map, picking up food to make the snake longer and has the amount of food eaten as lives. If the snake hits a obstacule that refers to a n-integer, it loses n-lives obtained, if there are not more lives to lose, the game stops and the player lost.

<p><center><img src="/assets/readme/old_snake.jpg" alt="oldfashioned snake" align="middle" style="width: 300px;"/></center></p>

Unlike the other snake games, in this game the player moves endless through the map collecting food but in the scene appears some doors with a math expression written on them. The player must resolve the expression in order to hit the smaller one to loose the less amount of points as posible.  

There are no levels just to endless map but the difficulty increase according to the time played. When the difficulty increases, so does the food falling speed and the math operations get harder to solve.  Thus, the player must improve its maths skills alongside to its reflexes in order to get further. The game is planned to be locally single player there will not be network implementations in a near future.

The controls are easy to understand. First of all player can only move the snek along the X axis. For the computer version the player can move with the arrow keys or clicking on the left or right zone of the game screen. For the phone version the player has to tap on the left or right zone of the cellphone screen.  
Here is an example of the game interface:

<p><center><img src="/assets/readme/game_interface.png" alt="oldfashioned snake" align="middle" style="width: 300px;"/></center></p>

As it can be seen there are two sides of the window, on the release of the game will not mark the two sides. The black line is just to illustrate in this example.



------------------------

## First milestone
The first objective as developers is to implement the basis of the game, so we will put the snek represented by a block which moves only in the x-axis. For this time the movemente will be posible only with the mouse clicking on the left and right zone of the screen.

There will be two types of food, one that will make the snek increase its size and the other one will decrease it. The "good" food will have a blue color while the "bad" food will be red.

No obstacles will be available at this time and the speed of fall will be the same at all times.The size of the snek will be represented by a counter, not by the actual graphic of the snek. Also this counter will be a score bar where the player can follow his progress.

## Second milestone
In this part we will replace the bad food with obstacles represented by doors which will represent a factor to decrease the snek size. There will be at least 3 different types of doors for instance: explicit numbers, aritmetic problems etc...

A large row that fits along the X axis of the screen will represent the different doors, so the player must choose one because he cant dodge them. Each door will be delemited by a tiny dot line of a contrast color. The math expresion will be clear on the middle of the door. If the snek has enough life to pass the door it will continue on the game with that amount of life less.

Also the snek size will be both represented by the counter and by an actual relation within the counter and its graphic representation. Besides for a better gameplay the snek size will be related to the speed of scrolling of the view, giving the player a comprehensive window of time to react.

Here is a proposal of the game with the future doors:

<p><center><img src="/assets/readme/concepto.png" alt="oldfashioned snake" align="middle" style="width: 300px;"/></center></p>

## Built with

Qt creator (IDE)  
C++ (only language used)

## Contributers

#### Antonio Álvarez Chavarría </pre>

#### Luis Diego Naranjo Monge

#### Sade Nudjent Mejía ( assets )
