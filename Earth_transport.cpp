#include "Earth_transport.h"

Earth_transport::Earth_transport()
{
	transport_name = "unknow";
	transport_type = "Earth";
	transport_speed = 0;
	transport_duration = 0;
}

Earth_transport::Earth_transport(std::string name, int speed, int duration) : Transport("Earth", name, speed)
{
	transport_duration = duration;
}

int Earth_transport::finish(const int distance)
{
	return 0;
}