#include "Metla.h"

Metla::Metla() : Metla ("Метла", 20){}

double Metla::finish(const int distance)
{
	return sokrachenie(distance) / transport_speed;
}

Metla::Metla(std::string name, int speed) : Air_transport(name, speed) {}

double Metla::sokrachenie(const int distance)
{
	return ((100 - floor(distance / 1000)) / 100) * distance; // Увеличивается на 1% за каждую 1000 у.е. расстояния. Например, для расстояния 5600 коэффициент будет 5 %
}
