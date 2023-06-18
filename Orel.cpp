#include "Orel.h"

Orel::Orel() : Orel ("����", 8){}

double Orel::finish(const int distance)
{
	return sokrashenie(distance) / transport_speed;
}

Orel::Orel(const std::string &name, int speed) : Air_transport(name, speed){}

double Orel::sokrashenie(int distance)
{
	return distance * 0.94; // 	������ 6%
}