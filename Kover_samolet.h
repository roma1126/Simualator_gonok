#pragma once
#include "Air_transport.h"

class Kover_samolet : protected Air_transport
{
public:
	Kover_samolet();

	double finish(const int distance) override;

protected:
	Kover_samolet(std::string name, int speed);

	double sokrashenie(const int distance);
};