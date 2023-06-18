#include "fast_Camel.h"

fast_Camel::fast_Camel() : fast_Camel("Верблюд-быстроход", 40, 10) {}

int fast_Camel::finish(const int distance)
{
	int time = distance / (transport_speed); // Время без остановок
	return time + relax(distance, time); // Время с остановками
}

fast_Camel::fast_Camel(const std::string &name, const int speed, const int duration) : Earth_transport(name, speed, duration) {}

int fast_Camel::relax(const int distance, const int time)
{
	int relax_time = 0;
	int stops = time / transport_duration;
	int count = (stops == 0) ? 1 :
		(stops == 1) ? 2 :
		(stops == 2) ? 3 :
		(stops > 2) ? 4 :
		5;
	switch (count)
	{
	case 1: relax_time = 0; // Если не было отдыха
		break;
	case 2: relax_time = 5; // Если отдых был 1 раз
		break;
	case 3: relax_time = 5 + 6.5; // Если отдых был 2 разa
		break;
	case 4: relax_time = (stops - 2) * 8 + 5 + 6.5; // Все последующие разы
	}
	return relax_time;

}