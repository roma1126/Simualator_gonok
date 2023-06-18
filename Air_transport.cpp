#include "Air_transport.h"

Air_transport::Air_transport()
{
	transport_name = "unknow";
	transport_type = "Air";
	transport_speed = 0;
}

double Air_transport::finish(int distance)
{
	return 0;
}

Air_transport::Air_transport(std::string name, int speed)
{
	transport_name = name;
	transport_type = "Air";
	transport_speed = speed;
};
