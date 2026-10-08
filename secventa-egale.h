#pragma once
#include <iostream>
using namespace std;
//10.4
void ceaMaiLungaSecventaEgale(int v[], int d )
{
   int start = -1;
   int lungime = 0;

    for (int i = 0; i < d; i++)
    {
        int j = i;
        while (j + 1 < d && v[j + 1] >v[j])
        {
            j++;
        }

        if (j - i + 1 > lungime)
        {
            start = i;
            lungime = j - i + 1;
        }

        i = j;
    }
    cout << start << " " << lungime;
}
void sol21() {
    int v[100] = { 1,2,3,4,2,1 };
    int d = 6;
    ceaMaiLungaSecventaEgale(v, d);
}

//10.5

void ceaMaiLungaSecventaEgaleParitate(int v[], int d) 
{
    int start = -1;
    int lungime = 0;

    for (int i = 0; i < d; i++)
    {
        int j = i;
        while (j + 1 < d && v[j + 1] > v[j] && v[j + 1] % 2 == v[j] % 2)
        {
            j++;
        }

        if (j - i + 1 > lungime)
        {
            start = i;
            lungime = j - i + 1;
        }

        i = j;
    }
    cout << lungime;
}
void sol22() {
    int v[100] = { 1,2,4,6,2,1 };
    int d = 6;
    ceaMaiLungaSecventaEgaleParitate(v, d);
}