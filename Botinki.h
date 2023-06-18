#pragma once
#include "Earth_transport.h"

class Botinki : protected Earth_transport
{
public:
	Botinki();

	int finish(const int distance) override;

protected:
	Botinki(const std::string& name, const int speed, const int duration);

	int relax(const int distance, const int time);
};