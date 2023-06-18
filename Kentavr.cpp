#include "Kentavr.h"

Kentavr::Kentavr() : Kentavr("Кентавр", 15, 8) {}

Kentavr::Kentavr(std::string name, int speed, int duration) : Earth_transport(name, speed, duration){}

int Kentavr::finish(const int distance)
{
	int time = distance / transport_speed;
	return time + relax(distance, time);
}

int Kentavr::relax(const int distance, const int time)
{
	int relax_time = 0;
	int stops = time / transport_duration;
	relax_time = stops * 2;
	return relax_time;
}