
#include <iostream>
#include "lift.h"
using namespace std;

lift::lift()
{
	m_cap = 0;// вместимость
	m_time = 0; // общее врем€ работы
	m_floor = 1; // на каком ща этаже
}

/*
lift::lift(const lift& rv)
{
	m_cap = 0;// вместимость
	m_time = 0; // общее врем€ работы
	m_floor = 1; // на каком ща этаже
	//copy(rv);
}

void lift::init()
{
	m_cap = 0;// вместимость
	m_time = 0; // общее врем€ работы
	m_floor = 1; // на каком ща этаже
}
*/


void lift::gotofloor(int n) {
	m_time += (n - m_floor) * 10;
	m_floor = n;
}

long long lift::get_time() {
	return m_time;
}