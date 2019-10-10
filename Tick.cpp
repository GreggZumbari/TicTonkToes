/*
 * This program is a console-bound tic-tac-toe game, where two players on the same
 * computer may take turns, playing their respective marks on the 3x3 grid board. It
 * counts how many wins and ties each side has achieved after each round.
 * @author Greggory Hickman, September-October 2019
 * @version pre-release 1.1
 */
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  
  //Player moves and empty values defined as constants to make code more readable
  int O_MOVE = 0;
  int X_MOVE = 1;
  int BLANK = 2;

  //Player command
  char move[2];
    
  int turnCount = 0;

  //Holds data for each tile
  int board[3][3];
  
  cout << "Hello all. This is my 2 player tic-tac-toe game." << endl;
  cout << "To place your piece, type the corresponding row number, followed by the corresponding column number on your turn." << endl;
  cout << "For example, type \"2b\" to play in the middle square, 1c to play in the top-right square, etc." << endl;
  cout << endl << "---------------" << endl;

  while (true) {
     
    bool playerOneVictory = false;
    bool playerTwoVictory = false;
      
    int turn = X_MOVE;
      
    //Clear board
    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        board[x][y] = BLANK;
      }
    }

    cout << endl;
      
    while (!playerOneVictory && !playerTwoVictory) {
      
      //Print the board
      cout << "Turns elapsed: " << turnCount << endl;
      cout << "  a b c" << endl;
      for (int x = 0; x < 3; x++) {
	cout << x + 1;
	for (int y = 0; y < 3; y++) {
	  cout << ' ';
	  if (board[x][y] == 2) {
	    cout << ' ';
	  }
	  if (board[x][y] == 1) {
	    cout << 'X';
	  }
	  if (board[x][y] == 0) {
	    cout << 'O';
	  }
	}
	cout << endl;
      }
      if (turn == 1) {
	cout << "It is X\'s turn!" << endl;
      }
      else {
	cout << "It is O\'s turn!" << endl;
      }

      //Place a piece
      cin >> move;
      cout << endl;
      if (((move[0] == '1' || move[0] == '2' || move[0] == '3') && (move[1] == 'a' || move[1] =='b' || move[1] == 'c')) ) {
        if (turn == X_MOVE) {
	  board[move[0] - 49][move[1] - 97] = X_MOVE;
	  turn = O_MOVE;
        }
        else if (turn == O_MOVE) {
	  board[move[0] - 49][move[1] - 97] = O_MOVE;
	  turn = X_MOVE;
        }
        turnCount++;
      }
        else {
          cout << "Illegal move. Please enter a number, followed by a letter (e.x. \"2a\", \"1c\", \"3b\")" << endl;
        }
      
    }

  }
  
}
