#pragma once
#include "Air_transport.h"

class Orel : protected Air_transport
{
public:
	Orel();

	double finish(const int distance) override;

protected:
	Orel(const std::string& name, int speed);

	double sokrashenie(const int distance);
};
