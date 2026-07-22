#include "Address.h"

Address::Address(std::string country, std::string city) 
	: _country(country), _city(city)
{
}

std::string Address::getCountry()
{
	return _country; 
}

std::string Address::getCity()
{
	return _city;
}
