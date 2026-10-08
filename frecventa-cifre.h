#pragma once
#include <iostream>
using namespace std;
//15.4
int cateCifreDiferite(int n)
{
    if (n < 0) n = -n;
    if (n == 0) return 1;
    int f[10] = { 0 };
    while (n > 0)
    {
        f[n % 10]++;
        n = n / 10;
    }
    int nr = 0;
    for (int i = 0; i <= 9; i++)
        if (f[i] > 0) nr++;
    return nr;
}

int numarCuCeleMaiMulteCifreDiferite(int v[], int d)
{
    int best = v[0];
    int bestNr = cateCifreDiferite(v[0]);
    for (int i = 1; i < d; i++)
    {
        int c = cateCifreDiferite(v[i]);
        if (c > bestNr)
        {
            bestNr = c;
            best = v[i];
        }
    }
    return best;
}

void sol31() {
    int v[100] = { 111,1234,55,907 };
    int d = 4;
    cout << numarCuCeleMaiMulteCifreDiferite(v, d);
}

//15.5
bool prietene(int a, int b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    int fa[10] = { 0 }, fb[10] = { 0 };
    if (a == 0) fa[0]++;
    while (a > 0) { fa[a % 10]++; a = a / 10; }
    if (b == 0) fb[0]++;
    while (b > 0) { fb[b % 10]++; b = b / 10; }
    for (int i = 0; i <= 9; i++)
        if (fa[i] != fb[i]) return false;
    return true;
}

int numarPerechiPrietene(int v[], int d)
{
    int nr = 0;
    for (int i = 0; i < d; i++)
        for (int j = i + 1; j < d; j++)
            if (prietene(v[i], v[j])) nr++;
    return nr;
}

void sol32() {
    int v[100] = { 21,12,34,43,21 };
    int d = 5;
    cout<<numarPerechiPrietene(v, d);
}
