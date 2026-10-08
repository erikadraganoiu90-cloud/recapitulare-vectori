#pragma once
#include <iostream>
using namespace std;
//    0 1 2 3   4  5  6  7  8  9 10 11 12 13 14
// v={2 5 8 12 16 23 38 45 56 67 72 81 90 95 99}  key=  72


// inf<=sup  mij   v[ mij]==key  inf  sup  
// 0<14  da  7       45=== 72    8     
// 8<14  da  11      81==72           10
// 8<10 da   9       67==72      9
// 9<10 da   10      72==72     

 
int cautareBinara(int v[], int d, int key)
{
    int inf = 0;
    int sup = d - 1;

    while (inf <= sup)
    {
        int mij = (inf + sup) / 2;
        if (v[mij] == key)
        {
            return mij;
        }
        if (v[mij] < key)
        {
            inf = mij + 1;
        }
        else
        {
            sup = mij - 1;
        }
    }

    return -1;
}
 void sol1( ) {
     int v[101] = { 2 ,23 ,34 ,56, 49, 57, 67 };
     int dim = 7;
     cout<<cautareBinara(v, dim, 23);
}
 int ctNrInVect(int v[], int d1, int w[], int d2) {
     int ct = 0;
     for (int i = 0;i < d2;i++) {
         if (cautareBinara(v, d1, w[i]) != -1) {
             ct++;
         }
     }
     return ct;
 }
 void solutie3() {
     int v[101] = { 5, 10,14,19 };
     int d1 = 4;
     int w[101] = { 10,7,19 };
     int d2 = 3;
     cout << ctNrInVect(v,d1,w,d2);
 }


 //2.3
 int pozitieInserare(int v[], int dim, int val) {
     for (int i = 0;i < dim;i++) {
         if (v[i] > val) {
             return i;
         }
     }
     return dim;
 }
 void sol34() {
     int v[100] = { 2,5,9,14 };
     int dim = 4;
     cout << pozitieInserare(v, dim, 7);
 }

  //2.4
 int ceaMaiMicaValMaiMareCaX(int v[], int dim, int x) {
     int inf = 0;
     int sup = dim - 1;
     int rez = -1;

     while (inf <= sup)
     {
         int mij = (inf + sup) / 2;
         if (v[mij] > x)
         {
             rez = v[mij];
             sup = mij - 1;
  
         }
         else
         {
            inf = mij + 1;
         }
     }

     return rez;
 }
 void sol6() {
     int v[101] = { 2 ,23 ,34 ,56, 49, 57, 67 };
     int dim = 7;
     cout <<ceaMaiMicaValMaiMareCaX(v, dim, 23);
 }

 //2.5
 int primaPozitieMaiMareEgal(int v[], int dim, int x) {
     int st = 0, dr = dim - 1, rez = dim;
     while (st <= dr) {
         int mij = (st + dr) / 2;
         if (v[mij] >= x) {
             rez = mij;
             dr = mij - 1;
         }
         else {
             st = mij + 1;
         }
     }
     return rez;
 }
 int ultimaPozitieMaiMicaEgal(int v[], int dim, int x) {
     int st = 0, dr = dim - 1, rez = -1;
     while (st <= dr) {
         int mij = (st + dr) / 2;
         if (v[mij] <= x) {
             rez = mij;
             st = mij + 1;
         }
         else {
             dr = mij - 1;
         }
     }
     return rez;
 }
 int cateInInterval(int v[], int dim, int a, int b) {
     int stanga = primaPozitieMaiMareEgal(v, dim, a);
     int dreapta = ultimaPozitieMaiMicaEgal(v, dim, b);
     if (stanga > dreapta) return 0;
     return dreapta - stanga + 1;
 }
 void sol7() {
     int v[101] = { 2 ,23 ,34 ,56, 49, 57, 67 };
     int dim = 7;
     cout<<cateInInterval(v, dim, 23, 49);
 }

 
