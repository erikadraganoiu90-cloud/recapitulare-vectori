#pragma once
#include <iostream>
using namespace std;
//12.4
int numarSecventeCuSuma(int v[], int d, int s)
{
    int nr = 0;
    int stanga = 0;
    int suma = 0;
    for (int i = 0; i < d; i++)
    {
        suma = suma + v[i];
        while (suma > s && stanga <= i)
        {
            suma = suma - v[stanga];
            stanga++;
        }
        if (suma == s)
        {
            nr++;
        }
    }
    return nr;
}
void sol25() {
    int v[100] = { 1,2,3,4,2,4 };
    int d = 6;
    int s;
    cin >> s;
    cout << numarSecventeCuSuma(v, d, s);
}

//12.5
int sumaMaximaCelMultK(int v[], int d, int k)
{
    int stanga = 0;
    int suma = 0;
    int best = v[0];
    for (int i = 0; i < d; i++)
    {
        suma = suma + v[i];
        while (i - stanga + 1 > k)
        {
            suma = suma - v[stanga];
            stanga++;
        }
        if (suma > best)
        {
            best = suma;
        }
    }
    return best;
}
void sol26() {
    int v[100] = { 9,2,3,4,6,3 };
    int d = 6;
    int k;
    cin >> k;
    cout << sumaMaximaCelMultK(v, d, k);
}