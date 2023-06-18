#include "Camel.h"

Camel::Camel() : Camel("Верблюд", 10,30){}

int Camel::finish(const int distance)
{
	int time = distance / (transport_speed); // Время без остановок
	return time + relax(distance, time); // Время с остановками
}

Camel::Camel(std::string name, int speed, int duration) : Earth_transport(name, speed, duration) {}

int Camel::relax(const int distance, const int time)
{
	int relax_time = 0;
	int stops = time / transport_duration;
	int count = (stops == 0) ? 1 :
		(stops < 0 && stops <= 1) ? 2 :
		(stops >= 2) ? 3 :
		(distance >= 10000) ? 4 :
		5;
	switch (count)
	{
	case 1: relax_time = 0; // Если не было отдыха
		break;
	case 2: relax_time = 5; // Если отдых был 1 раз
		break;
	case 3: relax_time = (stops - 1) * 8 - 5; // Все последующие разы
		break;
	}
	return relax_time;

}
