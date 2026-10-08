#pragma once
#include <iostream>
using namespace std;
//11.4
bool esteSubsecventa(int v[], int d, int y[], int dy)
{
    int j = 0;  
    for (int i = 0; i < d; i++)
    {
        if (j < dy && v[i] == y[j])
        {
            j++;
        }
    }
    if (j == dy)
        return true;
    else
        return false;
}
void sol23()
{
    int v[100] = { 8, 5, 8, 5, 2, 3 };
    int d = 6;

    int y1[100] = { 8, 2, 3 };
    int y2[100] = { 3, 5 };

    cout << esteSubsecventa(v, d, y1, 3) <<  endl;  
    cout << esteSubsecventa(v, d, y2, 2) <<  endl;  
}

//11.5
int lungimeMaximaComuna(int a[], int n, int b[], int m)
{
    int maxLen = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int k = 0;
            while (i + k < n && j + k < m && a[i + k] == b[j + k])
                k++;
            if (k > maxLen)
                maxLen = k;
        }
    return maxLen;
}
void sol24() {
    int a[100] = { 1,2,3,4 };
    int n = 4;
    int b[100] = { 1,2,3,6,7,8 };
    int m = 6;
    cout<<lungimeMaximaComuna(a, n, b, m);

}