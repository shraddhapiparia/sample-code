/*
---------------------------------------------------
Name: main.cpp
Date: February 23, 2019
Author: Shraddha Piparia (shraddhapiparia@my.unt.edu)
Description: This is the implemention file for the main function of parking lot
---------------------------------------------------
*/

#include "ParkingLot.cpp"
bool ParkingLot::instanceFlag = false;
ParkingLot* ParkingLot::p_lot = 0;
ParkingLot* ParkingLot::getInstance()
	{
		if (!instanceFlag )
		{
			p_lot = new ParkingLot();
			instanceFlag = true;
		}
		return p_lot;
	}

int main()
{
	int oper, id=0, v_type;
	string license_num, veh_type;
	Vehicle* vehicle = 0;
	
	// Create a Parking lot and Parking space type.
	StatusArrayPtr *updated_board = new StatusArrayPtr[ROW_SIZE];
	ParkingSpaceArrayPtr *board_type = new ParkingSpaceArrayPtr[ROW_SIZE];
	for(int i=0;i<ROW_SIZE;i++)
	{
		updated_board[i] = new Status[COL_SIZE];
		board_type[i] = new ParkingSpaceType[COL_SIZE];
	}
	
	//Initialize all parking space in parking lot as available. Initialize parking space type as large, compact, regular and handicapped.
	ParkingLot::getInstance()->initializeBoard(updated_board);
	ParkingLot::getInstance()->initializeBoardType(board_type);

	// Print the menu until user quits.
	while(1){
		cout << "\n Enter the operation to be performed:\n";
		cout << " 1. Park \n 2. Unpark \n 3. Display Parking Lot \n 4. Find a vehicle \n 5. Quit \n"; //TODO: reset 
		cin >> oper;
		if (oper == 1)
		{
			cout << "\n Enter the type of vehicle: \n 1. Motorcycle \n 2. Car \n 3. Bus \n 4. Handicapped \n";
			cin >> v_type;
			if(v_type >=1 && v_type <= 4)
			{ 
				id = ParkingLot::getInstance()->isAvailable(updated_board, v_type, vehicle, id);
				if (id)
				{
					cout << "Enter the license of the vehicle: ";
					cin >> license_num;
					vehicle = active_tickets[id];
					vehicle-> setLicenseNumber(license_num);
					vehicle-> setStartTime(std::chrono::system_clock::now());
					ParkingLot::getInstance()->reserveParkingSpace(updated_board, id, license_num, v_type);
					cout <<"Reserved successfully ticket ID is \033[1;35m" << id <<"\033[0m\n";
					ParkingLot::getInstance()->displayBoard(updated_board);
				}else{
					veh_type = (v_type) == 1? "Motorcycle":(v_type==2)?"Car":(v_type==3)?"Bus":"Handicapped";
					cout <<"Sorry parking for " << veh_type << " is full! Please come back later. \n";
				}
			}else
				cout<< "Please choose correct vehicle type and try again.\n";
		}else if(oper == 2){
			cout << "Enter ticket ID \n";
			cin >> id;
			if(updated_board[(id-1)/COL_SIZE][(id-1)%COL_SIZE] == UNAVL)
			{
				int fare = ParkingLot::getInstance()->releaseParkingSpace(updated_board, id);
				cout<< "Successfully unparked. Total fare is: $" <<fare<<endl;
				ParkingLot::getInstance()->displayBoard(updated_board);
			}else
				cout<<"Invalid ID! Please try again..."<<endl;
		}else if(oper == 3){

			ParkingLot::getInstance()->displayBoard(updated_board);

		}else if(oper == 4){

			cout << "Enter ticket ID: \n";
			cin >> id;
			if (updated_board[(id-1)/COL_SIZE][(id-1)%COL_SIZE] == UNAVL)
				ParkingLot::getInstance()->findVehicle(id);
			else
				cout<<"Invalid ticket ID! Please enter correct ID..."<<endl;

		}else if(oper == 5){
			exit(EXIT_FAILURE);
		}else{
			cout<< "Invalid operation!!! Please enter correct options and try again...\n";
		}
	}
	return 0;
}

