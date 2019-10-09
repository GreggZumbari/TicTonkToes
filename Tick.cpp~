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
  char BLANK = (char)32;
  char X_MOVE = 'X';
  char O_MOVE = 'O';

  //Whose turn is it?
  char turn = X_MOVE;

  //Player command
  char move[2];

  int boardSize = 3;
  int turnCount = 0;

  //Holds data for each tile
  int board[boardSize][boardSize];
  
  //Clear board
  for (int x = 1; x < boardSize; x++) {
    for (int y = 1; y < boardSize; y++) {
      board[x][y] = BLANK;
    }
  }
  
  cout << "Hello fellow friendless person. This is my 2 player tic-tac-toe game." << endl;
  cout << "To place your piece, type the corresponding row number, followed by the corresponding column number on your turn." << endl;
  cout << "For example, type \"2b\" to play in the middle square, 1c to play in the top-right square, etc." << endl;
  cout << endl << "---------------" << endl;

  while (true) {

    cout << endl;
    
    //Print the board
    cout << "Turns elapsed: " << turnCount << endl;
    cout << "  a b c" << endl;
    for (int x = 0; x < boardSize; x++) {
      cout << x + 1;
      for (int y = 0; y < boardSize; y++) {
	cout << " " << (char)board[x][y];
      }
    cout << endl;
    }

    //Place a piece
    cin >> move;
    if (((move[0] == '1' || move[0] == '2' || move[0] == '3') && (move[1] == 'a' || move[1] == 'b' || move[1] == 'c')) ) {
      if (turn == X_MOVE) {
	board[move[0] - 49][move[1] - 97] = X_MOVE;
	turn = O_MOVE;
      }
      else {
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

