#pragma once
#include "Transport.h"

class Air_transport : protected Transport
{
public:
	Air_transport();

	virtual double finish(int distance);

protected:
	Air_transport(std::string name, int speed);

};