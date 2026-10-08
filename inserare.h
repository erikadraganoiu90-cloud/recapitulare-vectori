#pragma once
#include <iostream>
using namespace std;

//9.4
void inserareElement(int v[], int& d,  int elem)
{
    for (int i = d - 1; i >= 0; i--)
    {
        if (v[i] % 2 == 0) {
            for (int j = d;j > i + 1;j--) {
               v[j] = v[j - 1];
            }
            v[i + 1] = elem;
            d++;
        }
        
    }
     
}
void sol19() {
    int v[100] = { 1,2,3,4,5 };
    int d = 5;
     
    
    inserareElement(v, d, 5);
    for (int i = 0;i < d;i++) {
        cout << v[i] << " ";
    }

   
}

//9.5
void intercalareAlternativa(int a[], int da, int b[], int db, int c[], int& dc)
{
    dc = 0;
    int i = 0, j = 0;
    while (i < da && j < db) {
        c[dc++] = a[i++];
        c[dc++] = b[j++];
    }
    while (i < da)
        c[dc++] = a[i++];
    while (j < db)
        c[dc++] = b[j++];
}
void sol20() {
    int a[100] = { 1, 2, 3 };
    int da = 3;
    int b[100] = { 7, 8 };
    int db = 2;
    int c[200], dc;
    intercalareAlternativa(a, da, b, db, c, dc);
    for (int i = 0; i < dc; i++)
        cout << c[i] << " ";
}
