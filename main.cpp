
#include "ParkingLot.cpp"
int main()
{
	StatusArrayPtr *updated_board = new StatusArrayPtr[ROW_SIZE];
	ParkingSpaceArrayPtr *board_type = new ParkingSpaceArrayPtr[ROW_SIZE];
	for(int i=0;i<ROW_SIZE;i++)
	{
		updated_board[i] = new Status[COL_SIZE];
		board_type[i] = new ParkingSpaceType[COL_SIZE];
	}
	int oper, ticket_num, id;
	string vType,license_num;
	ParkingLot lot;
	//VehicleType vType;
	//lot = lot.getInstance();
	lot.initializeBoard(updated_board);
	lot.initializeBoardType(board_type);
	while(1){
		cout << "Enter the operation to be performed:\n";
		cout << " 1. Park \n 2. Unpark \n 3. Display Parking Lot \n 4. Find a vehicle \n 5. Quit \n"; //TODO: reset 
		cin >> oper;
		if (oper == 1)
		{
			cout << "\n Enter the type of vehicle: Motorcycle/Car/Bus/Handicapped \n";
			cin >> vType;
			cout << "Enter the license of the vehicle \n";
			cin >> license_num;
			id = lot.isAvailable(updated_board, vType);
			if (id)
			{
				lot.reserveParkingSpace(updated_board, id, license_num, vType);
				cout <<"Reserved successfully ticket ID is " << id <<"\n";
				lot.displayBoard(updated_board);
			}else{
				cout <<"Sorry parking for " << vType << " is full! Please come back later.";
			//	break;
			}
		}else if(oper == 2){
			cout << "Enter ticket ID \n";
			cin >> id;
			lot.releaseParkingSpace(updated_board, id);
			cout<< "Successfully unparked. Updated parking lot is: \n";
			lot.displayBoard(updated_board);

		}else if(oper == 3){

			lot.displayBoard(updated_board);

		}else if(oper == 4){

			cout << "Enter ticket ID: \n";
			cin >> id;
			lot.findVehicle(id);

		}else if(oper == 5){
			exit(EXIT_FAILURE);
		}else{
			cout<< "Invalid operation!!! Please enter correct options and try again...";
		}
	}
	return 0;
}

