#pragma once
#include <iostream>
using namespace std;

//3.3
bool nrPar(int n) {
    if (n % 2 == 0) {
        return true;
    }
    return false;
 }
void sortarePare(int v[], int dim) {
    for (int i = 0;i < dim - 1;i++) {
        if (nrPar(v[i]) == 1) {
            for (int j = i + 1;j < dim;j++) {
                if (nrPar(v[j]) == 1&&v[j]<v[i]) {
                    swap(v[i], v[j]);
                }
            }
        }
    }
}
void sol35() {
    int v[100] = { 5,8,3,2,9,6 };
    int dim = 6;
    sortarePare(v, dim);
    for (int i = 0;i < dim;i++) {
        cout << v[i] << " ";
    }
}

//3.4
bool sortat(int v[], int dim) {
	for (int i = 0;i < dim-1;i++) {
		if (v[i] > v[i + 1]) {
			return false;
		}
	}
	return true;

}
void sol8() {
	int v[101] = { 2 ,23 ,34 ,56, 57, 67 };
	int dim = 6;
	cout << sortat(v, dim);
}

//3.5
void contorSortareCrescator(int v[], int d)
{
    int ct = 0;
    bool sortat = false;
    while (sortat == false)
    {
        sortat = true;
        for (int i = 0; i < d - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sortat = false;
                ct++;
            }
        }
    }
     cout<< ct;
}
void sol9() {
    int v[101] = { 24 ,23 ,34 ,56, 57, 67 };
    int dim = 6;
    contorSortareCrescator(v, dim);
}