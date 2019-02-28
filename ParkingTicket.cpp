/*
---------------------------------------------------
Name: ParkingTicket.cpp
Date: February 23, 2019
Author: Shraddha Piparia (shraddhapiparia@my.unt.edu)
Description: This is an implementation file for class ParkingTicket which assigns ticket and calculates fare for a vehicle.
---------------------------------------------------
*/
#include "header.h"
#include "Vehicle.cpp"
map<int, Vehicle*> active_tickets;

class ParkingTicket{
    public :

	/*
	 ============================================================================
	 Function    : assignTicket
	 Parameters  : ticket list , ticket ID , Vehicle license number and Vehicle type
	 Return      : nothing
	 Description : This function assigns a ticket to parked vehicle
	 ============================================================================
	 */
	void assignTicket(int id, string lic_num, int type)
	{	
		Vehicle* vehicle = active_tickets[id];
		vehicle->setStartTime(std::chrono::system_clock::now());
				
	}
	/*
	 ============================================================================
	 Function    : calculateFare
	 Parameters  : ticket list and ticket ID
	 Return      : fare
	 Description : This function calculates the fare when user wants to exit the lot.
	 ============================================================================
	 */
	float calculateFare(int id)
	{
		auto end = std::chrono::system_clock::now();
		Vehicle* vehicle = active_tickets[id];
		std::chrono::duration<double, std::milli> diff = end - (vehicle->getStartTime());
		int mins = (int)(diff.count())/60000.0;
		cout<<"The vehicle "<<active_tickets[id]->lic_num <<" was parked for " <<mins<<" mins."<<endl;
		float f = (float)mins*(vehicle->getRate()) < 0 ? 1: (float)mins*(vehicle->getRate());
		return f;

	}

};

