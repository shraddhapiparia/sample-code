#include "ParkingBoard.cpp"
#include "ParkingTicket.cpp"

class ParkingLot{
    /*private:
	static ParkingLot p_lot = NULL;
	static bool instanceFlag;
	ParkingLot()
	{
		// Private constructor, can be used to initialize values
	}
    public :
	~ParkingLot()
	{
		instanceFlag = false;
	}
	static ParkingLot getInstance()
	{
		if (!instanceFlag)
		{
			p_lot = new ParkingLot();
			instanceFlag = true;
		}
		return p_lot;
	}*/
    public:
	string name, address;
	int id[ROW_SIZE][COL_SIZE],i,j,count=1;
	map<int, Ticket> active_tickets;
	ParkingBoard pBoard;
	ParkingTicket pTicket;
	void initializeBoard(StatusArrayPtr *board)
	{
		for (i=0; i < ROW_SIZE; i++)
		{
			for (j=0; j < COL_SIZE; j++)
			{
				board[i][j] = A;
				id[i][j] = count++;
			}
		}
	}

	void initializeBoardType(ParkingSpaceArrayPtr *board_type)
	{
		for (j=0; j < COL_SIZE; j++)
		{
			board_type[0][j] = Large;
			board_type[1][j] = Handicapped;
			board_type[2][j] = Compact;
		}
		for (int i=3; i < ROW_SIZE; i++)
		{
			for (j=0; j < COL_SIZE; j++)
			{
				board_type[i][j] = Regular;
			}
		}
	}

	int isAvailable(StatusArrayPtr *board, string type)
	{
		int val = 0; //use switch case motocycle
		/*switch(type)
		{
		    case Motorcycle:
			for (j=0; j < COL_SIZE; j++)
			{
				if (board[2][j] == A)
					return id[2][j];
			}
			break;
		    case Car:
			for (i=3; i < ROW_SIZE; i++)
			{
				for (j=0; j < COL_SIZE; j++)
				{
					if (board[i][j] == A)
						return  id[i][j];
				}
			}
			break;
		    case Bus:
			for (j=0; j < COL_SIZE; j++)
			{
				if (board[0][j] == A)
					return id[0][j];
			}
			break;
		    case Handicapped:
			for (j=0; j < COL_SIZE; j++)
			{
				if (board[1][j] == A)
					return id[1][j];
			}
			break;
		    default:
			cout << "Invalid vehicle! \n";
		}	*/
		if (type == "Motorcycle")
		{
			for (j=0; j < COL_SIZE; j++)
			{
				if (board[2][j] == A)
					return id[2][j];
			}
		}	
		else if (type == "Car")
		{
			for (i=3; i < ROW_SIZE; i++)
			{
				for (j=0; j < COL_SIZE; j++)
				{
					if (board[i][j] == A)
						return  id[i][j];
				}
			}
		}	
		else if (type == "Bus")
		{
			for (j=0; j < COL_SIZE; j++)
			{
				if (board[0][j] == A)
					return id[0][j];
			}
			}	
		else if (type == "Handicapped")
		{
			for (j=0; j < COL_SIZE; j++)
			{
				if (board[1][j] == A)
					return id[1][j];
			}
		}else
			cout << "Invalid vehicle! \n";

	}
	void reserveParkingSpace(StatusArrayPtr *board, int id1, string lic_num, string type)
	{
		cout<<"\n ID received is : "<<id1<< endl;
		active_tickets = pTicket.assignTicket(active_tickets, id1, lic_num, type);
		cout<<" Back to reserve call update.\n";
		pBoard.updateBoard(board, id1, false);
	}
	float releaseParkingSpace(StatusArrayPtr *board, int id1)
	{
		float total_fare = pTicket.calculateFare(active_tickets,id1);
		pBoard.updateBoard(board, id1, true);
		return total_fare;
	}
	void displayBoard(StatusArrayPtr *updated_board){
		ParkingBoard pBoard;
		pBoard.displayBoard(updated_board);
	}
	void findVehicle(int id1){
		if(id1){
			cout << "Type of vehicle: " << active_tickets[id1].type <<endl;
			cout << "License number of vehicle: " << active_tickets[id1].lic_num <<endl;
			//cout << "Start time of vehicle: " << active_tickets[id1].start_time.str() <<endl;
			cout << "Vehicle is parked at row " << (id1-1)/4 << " and column "<< (id1-1)%4 <<".\n";
		}		
	}
};
