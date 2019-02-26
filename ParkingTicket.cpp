#include "header.h"

class ParkingTicket{
    public :
	Ticket ticket;
	map<int, Ticket> assignTicket(map<int, Ticket> &tlist, int id, string lic_num, string type)
	{
		cout<<" Inside Assign Ticket.";
		Ticket t;
		t.start_time = std::chrono::system_clock::now(); 
		t.id = id;
		t.lic_num = lic_num;
		t.type = type;
		tlist[id] = t;
		cout<<" Done Assign Ticket.";
	}
	float calculateFare(map<int, Ticket> &tlist, int id)
	{
		auto end = std::chrono::system_clock::now();
		auto start = tlist[id].start_time;
		string type = tlist[id].type;
		float rpm = 0;
		if(type == "Motorcycle")
			rpm = 0.75;
		else if (type == "Car")
			rpm = 1.75;
		else if (type == "Handicapped")
			rpm = 1.50;
		else
			rpm = 2.50;
		std::chrono::duration<double> diff = end - start;
		int mins = (int)(diff.count())/60.0;
		return mins*rpm;
	}

};

