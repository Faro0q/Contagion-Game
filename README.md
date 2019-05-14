# Contagion-Game

Write a program that allows two human players to play the game of Contagion, where the objective is to capture as many board positions as possible, alternating play between play X and O.  This game is a variation of Ataxx, a version of which can be played online at  http://www.classikgames.com/ataxx.html     The game ends when either one player is completely eliminated from the board or when all board positions are filled. 

Running the program looks like the following:
Welcome to the 2-player game of Contagion. 

    1   2   3   4   5  
  ---------------------
A | X |   |   |   | O | A 
  |---|---|---|---|---| 
B |   |   |   |   |   | B 
  |---|---|---|---|---| 
C |   |   |   |   |   | C 
  |---|---|---|---|---| 
D |   |   |   |   |   | D 
  |---|---|---|---|---| 
E | O |   |   |   | X | E 
  ---------------------
    1   2   3   4   5  

1. Enter 'i' for instructions, 'x' to exit, or move for X: i
 
Welcome to the 2-player game of Contagion, where the point of the game is    
to capture as much of the board as possible.  On each move you must enter 
the row and column position of one of your current pieces (e.g. a1) and   
the row and column of an empty destination, which must be one or two      
squares away.  Moves can be made horizontally, vertically, or diagonally. 
 
If the destination is one square away, then an additional piece for you   
is placed in the destination square.  If the destination is two squares   
away (a jump move), then the original piece is moved to that destination. 
jumping over a single square or any player's piece.                       
 
After a piece has been moved, all opponent pieces adjacent to the         
destination are changed to match the piece of the user making the move.   
Player X moves first.     
 
A valid first move, for instance, could be: a1 a2  which since it is just 
one square away, would put an additional X on square a2.  Alternatively   
if the first move is:  a1 c3  then since it is two squares away, the piece
currently at a1 would be moved to destination c3. 
