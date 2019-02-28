/*
---------------------------------------------------
Name: ParkingBoard.cpp
Date: February 23, 2019
Author: Shraddha Piparia (shraddhapiparia@my.unt.edu)
Description: This is an implementation file for class ParkingBoard which contains functions to print and update the parking lot.
---------------------------------------------------
*/

#include "header.h"
class ParkingBoard{
public:
/*
 ============================================================================
 Function    : displayBoard
 Parameters  : parking board
 Return      : nothing
 Description : This function prints out the parking board
 ============================================================================
 */
 void displayBoard(StatusArrayPtr *board){
	cout << "    0 1 2 3 " << endl;
	cout << "  +----------+" << endl;

	for (int row = 0; row < ROW_SIZE; row++)
	{
		cout << " " << row << "|";

		for (int col = 0; col < COL_SIZE; col++)
		{
			if (board[row][col] == AVL)
				cout << " " << "\033[1;32m" << board[row][col] <<"\033[0m";
			else
				cout << " " << "\033[1;31m" << board[row][col] <<"\033[0m";
		}

		cout << " |" << endl;
	}

	cout << "  +----------+" << endl;
}
/*
 ============================================================================
 Function    : updateBoard
 Parameters  : parking board, ticket ID and park/unpark information
 Return      : nothing
 Description : This function updates the board and sets spaces as available/unavailable
 ============================================================================
 */
void updateBoard(StatusArrayPtr *board,int id, bool avail){
	if(id){
		int row = (id - 1)/COL_SIZE;
		int col = (id - 1)%COL_SIZE;
		if (avail == false)
			board[row][col] = UNAVL;
		else
			board[row][col] = AVL;
	}else
		cout<< "Invalid id!\n";
	
}
};
