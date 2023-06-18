#pragma once
#include "Transport.h"

class Earth_transport : protected Transport
{
public: 
	Earth_transport();

	virtual int finish(const int distance);

protected:
	Earth_transport(std::string name, int speed, int duration);

	int transport_duration;
};