
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
	m_time += abs(n - m_floor) * 10;
	m_floor = n;
}

long long lift::get_time() {
	return m_time;
}

int lift::is_lift_free() {
	return 0;
}
/*
int lift::findlift(lift& a,int lift_count) {
	int ans;
	for (int i = 0; i < lift_count; i++) {
		if (!is_lift_free)
			continue;
	}
	return ans;
}
*/