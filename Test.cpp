#include <cmath>
#include "doctest.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
using namespace std; 
using namespace pandemic;



/*
* this func create a random units file
*/

TEST_CASE("initialize board")
{
	Board b = Board();
	CHECK(b.is_clean());
	b[City::Algiers] = 1;
	CHECK_FALSE(b.is_clean());
}
// 2
TEST_CASE("initialize board")
{
	Board bD = Board();
	Board& b = bD;
	Dispatcher dp = Dispatcher(b, City::Atlanta);
	CHECK_THROWS(dp.drive(City::MexicoCity)); // he's in Atlanta, Atlanta and MexicoCity are not connected
	CHECK_THROWS(dp.build()); // he's in Atlanta and don't have Atlanta card

	dp.take_card(City::Atlanta);
	try
	{
		dp.build();
		CHECK(true); // to know we didn't throw
	}
	catch(const std::exception& e)
	{
		CHECK(false);
	}
	
	
	try
	{
		dp.drive(City::Bangkok);
		CHECK(true); // to know we didn't throw
	}
	catch(const std::exception& e)
	{
		CHECK(false);
	}
	// so far the dp should be in Bankok because from a search station he should fky to wherever he wants


	try
	{
		dp.drive(City::Chennai);
		CHECK(true); // to know we didn't throw
	}
	catch(const std::exception& e)
	{
		CHECK(false);
	}
	// so far the dp should be in Chennai

	dp.take_card(City::Chicago);
	dp.drive(City::Chicago);
	CHECK_THROWS(dp.drive(City::Chennai));
	// dp threw his Chennai card when he flied so now he don't have the card

// (6)
	dp.drive(City::MexicoCity);
	CHECK_THROWS(dp.drive(City::Atlanta));
	// he should fly from a city with search station to wherever he want but not the other way around

// (7)
	OperationsExpert oep = OperationsExpert(b, City::HongKong);
	try
	{
		oep.build();
		CHECK(true); // he can build without the card of the city
	}
	catch(const std::exception& e)
	{
		CHECK(false);
	}

// (8)
	Scientist sp = Scientist(b, City::Algiers, 2);
	CHECK_THROWS(sp.discover_cure(Color::Black));
// (9)
	sp.take_card(City::Algiers);
	CHECK_THROWS(sp.discover_cure(Color::Black));
//(10)	
	sp.take_card(City::Cairo);
	try
	{
		CHECK_THROWS(sp.discover_cure(Color::Black));
		CHECK(true); // he can build without the card of the city
	}
	catch(const std::exception& e)
	{
		CHECK(false);
	}

	CHECK_THROWS(sp.discover_cure(Color::Black));
// (11)
	CHECK_THROWS(oep.discover_cure(Color::Red));
	oep.take_card(City::HongKong);
//(12)
	CHECK_THROWS(oep.discover_cure(Color::Red));	
	sp.take_card(City::Beijing);
//(13)
	CHECK_THROWS(oep.discover_cure(Color::Red));
	oep.take_card(City::HoChiMinhCity);
//(14)
	CHECK_THROWS(oep.discover_cure(Color::Red));	
	sp.take_card(City::Jakarta);
//(15)
	CHECK_THROWS(oep.discover_cure(Color::Red));
	sp.take_card(City::Seoul);
// (16)
	CHECK_THROWS(oep.discover_cure(Color::Black));
//(17)
	CHECK_THROWS(oep.discover_cure(Color::Yellow));
//(18)
	CHECK_THROWS(oep.discover_cure(Color::Blue));
//(19)
	try
	{
		oep.discover_cure(Color::Red);
		CHECK(true); // he can build without the card of the city
	}
	catch(const std::exception& e)
	{
		CHECK(false);
	}

	Scientist finalSp = Scientist(b, City::Algiers, 0);
	finalSp.discover_cure(Color::Black);
	finalSp.discover_cure(Color::Blue);
	finalSp.discover_cure(Color::Yellow);
	CHECK(b.is_clean());
		

}
