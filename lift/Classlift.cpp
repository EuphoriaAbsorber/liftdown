
#include <iostream>
#include "lift.h"
using namespace std;

lift::lift()
{
	m_cap = 0;// �����������
	m_time = 0; // ����� ����� ������
	m_floor = 1; // �� ����� �� �����
}

/*
lift::lift(const lift& rv)
{
	m_cap = 0;// �����������
	m_time = 0; // ����� ����� ������
	m_floor = 1; // �� ����� �� �����
	//copy(rv);
}

void lift::init()
{
	m_cap = 0;// �����������
	m_time = 0; // ����� ����� ������
	m_floor = 1; // �� ����� �� �����
}
*/


void lift::gotofloor(int n) {
	m_time += (n - m_floor) * 10;
	m_floor = n;
}

long long lift::get_time() {
	return m_time;
}