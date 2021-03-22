#include <iostream>
#include <algorithm>
#include "lift.h"
#include <string>
#include <sstream>
#include <vector>
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
    int request_count; // количество запросов
    int total_outcalls_count = 0; // всего вызовов

    cin >> lift_count; // количество лифтов
    vector <lift> lifts;
    for (int i = 0; i < lift_count; i++) {
        lift d;
        lifts.push_back(d);
    }
    lift* liftpointer = &lifts[0];

    cin >> request_count; // количество запросов
    for (int l = 0; l < request_count; l++) {
        cin >>  nowtime;// время вызова
        int n; // количество вызовов на этажи
        //cout << nowtime << endl;
        int a; // этаж
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> dir >> a;
            pair<long long, pair<int, char>> z;
            z.first = nowtime; // время вызова
            z.second.first = a; // этаж
            z.second.second = dir; // направление
            yy.push_back(z);
            outcalls.insert(z);
        }
        string s;
        getline(cin, s);
        for (int i = total_outcalls_count; i < total_outcalls_count + n; i++) {

            getline(cin, s);
            istringstream ss(s);
            int k;
            while (ss >> k)
                m[yy[i]].push_back(k);

            if (yy[i].second.second == '^')
                sort(m[yy[i]].begin(), m[yy[i]].end());
            if (yy[i].second.second == 'v')
                sort(m[yy[i]].rbegin(), m[yy[i]].rend());

            if (yy[i].second.second == '#') {
                sort(m[yy[i]].begin(), m[yy[i]].end());
                vector <int> less;
                vector <int> more;
                for (int j = 0; j < m[yy[i]].size(); j++) {
                    if (m[yy[i]][j] < yy[i].second.first)
                        less.push_back(m[yy[i]][j]);
                    else
                        more.push_back(m[yy[i]][j]);
                }
                int time_up = 0;
                int time_down = 0;

                for (int j = 1; j < less.size(); j++)
                    time_down += 10 * abs(less[j] - less[j-1]);
                time_down += abs(less[0] - yy[i].second.first);
                time_down += abs(less[less.size()-1] - yy[i].second.first);
                for (int j = 1; j < more.size(); j++)
                    time_up += 10 * abs(more[j] - more[j-1]);
                time_up += abs(more[0] - yy[i].second.first);
                time_up += abs(more[more.size() - 1] - yy[i].second.first);
                
                if (time_down < time_up) {
                    for (int j = 0; j < less.size(); j++)
                        m[yy[i]][j] = less[j];
                    for (int j = less.size(); j < less.size()+more.size(); j++)
                        m[yy[i]][j] = more[j-less.size()];
                }
                else {
                    for (int j = 0; j < more.size(); j++)
                        m[yy[i]][j] = more[j];
                    for (int j = more.size(); j < less.size() + more.size(); j++)
                        m[yy[i]][j] = less[j - more.size()];
                }
                
            }
                      
        }
        total_outcalls_count += n;
    }
        while (outcalls.size()) {

            if (outcalls.size() == 0)
                break;
            for (int i = 0; i < lift_count; i++)
                lifts[i].m_time = max(lifts[i].m_time, total_time);
          
            help_set = outcalls;

            for (int i = 0; i < lift_count; i++)
                if (lifts[i].is_lift_free(total_time)) {
                    for (auto z : outcalls) {
                        if (z.first > lifts[i].m_time)
                            break;
                        if (z.first <= lifts[i].m_time && z.second.first == lifts[i].m_floor) {
                            for (int j = 0; j < m[z].size(); j++)
                                lifts[i].gotofloor(m[z][j]);
                            help_set.erase(z);
                            break;
                        }
                    }
                    outcalls = help_set;
                }

            for (auto  z : outcalls) {
                if (z.first > total_time)
                    break;

                int r = findlift(liftpointer,lift_count,z.second.first,total_time);
                if (r == -1)
                    break;

                lifts[r].gotofloor(z.second.first);           
                for (int i = 0; i < m[z].size(); i++)
                    lifts[r].gotofloor(m[z][i]);
                help_set.erase(z);
                }
            outcalls = help_set; 
            
            total_time += 10;
            //time_update(liftpointer, lift_count, total_time);
        }
    for (int i = 0; i < lift_count; i++)
        total_time = max(lifts[i].m_time, total_time);

    cout << "Total time " << total_time << endl;
}

