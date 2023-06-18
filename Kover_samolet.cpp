#include "Kover_samolet.h"

Kover_samolet::Kover_samolet() : Kover_samolet("Ковер-самолет", 10){}

double Kover_samolet::finish(const int distance)
{
	return sokrashenie(distance) / transport_speed;
}

Kover_samolet::Kover_samolet(std::string name, int speed) : Air_transport(name, speed){}

double Kover_samolet::sokrashenie(const int distance)
{
	double less_distance = 0;
	int less = (distance < 1000 && distance > 0) ? 1 :
		(distance < 5000 && distance >= 1000) ? 2 :
		(distance >= 5000 && distance < 10000) ? 3 :
		(distance >= 10000) ? 4 :
		5;
	switch (less)
	{
	case 1: less_distance = 1; // Если расстояние < 1000
		break;
	case 2: less_distance = 0.97; // Если расстояние < 5000
		break;
	case 3: less_distance = 0.90; // Если расстояние > 5000, но < 10000
		break;
	case 4: less_distance = 0.95; // Eсли расстояние > 10000
		break;
	}
	return distance * less_distance;

}


