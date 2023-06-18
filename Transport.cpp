#include "Transport.h"

Transport::Transport()
{
	transport_name = "unknow";
	transport_type = "unknow";
	transport_speed = 0;
}

Transport::Transport(std::string name, std::string type, int speed)
{
	transport_name = name;
	transport_type = type;
	transport_speed = speed;
};
