#pragma once
#include "Earth_transport.h"

class Kentavr : protected Earth_transport
{
public:
	Kentavr();

	int finish(const int distance) override;

protected:
	Kentavr(std::string name, int speed, int duration);

	int relax(const int distance, const int time);
};