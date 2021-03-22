
#include <iostream>
#include "lift.h"
#include <vector>
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
	m_time += abs(n - m_floor) * 10;
	m_floor = n;
}

long long lift::get_time() {
	return m_time;
}

int lift::is_lift_free(int time) {
	if (time < m_time)
		return 0;
	return 1;
}

void time_update(lift* lifts, int lift_count, long long time) {
	for (int i = 0; i < lift_count; i++) {
		lifts[i].m_time = max(lifts[i].m_time, time);
	}
}

int findlift(lift *lifts, int lift_count, int floor, long long time){
	int ans = -1;
	vector <int> q(lift_count);
	
	for (int i = 0; i < lift_count; i++) {

		if (!lifts[i].is_lift_free(time))
			q[i] = 1e9;
		else
			q[i] = abs(lifts[i].m_floor - floor);
	}
	int min = 1e9;
	for (int i = 0; i < lift_count; i++)
		if (q[i] < min) {
			min = q[i];
			ans = i;
		}

	return ans;
}
