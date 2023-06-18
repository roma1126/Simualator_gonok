#include "Botinki.h"

Botinki::Botinki() : Botinki("�������-���������", 6, 60){}

Botinki::Botinki(const std::string &name, const int speed, const int duration) : Earth_transport(name, speed, duration){}

int Botinki::finish(const int distance)
{
	int time = distance / (transport_speed); // ����� ��� ���������
	return time + relax(distance, time); // ����� � �����������
}

int Botinki::relax(const int distance, const int time)
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
	case 1: relax_time = 0; // ���� �� ���� ������
		break;
	case 2: relax_time = 10; // ���� ����� ��� 1 ���
		break;
	case 3: relax_time = (stops - 1) * 5 + 10; // ��� ����������� ����
		break;
	}
	return relax_time;
}