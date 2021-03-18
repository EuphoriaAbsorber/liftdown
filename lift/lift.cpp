// lift.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "lift.h"
//#include "Classlift.cpp"
#include <vector>
#include <queue>
using namespace std;

int main()
{
    char f = 'a';
    vector <vector <int>> all;
    all.resize(2);
    vector <int> goup;
    vector <int> godown;
    char dir; // направление
    lift x;
    while (1) {
        cin >> f;
        if (f == 'q')
            break;
        int n; // количество вызовов на этажи
        int a;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> dir >> a;
            if (dir == '^')
                all[0].push_back(a);
            if (dir == 'v')
                all[1].push_back(a);
        }
       /*
        for (int i = 0; i < all[0].size();i++) {
            int b;
            while (not '\0') {
                cin >> b;
                all[0].push_back(b);
            }
        }
        for (int i = 0; i < all[1].size();i++) {
            int b;
            while (not '\0') {
                cin >> b;
                all[1].push_back(b);
            }
        }
        //for (int i = 0; i < godown.size();i++)
            //x.gotofloor(godown[i]);
        for(int k = 0; k<2; k++)
            for (int i = 0; i < all[k].size();i++) {
                x.gotofloor(all[k][i]);          
        }
        */
        for (int k = 0; k < 2; k++)
            for (int i = 0; i < all[k].size();i++) {
                x.gotofloor(all[k][i]);
            }
        
    }
    cout << "Total time " << x.get_time() << endl;
}

