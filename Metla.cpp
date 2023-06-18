#include "Metla.h"

Metla::Metla() : Metla ("�����", 20){}

double Metla::finish(const int distance)
{
	return sokrachenie(distance) / transport_speed;
}

Metla::Metla(std::string name, int speed) : Air_transport(name, speed) {}

double Metla::sokrachenie(const int distance)
{
	return ((100 - floor(distance / 1000)) / 100) * distance; // ������������� �� 1% �� ������ 1000 �.�. ����������. ��������, ��� ���������� 5600 ����������� ����� 5 %
}
