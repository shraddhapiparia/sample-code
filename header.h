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
#include <ctime>
#include <typeinfo>

using namespace std;

const int ROW_SIZE = 6, COL_SIZE = 4;

enum VehicleType{MOTORCYCLE=1, CAR, BUS, HANDICAPPED};

enum ParkingSpaceType{COMPACT, REGULAR, LARGE, HANDICAP};
typedef ParkingSpaceType* ParkingSpaceArrayPtr;

enum Status{AVL, UNAVL};
typedef Status* StatusArrayPtr;
/*
struct Ticket
{
	int id;
	string lic_num;
	std::chrono::system_clock::time_point start_time;
	//time_point start_time;
	int type;
};
*/
#endif
