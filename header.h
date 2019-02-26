/*
---------------------------------------------------
Name: header.h
Date: February 23, 2019
Author: Shraddha Piparia (shraddhapiparia@my.unt.edu)
Description: Sets up parking lot
---------------------------------------------------
*/
#ifndef MAIN_HEADER_H_
#define MAIN_HEADER_H_

#include <iostream>
#include <vector>
#include <chrono>
#include <map>

using namespace std;

const int ROW_SIZE = 6, COL_SIZE = 4;

enum VehicleType{Motorcycle, Car, Bus, H};

enum ParkingSpaceType{Large, Compact, Handicapped, Regular};
typedef ParkingSpaceType* ParkingSpaceArrayPtr;

enum Status{A, U};
typedef Status* StatusArrayPtr;

struct Ticket
{
	int id;
	string lic_num;
	std::chrono::system_clock::time_point start_time = std::chrono::system_clock::now();
	string type;
};

#endif
/*
class ParkingBoard{};
class Vehicle{};
class ParkingTicket{};
class ParkingLot{};
/*	public:
	StatusArrayPtr initializeBoard();
	ParkingSpaceArrayPtr initializeBoardType();
	int isAvailable(string);
	StatusArrayPtr reserveParkingSpace(StatusArrayPtr *board, int);
	StatusArrayPtr releaseParkingSpace(StatusArrayPtr *board, int);
	void displayBoard(StatusArrayPtr *board);
	void findVehicle(StatusArrayPtr *board, int);
};
*/
