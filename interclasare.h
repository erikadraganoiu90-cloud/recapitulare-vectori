#pragma once
#include <iostream>
using namespace std;

//7.4
void interclasare(int a[], int da, int b[], int db, int c[], int& dc)
{
    int i = 0;
    int j = 0;
    dc = 0;

    while (i < da && j < db)
    {
        if (a[i] < b[j])
        {
            c[dc++] = a[i++];
             
        }else{
        if (b[j] < a[i]) {
            c[dc++] = b[j++];
        }
        else {
            c[dc++] = a[i];
            i++;
            j++;
        }
        }
        

         
            
        
       
    }

    while (i < da)
    {
        if (dc == 0 || c[dc - 1] != a [i] ) {
           c[dc++] = a[i];
        }
        i++;
        
        
    }

    while (j < db)
    {
        if (dc == 0 || c[dc - 1] != b[j]) {
           c[dc++] = b[j];
        }
        
        j++;
        
    }
    
}
void sol15() {
    int a[100] = { 1 ,3 ,5 ,6, 7 };
    int b[100] = { 1 ,2 ,5 , 8, 9 };
    int da = 5;
    int db = 5;
    int c[100];
    int dc;
    interclasare(a, da, b, db, c, dc);
    for (int i = 0;i < dc;i++) {
        cout << c[i] << " ";
    }
}

//7.5
void sol16() {
    int a[100] = { 1, 3, 5, 6, 7 };
    int b[100] = { 1, 2, 5, 8, 9 };
    int d[100] = { 0, 4, 5, 10 };
    int da = 5, db = 5, dd = 4;

    int temp[200], c[300];
    int dtemp, dc;

    interclasare(a, da, b, db, temp, dtemp);  
    interclasare(temp, dtemp, d, dd, c, dc);  

    for (int i = 0; i < dc; i++)
        cout << c[i] << " ";
}