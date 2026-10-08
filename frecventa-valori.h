#pragma once
#include <iostream>
using namespace std;
//14.4
int frecventaValori(int v[], int d )
{
    int ct[10000] = { 0 };
    for (int i = 0;i < d;i++) {
        ct[v[i]]++;
        if (ct[v[i]] == 2) {
            return v[i];
        }
     }
    return -1;
}
void sol29() {
    int v[100] = { 2,3,5,1,2,5 };
    int d = 6;
    cout << frecventaValori(v, d);
}

//14.5
int majoritar(int v[], int d) {
    int ct[1000] = { 0 };
    for (int i = 0;i < d;i++) {
        ct[v[i]]++;
    }
    int max = -1000;
    int nr=0;
    for (int i = 0;i < d;i++) {
        if (ct[v[i]] > d / 2 && ct[v[i]] > max) {
            max = ct[v[i]];
             nr = v[i];
        }
    }
    if (nr == 0) {
        return -1;
    }
    else {
        return nr;
    }
    
}
void sol30() {
    int v[100] = { 3,3,4,4 };
    int d = 6;
    cout<<majoritar(v, d);
}
