#pragma once
#include <iostream>
using namespace std;

//5.3
void ordonareCrescator(int v[], int start,int stop) {
    for (int i = start;i < stop;i++) {
        for (int j = i + 1;j <= stop;j++) {
           if (v[i] > v[j]) {
            swap(v[i], v[j]);
        }
        }
        
    }
}
void ordonareDescrescator(int v[], int start,int stop) {
    for (int i =start;i <stop;i++) {
        for (int j = i + 1;j <= stop;j++) {
           if (v[i] < v[j]) {
            swap(v[i], v[j]);
        }
        }
        
    }
}
void sortareJumatati(int v[], int dim) {
    int mij = dim / 2;
    ordonareCrescator(v, 0, mij);
    ordonareDescrescator(v, mij, dim);
}
void sol37() {
    int v[100] = { 9,7,5,3,1,2 };
    int dim = 6;
    sortareJumatati(v, dim);
    for (int i = 0;i<dim;i++) {
        cout << v[i] << " ";
    }
}

//5.4
void sortareInterval(int v[],int dim, int start, int finish) {
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
void sol12( ) {
int v[] = { 9, 7, 5, 3, 1, 2 };
    int dim = 6;

    for (int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
    
    sortareInterval(v, dim, 1, 4);
}

//5.5
 
void sortareTreimi(int v[], int dim) {
    int p = dim / 3;  
    sortareInterval(v,dim, 0, p - 1);
    sortareInterval(v, dim,p, 2 * p - 1);
    sortareInterval(v,dim, 2 * p, dim - 1);

}
void sol13() {
    int v[] = { 9, 7, 5, 3, 1, 2 };
    int dim = 6;
    sortareTreimi(v, dim);
    for (int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
}

