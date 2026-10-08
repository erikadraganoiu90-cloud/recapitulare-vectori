#pragma once
#include <iostream>
using namespace std;

//4.3
int nrCif(int n) {
    if (n == 0) {
        return 1;
    }
    int nr = 0;
    while (n > 0) {
        nr++;
        n = n / 10;
    }
    return nr;
}
void sortareDupaLungime(int v[], int dim) {
    for (int i = 0;i < dim - 1;i++) {
        for (int j = i + 1;j < dim;j++) {
            if (nrCif(v[i]) < nrCif(v[j])) {
                swap(v[i], v[j]);
            }
        }
    }
}
void sol36() {
    int v[100] = { 1,343,23,4543 };
    int dim = 4;
    sortareDupaLungime(v, dim);
    for (int i = 0;i < dim;i++) {
        cout << v[i] << " ";
    }
}

//4.4
void valDistincte(int v[], int dim) {
	int ct[10000] = { 0 };
	int max = 0;
	for (int i = 0;i < dim;i++) {
		ct[v[i]]++;
		if (v[i] > max) {
			max = v[i];
		}
	}
	for (int i = 0;i < max+1;i++) {
		if (ct[i] >= 1) {
			cout << i << " ";
		}
	}
}
void sol10() {
	int v[101] = { 2 ,2 ,3 ,5, 5, 6 };
	int dim = 6;
	valDistincte(v, dim);
}

//4.5
void sortareSelectie(int v[], int dim) {
    for (int i = 0; i < dim - 1; i++)
    {
        if (v[i] == 0) {
            continue;
        }


        int pmin = i;
        for (int j = i + 1; j < dim; j++)
        {
            if (v[j] == 0) {
                continue;
            }
            if (v[j] < v[pmin])
            {
                pmin = j;
            }
        }

        if (pmin != i)
        {
            int aux = v[i];
            v[i] = v[pmin];
            v[pmin] = aux;
        }
    }for (int i = 0; i < dim; i++)
        cout << v[i] << " ";
}
void sol11( ) {
    int v[100] = { 0,34,5,0,3 };
    int dim = 5;
    sortareSelectie(v, dim);
     
}