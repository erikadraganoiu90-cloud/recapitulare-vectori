#pragma once
#include <iostream>
using namespace std;
//13.5
int sumaMaximaCelPutin2(int v[], int d)
{
    int best = v[0] + v[1];
    for (int i = 0; i < d; i++)
    {
        int suma = 0;
        for (int j = i; j < d; j++)
        {
            suma = suma + v[j];
            if (j - i + 1 >= 2)
            {
                if (suma > best)
                    best = suma;
            }
        }
    }
    return best;
}
void sol27() {
    int v[100] = { 5,-9,6,-1,7 };
    int d = 5;
    cout<<sumaMaximaCelPutin2(v, d);
}

//13.5
int sumaMaximaBucata(int v[], int st, int dr)
{
    int best = v[st];
    int suma = 0;
    for (int i = st; i <= dr; i++)
    {
        if (suma < 0)
            suma = v[i];
        else
            suma = suma + v[i];
        if (suma > best)
            best = suma;
    }
    return best;
}

int sumaMaximaDouaSecvente(int v[], int d)
{
    int best = -1000000000;
    for (int t = 0; t < d - 1; t++)
    {
        int stanga = sumaMaximaBucata(v, 0, t);
        int dreapta = sumaMaximaBucata(v, t + 1, d - 1);
        if (stanga + dreapta > best)
            best = stanga + dreapta;
    }
    return best;
}

void sol28() {
    int v[100] = { 3,-2,5,-8,4,6 };
    int d = 6;
    cout << sumaMaximaDouaSecvente(v, d);
}
