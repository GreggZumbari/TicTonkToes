/*
 * This program is a console-bound tic-tac-toe game, where two players on the same
 * computer may take turns, playing their respective marks on the 3x3 grid board. It
 * counts how many wins and ties each side has achieved after each round.
 * @author Greggory Hickman, September-October 2019
 * @version release 1.0
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
    
  int turnCount;
  int turn = X_MOVE;
  int x_wins = 0;
  int o_wins = 0;
  int ties = 0;
  
  cout << endl << "Hello all. This is my 2 player tic-tac-toe game." << endl;
  cout << "To place your piece, type the corresponding row number, followed by the corresponding column number on your turn." << endl;
  cout << "For example, type \"2b\" to play in the middle square, 1c to play in the top-right square, etc.";

  while (true) {

    //Holds data for each tile 
    int board[3][3];

    turnCount = 0;
    bool playerOneVictory = false;
    bool playerTwoVictory = false;
      
    //Clear board
    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        board[x][y] = (char)32;
      }
    }

    cout << endl;
      
    while (!playerOneVictory && !playerTwoVictory && turnCount < 9) {

      //Print the scoreboard
      cout << endl << "---------------" << endl << "X Wins: " << x_wins << endl << "O Wins: " << o_wins << endl << "Ties: " << ties << endl << "---------------" << endl;
      
      //Print the board
      cout << "Turns elapsed: " << turnCount << endl;
      cout << "  a b c" << endl;
      for (int x = 0; x < 3; x++) {

	char output[3];
	output[0] = (char)32;
	output[1] = (char)32;
	output[2] = (char)32;

	cout << x + 1 << ' ';
	for (int y = 0; y < 3; y++) {
	  if (board[x][y] == BLANK) {
	    output[y] = (char)32;
	  }
	  if (board[x][y] == X_MOVE) {
	    output[y] = 'X';
	  }
	  if (board[x][y] == O_MOVE) {
	    output[y] = 'O';
	  }
	}
	cout << output[0] << " " << output[1] << " " << output[2] << endl;
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
      if (((move[0] == '1' || move[0] == '2' || move[0] == '3') && (move[1] == 'a' || move[1] =='b' || move[1] == 'c')) && (board[move[0] - 49][move[1] - 97] != X_MOVE && board[move[0] - 49][move[1] - 97] != O_MOVE)) {
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
      
      //Has either player won??? Credit to Gregg from 2018 for doing this once so that I never have to do it ever again. Gregg from 2018, if you are reading this, thank you. Sincerely, Gregg from 2019.
      //If player one wins...
      if(board[0][0] == X_MOVE && board[0][1] == X_MOVE && board[0][2] == X_MOVE){
	//Old me used to indent like crazy. My sincerest apologies to whoever has to grade this
	playerOneVictory = true;

      }
      
      else if(board[1][0] == X_MOVE && board[1][1] == X_MOVE && board[1][2] == X_MOVE){

	playerOneVictory = true;

      }
      
      else if(board[2][0] == X_MOVE && board[2][1] == X_MOVE && board[2][2] == X_MOVE){
	
	playerOneVictory = true;
	
      }
      
      else if(board[0][0] == X_MOVE && board[1][0] == X_MOVE && board[2][0] == X_MOVE){
	
	playerOneVictory = true;
	
      }
      
      else if(board[0][1] == X_MOVE && board[1][1] == X_MOVE && board[2][1] == X_MOVE){
	
	playerOneVictory = true;
	
      }
      
      else if(board[0][2] == X_MOVE && board[1][2] == X_MOVE && board[2][2] == X_MOVE){
	
	playerOneVictory = true;
	
      }
      
      else if(board[0][0] == X_MOVE && board[1][1] == X_MOVE && board[2][2] == X_MOVE){
	
	playerOneVictory = true;
	
      }
      
      else if(board[0][2] == X_MOVE && board[1][1] == X_MOVE && board[2][0] == X_MOVE){
	
	playerOneVictory = true;
	
      }
      
      //If player two wins...
      else if(board[0][0] == O_MOVE && board[0][1] == O_MOVE && board[0][2] == O_MOVE){
	
	playerTwoVictory = true;
	
      }
      
      else if(board[1][0] == O_MOVE && board[1][1] == O_MOVE && board[1][2] == O_MOVE){
	
	playerTwoVictory = true;
	
      }
      
      else if(board[2][0] == O_MOVE && board[2][1] == O_MOVE && board[2][2] == O_MOVE){
	
	playerTwoVictory = true;
	
      }
      
      else if(board[0][0] == O_MOVE && board[1][0] == O_MOVE && board[2][0] == O_MOVE){
	
	playerTwoVictory = true;
	
      }
      
      else if(board[0][1] == O_MOVE && board[1][1] == O_MOVE && board[2][1] == O_MOVE){
	
	playerTwoVictory = true;
	
      }
      
      else if(board[0][2] == O_MOVE && board[1][2] == O_MOVE && board[2][2] == O_MOVE){
	
	playerTwoVictory = true;
	
      }
      
      else if(board[0][0] == O_MOVE && board[1][1] == O_MOVE && board[2][2] == O_MOVE){
	
	playerTwoVictory = true;
	
      }
      
      else if (board[0][2] == O_MOVE && board[1][1] == O_MOVE && board[2][0] == O_MOVE){

	playerTwoVictory = true;

      }
      
      //Victory text
      if (playerOneVictory) {
	cout << "X has won. Don\'t tell O this, but you are my favorite." << endl;
	x_wins++;

	//Print the board
	cout << "Winning board:" << endl;
	cout << "  a b c" << endl;
	for (int x = 0; x < 3; x++) {

	  char output[3];
	  output[0] = (char)32;
	  output[1] = (char)32;
	  output[2] = (char)32;

	  cout << x + 1 << ' ';
	  for (int y = 0; y < 3; y++) {
	    if (board[x][y] == BLANK) {
	      output[y] = (char)32;
	    }
	    if (board[x][y] == X_MOVE) {
	      output[y] = 'X';
	    }
	    if (board[x][y] == O_MOVE) {
	      output[y] = 'O';
	    }
	  }
	  cout << output[0] << " " << output[1] << " " << output[2] << endl;
	}

      }
      
      else if (playerTwoVictory) {
	cout << "O has won. Good job, O." << endl;
	o_wins++;

	//Print the board
	cout << "Winning board:" << endl;
	cout << "  a b c" << endl;
	for (int x = 0; x < 3; x++) {

	  char output[3];
	  output[0] = (char)32;
	  output[1] = (char)32;
	  output[2] = (char)32;

	  cout << x + 1 << ' ';
	  for (int y = 0; y < 3; y++) {
	    if (board[x][y] == BLANK) {
	      output[y] = (char)32;
	    }
	    if (board[x][y] == X_MOVE) {
	      output[y] = 'X';
	    }
	    if (board[x][y] == O_MOVE) {
	      output[y] = 'O';
	    }
	  }
	  cout << output[0] << " " << output[1] << " " << output[2] << endl;
	}

      }
      
      else if (turnCount >= 9) {
	cout << "It's a tie." << endl;
	ties++;
      }

    }

  }
  
}
