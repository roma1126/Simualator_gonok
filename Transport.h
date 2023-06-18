#pragma once
#include <string>
class Transport
{
public:
	Transport();

protected:
	std::string transport_name;
	std::string transport_type;
	int transport_speed;

	Transport(std::string name, std::string type, int speed);
};