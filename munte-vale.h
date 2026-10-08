#pragma once
#include <iostream>
using namespace std;
//6.4
void sortareInterval(int v[], int start, int finish)
{
    bool sortat = false;
    while (sortat == false)
    {
        sortat = true;
        for (int i = start; i < finish; i++)
        {
            if (v[i] > v[i + 1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sortat = false;
            }
        }
    }
}
void sortareIntervalDescrescator(int v[], int start, int finish)
{
    bool sortat = false;
    while (sortat == false)
    {
        sortat = true;
        for (int i = start; i < finish; i++)
        {
            if (v[i] < v[i + 1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sortat = false;
            }
        }
    }
}
void sortareMunte(int v[], int d, int varf)
{
    sortareInterval(v, 0, varf);
    sortareIntervalDescrescator(v, varf, d - 1);
    for (int i = 0;i < d;i++) {
        cout << v[i] << " ";
    }
}
void sol14() {
    int v[] = { 9, 7, 5, 3, 1, 2 };
    int dim = 6;
    sortareMunte(v, dim, 3);
}

//6.5

