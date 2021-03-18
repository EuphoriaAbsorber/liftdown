
#include <iostream>
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
    vector <pair<int, pair<long long, char>>> yy;
    char dir; // направление
    lift x;
        cin >> lift_count >> nowtime;// флаг + время вызова
        int n; // количество вызовов на этажи
        /*
        vector <lift> lifts;
        for (int i = 0; i < lift_count; i++) {
            lift d;
            lifts.push_back(d);
        }
        */
        int a;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> dir >> a;
            pair<int, pair<long long, char>> z;
            z.first = a; // этаж
            z.second.first = nowtime; // время вызова
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

        for (pair<int, pair<long long, char>> z : outcalls) {
            //int r = findlift(x);
            x.gotofloor(z.first);
            for (int i = 0; i < m[z].size(); i++)
                x.gotofloor(m[z][i]);

        }
        
    cout << "Total time " << x.get_time() << endl;
}

