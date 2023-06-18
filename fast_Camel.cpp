#include "fast_Camel.h"

fast_Camel::fast_Camel() : fast_Camel("�������-���������", 40, 10) {}

int fast_Camel::finish(const int distance)
{
	int time = distance / (transport_speed); // ����� ��� ���������
	return time + relax(distance, time); // ����� � �����������
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
	case 1: relax_time = 0; // ���� �� ���� ������
		break;
	case 2: relax_time = 5; // ���� ����� ��� 1 ���
		break;
	case 3: relax_time = 5 + 6.5; // ���� ����� ��� 2 ���a
		break;
	case 4: relax_time = (stops - 2) * 8 + 5 + 6.5; // ��� ����������� ����
	}
	return relax_time;

}