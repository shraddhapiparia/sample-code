#define CATCH_CONFIG_MAIN
#include "../main.cpp"
#include "catch.hpp"

TEST_CASE("Vehicle parked at first available position","[isAvailable]"){
	REQUIRE(isAvailable(board,4,vehicle,0)==5);
	REQUIRE(isAvailable(board,1,vehicle,0)==9);
	REQUIRE(isAvailable(board,2,vehicle,0)==13);
	REQUIRE(isAvailable(board,3,vehicle,0)==1);
}
