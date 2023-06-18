#pragma once
#include "Earth_transport.h"

class fast_Camel : protected Earth_transport
{
public:
	fast_Camel();

	int finish(const int distance) override;

protected:
	fast_Camel(const std::string& name, const int speed, const int duration);

	int relax(const int distance, const int time);
};
