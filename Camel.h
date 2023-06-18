#pragma once
#include "Earth_transport.h"

class Camel : protected Earth_transport
{
public:
	Camel();

	int finish(const int distance) override;

protected:
	Camel(std::string name, int speed, int duration);

	int relax(const int distance, const int time);
};