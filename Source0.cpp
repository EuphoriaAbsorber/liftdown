#include <iostream>
#include <set>
using namespace std;

int main(){
	set <int> t = { 1,2,3,4,5 };
	for (auto h : t)
		t.erase(h);
	for (auto h : t)
		cout << h << endl;
}