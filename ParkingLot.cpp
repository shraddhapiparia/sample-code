/*
---------------------------------------------------
Name: ParkingLot.cpp
Date: February 23, 2019
Author: Shraddha Piparia (shraddhapiparia@my.unt.edu)
Description: This is an implementation file for singleton class Parking lot.
---------------------------------------------------
*/
#include "ParkingBoard.cpp"
#include "ParkingTicket.cpp"

class ParkingLot{
	static ParkingLot* p_lot;
	static bool instanceFlag;
    private:
	ParkingLot(){
	}    
    public :
	~ParkingLot() { instanceFlag = false; }
	static ParkingLot* getInstance();
	string name, address;
	int t_id[ROW_SIZE][COL_SIZE],i,j,count=1,val;
	
	ParkingBoard pBoard;
	ParkingTicket pTicket;
	VehicleType vehicleType;
	
	/*
	 ============================================================================
	 Function    : initializeBoard
	 Parameters  : parking board
	 Return      : nothing
	 Description : This function initialized parking lot with all spots as available
	 ============================================================================
	 */
	void initializeBoard(StatusArrayPtr *board)
	{
		for (i=0; i < ROW_SIZE; i++)
		{
			for (j=0; j < COL_SIZE; j++)
			{
				board[i][j] = AVL;
				t_id[i][j] = count++;
			}
		}
	}
	/*
	 ============================================================================
	 Function    : initializeBoardType
	 Parameters  : parking board type
	 Return      : nothing
	 Description : This function initializes parking space as large, compact, 
		       handicap or regular
	 ============================================================================
	 */
	void initializeBoardType(ParkingSpaceArrayPtr *board_type)
	{
		for (j=0; j < COL_SIZE; j++)
		{
			board_type[0][j] = LARGE;
			board_type[1][j] = HANDICAP;
			board_type[2][j] = COMPACT;
		}
		for (int i=3; i < ROW_SIZE; i++)
		{
			for (j=0; j < COL_SIZE; j++)
			{
				board_type[i][j] = REGULAR;
			}
		}
	}

	/*
	 ============================================================================
	 Function    : isAvailable
	 Parameters  : parking board and Vehicle type
	 Return      : ticket ID
	 Description : This function checks whether there is empty slot in parking lot
	 ============================================================================
	 */
	int isAvailable(StatusArrayPtr *board, int type, Vehicle* vehicle, int id)
	{
		id = 0;
		switch(type)
		{
		    case MOTORCYCLE:
			for (j=0; j < COL_SIZE; j++)
			{
				if (board[2][j] == AVL)
				{
					id = t_id[2][j];
					active_tickets[id] = new Motorcycle();
					break;
				}
			}
			break;
		    case CAR:
			for (i=3; i < ROW_SIZE; i++)
			{
				for (j=0; j < COL_SIZE; j++)
				{
					if (board[i][j] == AVL)
					{
						id = t_id[i][j];
						active_tickets[id] = new Car();
						goto b1;
					}
				}
			}
			break;
		    case BUS:
			for (j=0; j < COL_SIZE; j++)
			{
				if (board[0][j] == AVL)
				{
					id = t_id[0][j];
					active_tickets[id] = new Bus();
					break;
				}
			}
			break;
		    case HANDICAPPED:
			for (j=0; j < COL_SIZE; j++)
			{
				if (board[1][j] == AVL)
				{
					id = t_id[1][j];
					active_tickets[id] = new Handicapped();
					break;
				}
			}
			break;
		    default:
			cout << "Invalid vehicle! \n";
		}
		b1:
		return id;	

	}

	/*
	 ============================================================================
	 Function    : reserveParkingSpace
	 Parameters  : ticket list , ticket ID , Vehicle license number and Vehicle type
	 Return      : nothing
	 Description : This function parks a vehicle and assigns a ticket.
	 ============================================================================
	 */
	void reserveParkingSpace(StatusArrayPtr *board, int id1, string lic_num, int t)
	{
		pTicket.assignTicket(id1, lic_num, t);
		pBoard.updateBoard(board, id1, false);
		return; 
	}

	/*
	 ============================================================================
	 Function    : releaseParkingSpace
	 Parameters  : parking board , ticket ID and ticket list  
	 Return      : fare
	 Description : This function removes a parked vehicle and fetches the fare amount
	 ============================================================================
	 */
	float releaseParkingSpace(StatusArrayPtr *board, int id1)
	{
		float total_fare = pTicket.calculateFare(id1);
		pBoard.updateBoard(board, id1, true);
		return total_fare;
	}

	/*
	 ============================================================================
	 Function    : displayBoard
	 Parameters  : parking board
	 Return      : nothing
	 Description : This function is designed to print parked vehicles
	 ============================================================================
	 */
	void displayBoard(StatusArrayPtr *updated_board){

		pBoard.displayBoard(updated_board);

	}
	/*
	 ============================================================================
	 Function    : findVehicle
	 Parameters  : ticket ID and ticket list
	 Return      : nothing
	 Description : This function find a parked vehicle
	 ============================================================================
	 */
	void findVehicle(int id1){
		if(id1){
			int t = active_tickets[id1]->type;
			string v_type = (t==1)? "Motorcycle" : (t==2) ? "Car" : (t==3) ? "Bus" : "Handicap";
			cout<<"---------------------------------------------------------"<<endl;
			cout << "Type of vehicle: " << v_type <<endl;
			cout << "License number of vehicle: " << active_tickets[id1]->lic_num <<endl;
			//cout << "Start time of vehicle: " << std::chrono::system_clock::to_time_t(active_tickets[id1]->start_time) <<endl;
			cout << "Vehicle is parked at row " << (id1-1)/COL_SIZE << " and column "<< (id1-1)%COL_SIZE <<".\n";
			cout<<"---------------------------------------------------------"<<endl;
		}
	}
};

