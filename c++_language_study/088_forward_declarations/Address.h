#pragma once

#include <string>

class Address {
public:
	Address(std::string country, std::string city);
	std::string getCountry();
	std::string getCity();
private:
	std::string _country;
	std::string _city;
};