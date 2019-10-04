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
  int BLANK = 0;
  int PLAYER1 = 1;
  int PLAYER2 = 2;

  int boardSize = 3;

  //Holds data for each tile
  int board[boardSize][boardSize];
  
  //Clear board
  for (int x = 0; x < boardSize; x++) {
    for (int y = 0; y < boardSize; y++) {
      board[x][y] = BLANK;
    }
  }

  cout << "Hello fellow friendless person. This is my 2 player tic-tac-toe game." << endl;
  cout << "To place your piece, type the corresponding row number, followed by the corresponding column number on your turn." << endl;
  cout << "For example, type \"2b\" to play in the middle square, 1c to play in the top-right square, etc." << endl;

  printBoard(board);
  
}

//Print the board exactly as it is when this method is called
int printBoard(int board) {
  cout << "  a b c" << endl;
  for (int x = 0; x < sizeof(board); x++) {
    for (int y = 0; y < sizeof(board); y++) {
      cout << y + 1 << " " << (int)board[x][y] << endl;
    }
  }
}
