#pragma once
#include "Air_transport.h"

class Metla : protected Air_transport
{
public: 
	Metla();

	double finish(const int distance) override;

protected:
	Metla(std::string name, int speed);

	double sokrachenie(const int distance);
};