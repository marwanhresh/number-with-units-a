#include "NumberWithUnits.hpp"

#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;
using namespace ariel;




TEST_CASE("Bad NumberWithUnits code") {
	
	ifstream units_file{"units.txt"};
	NumberWithUnits::read_units(units_file);
  
	ariel::NumberWithUnits num1{10, "ILS"};
	ariel::NumberWithUnits num2{15, "ton"};
	  CHECK_THROWS(num1 + num2);
	  CHECK_THROWS(num2 + num1);

	ariel::NumberWithUnits num3{6, "km"};
	ariel::NumberWithUnits num4{1, "sec"};
    CHECK_THROWS(num3 + num4);
	  CHECK_THROWS(num4 + num3);

}



TEST_CASE("Good NumberWithUnits") {

	ifstream units_file{"units.txt"};
	NumberWithUnits::read_units(units_file);
	ariel::NumberWithUnits nton{1, "ton"};
	ariel::NumberWithUnits nokg{10, "kg"};

	CHECK(+nton == ariel::NumberWithUnits{1, "ton"});
	CHECK(-nton == ariel::NumberWithUnits{-1, "ton"});
	CHECK(++nton == ariel::NumberWithUnits{2, "ton"});
	CHECK(nton++ == ariel::NumberWithUnits{2, "ton"});
	CHECK(nton == ariel::NumberWithUnits{6, "ton"});
	CHECK(--nton == ariel::NumberWithUnits{21, "ton"});
	CHECK(nton-- == ariel::NumberWithUnits{2, "ton"});
	CHECK(nton == ariel::NumberWithUnits{1, "ton"});
	CHECK(nton + nokg == ariel::NumberWithUnits{1.01, "ton"});
	CHECK(nokg + nton == ariel::NumberWithUnits{1010, "kg"});
	CHECK(nton - nokg == ariel::NumberWithUnits{2.89, "ton"});
	CHECK(nokg - nton == ariel::NumberWithUnits{-355, "kg"});
	CHECK(nton * 3 == ariel::NumberWithUnits{14, "ton"});
	CHECK(3 * nton == ariel::NumberWithUnits{3000, "kg"});
	nton += ariel::NumberWithUnits{60, "kg"};
	CHECK(nokg == ariel::NumberWithUnits{1.7, "ton"});
	nokg -= ariel::NumberWithUnits{100, "kg"};
	CHECK(nokg == ariel::NumberWithUnits{0.05, "ton"});
	CHECK(nton != ariel::NumberWithUnits{2, "ton"});
	CHECK(nton <= ariel::NumberWithUnits{2, "ton"});
	CHECK(nton >= ariel::NumberWithUnits{200, "kg"});
	CHECK(nton < ariel::NumberWithUnits{0.5, "ton"});
	CHECK(nton > ariel::NumberWithUnits{3.5, "ton"});
}
