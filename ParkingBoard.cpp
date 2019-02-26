#include "header.h"

class ParkingBoard{
public:
 void displayBoard(StatusArrayPtr *board){
	cout << "    0 1 2 3 " << endl;
	cout << "  +----------+" << endl;

	for (int row = 0; row < ROW_SIZE; row++)
	{
		cout << " " << row << "|";

		for (int col = 0; col < COL_SIZE; col++)
		{
			cout << " " << board[row][col];
		}

		cout << " |" << endl;
	}

	cout << "  +----------+" << endl;
}

void updateBoard(StatusArrayPtr *board,int id, bool avail){
	cout << "Update board\n";
	int row = (id - 1)/ COL_SIZE;
	int col = (id - 1) % COL_SIZE;
	cout<< " \n row: "<<row<<" col: "<< col<< endl;
	if (avail == false)
		board[row][col] = U;
	else
		board[row][col] = A;
	displayBoard(board);
}
};
