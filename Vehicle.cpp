#include "header.h"
//Vehicle class implements virtual functions getRate and getSize
class Vehicle{
    public:
	string lic_num;
	int type;
	std::chrono::system_clock::time_point start_time;

	virtual float getRate() = 0;
	virtual int getSize() = 0;

	string getLicenseNumber(){ return lic_num; }
	std::chrono::system_clock::time_point getStartTime(){ return start_time; }

	void setLicenseNumber(string s){ lic_num = s; }
	void setStartTime(std::chrono::system_clock::time_point st){ start_time = st; }

};

class Motorcycle : public Vehicle{
	private:
		ParkingSpaceType size = COMPACT;
		float rate = 0.75;
	public:
	float getRate(){
		return rate;
	}
	int getSize(){
		return size;
	}

};

class Car : public Vehicle{
	private:
		ParkingSpaceType size = REGULAR;
		float rate = 1.75;
	public:
	float getRate(){
		return rate;
	}
	int getSize(){
		return size;
	}

};

class Bus : public Vehicle{
	private:
		ParkingSpaceType size = LARGE;
		float rate = 2.5;
	public:
	float getRate(){
		return rate;
	}
	int getSize(){
		return size;
	}

};

class Handicapped : public Vehicle{
	private:
		ParkingSpaceType size = HANDICAP;
		float rate = 2.5;
	public:
	float getRate(){
		return rate;
	}
	int getSize(){
		return size;
	}


};
