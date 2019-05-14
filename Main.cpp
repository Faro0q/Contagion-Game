/* Prog2Contagion.cpp

   Program #2: Play the game of Contagion against another person
               This is a variation of Ataxx, a version of which can
               be played online at: http://www.classikgames.com/ataxx.html
   Class: CS 141
   Date: 1/27/2019
   Author: *** Farooq Syed ***

   Grading Rubric:
     55% Passes Codio run-time tests (some cases below are split into multiple tests)
          5 Handles both upper and lower case user input
          5 Handles making adjacent move for each player
         10 Handles making jump move for each player
          5 Handles pass move 
          2 Error message and retry when source position does not belong to player
          2 Error message and retry when destination position is not empty
          6 Error message and retry when destination is not one or two squares away
            in horizontal, vertical, or diagonal line
         15 Flips opponent pieces adjacent to move destination
          5 When board is filled correctly identifies winner and exits program

     45% Programming Style:
         10 Meaningful Identifier Names.
         10 Comments, header, and meaningful variable names
         10 Functional Decomposition 
         10 Appropriate data and control structures
          5 Code Layout
*/

/***
 * Mallavarapu:
 * 1) Comments are absent
 * 2) The return type of getpiece is not restrictive enough.
 * ***/
#include <iostream>
#include <cstdlib> // for exit() and abs()
#include <math.h>
using namespace std;

// The 25 board position variables may be global variables, but no other variables may be global.
char p1, p2, p3, p4, p5,
    p6, p7, p8, p9, p10,
    p11, p12, p13, p14, p15,
    p16, p17, p18, p19, p20,
    p21, p22, p23, p24, p25;

char *getPiece(char row, char col)
{
    if (row == 'A' && col == '1')
    {
        return &p1;
    }
    else if (row == 'A' && col == '2')
    {
        return &p2;
    }
    else if (row == 'A' && col == '3')
    {
        return &p3;
    }
    else if (row == 'A' && col == '4')
    {
        return &p4;
    }
    else if (row == 'A' && col == '5')
    {
        return &p5;
    }
    else if (row == 'B' && col == '1')
    {
        return &p6;
    }
    else if (row == 'B' && col == '2')
    {
        return &p7;
    }
    else if (row == 'B' && col == '3')
    {
        return &p8;
    }
    else if (row == 'B' && col == '4')
    {
        return &p9;
    }
    else if (row == 'B' && col == '5')
    {
        return &p10;
    }
    else if (row == 'C' && col == '1')
    {
        return &p11;
    }
    else if (row == 'C' && col == '2')
    {
        return &p12;
    }
    else if (row == 'C' && col == '3')
    {
        return &p13;
    }
    else if (row == 'C' && col == '4')
    {
        return &p14;
    }
    else if (row == 'C' && col == '5')
    {
        return &p15;
    }
    else if (row == 'D' && col == '1')
    {
        return &p16;
    }
    else if (row == 'D' && col == '2')
    {
        return &p17;
    }
    else if (row == 'D' && col == '3')
    {
        return &p18;
    }
    else if (row == 'D' && col == '4')
    {
        return &p19;
    }
    else if (row == 'D' && col == '5')
    {
        return &p20;
    }
    else if (row == 'E' && col == '1')
    {
        return &p21;
    }
    else if (row == 'E' && col == '2')
    {
        return &p22;
    }
    else if (row == 'E' && col == '3')
    {
        return &p23;
    }
    else if (row == 'E' && col == '4')
    {
        return &p24;
    }
    else if (row == 'E' && col == '5')
    {
        return &p25;
    }
    else
    {
        return NULL;
    }
}
void setPiece(char row, char col, char newValue)
{
    char *piecePtr = getPiece(row, col);
    *piecePtr = newValue;
}
int countPieces(char piece)
{
    int count = 0;
    for (char row_i = 'A'; row_i <= 'E'; row_i++)
    {
        for (char col_j = '1'; col_j <= '5'; col_j++)
        {
            char *charPtr = getPiece(row_i, col_j);
            char pieceAtLocation = *charPtr;
            if (piece == pieceAtLocation)
            {
                count++;
            }
        }
    }
    return count;
}
void flipSurrounding(char row, char col, char currentPlayer)
{
    if (currentPlayer != 'X' && currentPlayer != 'O')
    {
        return;
    }
    for (char row_i = row - 1; row_i <= row + 1; row_i++)
    {
        for (char col_j = col - 1; col_j <= col + 1; col_j++)
        {
            char *charPtr = getPiece(row_i, col_j);
            if (charPtr == NULL)
            {
                continue;
            }
            char piece = *charPtr;
            if (piece == ' ')
            {
                continue;
            }
            if (currentPlayer == 'O')
            {
                setPiece(row_i, col_j, 'O');
            }
            else
            {
                setPiece(row_i, col_j, 'X');
            }
        }
    }
}
bool isValidMove(char currentRow, char currentCol, char destRow, char destCol)
{
    char *currentPiecePtr = getPiece(currentRow, currentCol);
    char currentPiece = *currentPiecePtr;
    char *destPiecePtr = getPiece(destRow, destCol);
    char destPiece = *destPiecePtr;
    return currentPiece != ' ' && destPiece == ' ';
}
void copyPiece(char currentRow, char currentCol, char destRow, char destCol)
{
    if (!isValidMove(currentRow, currentCol, destRow, destCol))
    {
        return;
    }
    char currentPiece = *getPiece(currentRow, currentCol);
    setPiece(destRow, destCol, currentPiece);
    flipSurrounding(destRow, destCol, currentPiece);
}
void movePiece(char currentRow, char currentCol, char destRow, char destCol)
{
    if (!isValidMove(currentRow, currentCol, destRow, destCol))
    {
        return;
    }
    char currentPiece = *getPiece(currentRow, currentCol);
    setPiece(currentRow, currentCol, ' ');
    setPiece(destRow, destCol, currentPiece);
    flipSurrounding(destRow, destCol, currentPiece);
}

//-----------------------------------------------------------------------------------------
// Display the game instructions
void displayInstructions()
{
    cout << " \n"
         << "Welcome to the 2-player game of Contagion, where the point of the game is    \n"
         << "to capture as much of the board as possible.  On each move you must enter \n"
         << "the row and column position of one of your current pieces (e.g. a1) and   \n"
         << "the row and column of an empty destination, which must be one or two      \n"
         << "squares away.  Moves can be made horizontally, vertically, or diagonally. \n"
         << " \n"
         << "If the destination is one square away, then an additional piece for you   \n"
         << "is placed in the destination square.  If the destination is two squares   \n"
         << "away (a jump move), then the original piece is moved to that destination. \n"
         << "jumping over a single square or any player's piece.                       \n"
         << " \n"
         << "After a piece has been moved, all opponent pieces adjacent to the         \n"
         << "destination are changed to match the piece of the user making the move.   \n"
         << "Player X moves first.     \n"
         << " \n"
         << "A valid first move, for instance, could be: a1 a2  which since it is just \n"
         << "one square away, would put an additional X on square a2.  Alternatively   \n"
         << "if the first move is:  a1 c3  then since it is two squares away, the piece\n"
         << "currently at a1 would be moved to destination c3.                         \n"
         << endl;
}
int countDistance(char currentRow, char currentCol, char destRow, char destCol)
{
    if (currentRow == destRow)
    {
        return abs(destCol - currentCol);
    }
    else if (currentCol == destCol)
    {
        return abs(destRow - currentRow);
    }
    else
    {
        int absRowDistance = abs(destRow - currentRow);
        return sqrt(pow(abs(destRow - currentRow), 2) + pow(abs(destCol - currentCol), 2));
    }
}
//-----------------------------------------------------------------------------------------
// Display the board, using the global board variables
// For reference here are the board row, col and board variable values:
//       1  2  3  4  5
//    ----------------
//  A |  1  2  3  4  5
//  B |  6  7  8  9 10
//  C | 11 12 13 14 15
//  D | 16 17 18 19 20
//  E | 21 22 23 24 25
//
void displayBoard()
{
    cout << "    1   2   3   4   5\n"
         << "  ---------------------\n"
         << "A | " << p1 << " | " << p2 << " | " << p3 << " | " << p4 << " | " << p5 << " | A\n"
         << "  |---|---|---|---|---|\n"
         << "B | " << p6 << " | " << p7 << " | " << p8 << " | " << p9 << " | " << p10 << " | B\n"
         << "  |---|---|---|---|---|\n"
         << "C | " << p11 << " | " << p12 << " | " << p13 << " | " << p14 << " | " << p15 << " | C\n"
         << "  |---|---|---|---|---|\n"
         << "D | " << p16 << " | " << p17 << " | " << p18 << " | " << p19 << " | " << p20 << " | D\n"
         << "  |---|---|---|---|---|\n"
         << "E | " << p21 << " | " << p22 << " | " << p23 << " | " << p24 << " | " << p25 << " | E\n"
         << "  ---------------------\n"
         << "    1   2   3   4   5\n"
         << endl;
}

//-----------------------------------------------------------------------------------------
int main()
{
    // Set initial values for the global board variables to all be blank
    p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = p14 = p15 = p16 = p17 = p18 = p19 = p20 = p21 = p22 = p23 = p24 = p25 = ' ';
    // Set corner starting positions
    p1 = p25 = 'X';
    p5 = p21 = 'O';

    // Variables to store user input for current row and column, and destination row and column
    char currentRow, currentCol, destRow, destCol;
    char input;

    // ...

    cout << "Welcome to the 2-player game of Contagion. \n"
         << endl;

    // Main loop to play game
    bool xMove = true;
    bool oMove = !xMove;

    while (true)
    {

        // Display board and handle first character of user input
        displayBoard();
        int xPieces = countPieces('X');
        int oPieces = countPieces('O');
        if (oPieces == 0)
        {
            cout << "X wins!" << endl;
            break;
        }
        else if (xPieces == 0)
        {
            cout << "O wins!" << endl;
            break;
        }
        else if (countPieces(' ') == 0)
        {
            // game over
            if (xPieces > oPieces)
            {
                cout << "X wins!" << endl;
                break;
            }
            else
            {
                cout << "O wins!" << endl;
                break;
            }
        }
        cout << "Enter 'i' for instructions, 'x' to exit, or move for "
             << (xMove ? "X" : "O")
             << ": ";
        cin >> input;
        input = toupper(input);

        // Check to see if user input was 'i' for instructions or 'x' to exit
        if (input == 'I')
        {
            displayInstructions();
            continue; // Loop back up to retry move
        }
        else if (input == 'X')
        {
            cout << "Exiting program... \n"
                 << endl;
            break; // Break out of enclosing loop, to exit the game.
        }
        else if (input == 'P')
        {
            xMove = !xMove;
            oMove = !oMove;
            continue;
        }
        else
        {
            if (input >= 'A' && input <= 'E')
            {
                currentRow = input;
            }
            cin >> input;
            while (input == ' ')
            {
                cin >> input;
            }
            if (input >= '1' && input <= '5')
            {
                currentCol = input;
            }
            cin >> input;
            while (input == ' ')
            {
                cin >> input;
            }
            input = toupper(input);
            if (input >= 'A' && input <= 'E')
            {
                destRow = input;
            }
            cin >> input;
            while (input == ' ')
            {
                cin >> input;
            }
            if (input >= '1' && input <= '5')
            {
                destCol = input;
            }
            char currentPiece = *getPiece(currentRow, currentCol);
            bool xIsMoving = false;
            if (currentPiece == 'X')
            {
                xIsMoving = true;
            }
            else if (currentPiece == 'O')
            {
                xIsMoving = false;
            }
            else
            {
                // throw error
                cout << "*** Invalid move.  Current piece must belong to you. Please retry." << endl;
                continue;
            }
            if ((xIsMoving && !xMove) || (!xIsMoving && !oMove))
            {
                cout << "*** Invalid move.  Current piece must belong to you. Please retry." << endl;
                continue;
            }
            else if (!isValidMove(currentRow, currentCol, destRow, destCol))
            {
                cout << "*** Invalid move.  Destination must be empty. Please retry." << endl;
                continue;
            }
            int distance = countDistance(currentRow, currentCol, destRow, destCol);
            switch (distance)
            {
            case 0: //invalid move
                break;
            case 1:
                copyPiece(currentRow, currentCol, destRow, destCol);
                break;
            case 2:
                movePiece(currentRow, currentCol, destRow, destCol);
                break;
            default:
                cout << "*** Invalid move.  A move must be one or two squares away. Please retry." << endl;
                continue;
            }
            xMove = !xMove;
            oMove = !oMove;

            // User input was not 'i' for instructions or 'x' to exit, so a move is being made
            // ...
        }
    } //end while( true)

    return 0;
} // end main()
