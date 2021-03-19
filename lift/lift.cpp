
#include <iostream>
#include <algorithm>
#include "lift.h"
#include <string>
#include <sstream>
//#include "Classlift.cpp"
#include <vector>
//#include <queue>
#include <set>
#include <map>
using namespace std;


int main()
{
    long long total_time = 0;
    long long nowtime;
    int lift_count;
    map <pair<int, pair<long long, char>>, vector <int>> m;
    set <pair<int,pair<long long, char>>> outcalls; // внешние вызовы
    set <pair<int, pair<long long, char>>> help_set;
    vector <pair<int, pair<long long, char>>> yy;
    char dir; // направление
    //lift x;
        cin >> lift_count >> nowtime;// флаг + время вызова
        int n; // количество вызовов на этажи
        
        vector <lift> lifts;
        for (int i = 0; i < lift_count; i++) {
            lift d;
            lifts.push_back(d);
        }
        lift* liftpointer = &lifts[0];
        
        int a;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> dir >> a;
            pair<long long, pair<int, char>> z;
            z.first = nowtime; // этаж
            z.second.first = a; // время вызова
            z.second.second = dir; // направление
            yy.push_back(z);
            outcalls.insert(z);
        }
        string s;
        getline(cin, s);
        for (int i = 0; i < n; i++) {
            
            getline(cin, s);
            istringstream ss(s);
            int k;
            while(ss >> k){
                m[yy[i]].push_back(k);
            }
        }
        
        while (outcalls.size()) {

            if (outcalls.size() == 0)
                break;
            for (int i = 0; i < lift_count; i++)
                lifts[i].m_time = max(lifts[i].m_time, total_time);
            total_time += 10;
            help_set = outcalls;
            for (auto  z : outcalls) {
                //int r = 0;
                int r = findlift(liftpointer,lift_count,z.second.first,total_time);
                if (r == -1)
                    break;
                lifts[r].gotofloor(z.second.first);
                for (int i = 0; i < m[z].size(); i++)
                    lifts[r].gotofloor(m[z][i]);
                help_set.erase(z);
                }
            outcalls = help_set; 
        }
    for (int i = 0; i < lift_count; i++)
        total_time = max(lifts[i].m_time, total_time);

    cout << "Total time " << total_time << endl;
}

