#pragma once
#include <iostream>
using namespace std;
//6.3
bool esteVarf(int v[], int dim,int i) {
    
    if (i == 0 || i == dim - 1) {
        return false;
    }

    return v[i - 1]<v[i] && v[i]>v[i + 1];
}

int pozVf(int v[], int dim) {
    for (int i = 0;i < dim;i++) {
        if (esteVarf(v, dim, i) == 1) {
            return i;
         }
    }
    
}
void sol38() {
    int v[100] = { 1, 2, 3, 4, 2, 1 };
    int dim = 6;
    cout << pozVf(v, dim);
}

//6.4
void sortareInterval(int v[], int start, int finish)
{
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
void sortareIntervalDescrescator(int v[], int start, int finish)
{
    bool sortat = false;
    while (sortat == false)
    {
        sortat = true;
        for (int i = start; i < finish; i++)
        {
            if (v[i] < v[i + 1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sortat = false;
            }
        }
    }
}
void sortareMunte(int v[], int d, int varf)
{
    sortareInterval(v, 0, varf);
    sortareIntervalDescrescator(v, varf, d - 1);
    for (int i = 0;i < d;i++) {
        cout << v[i] << " ";
    }
}
void sol14() {
    int v[] = { 9, 7, 5, 3, 1, 2 };
    int dim = 6;
    sortareMunte(v, dim, 3);
}

//6.5

//Scrie o functie care intoarce lungimea celei mai lungi portiuni de elemente vecine care formeaza un munte
  //todo functie este varf

//cati pasi pot merge la stanga 

int pasiLaStanga(int v[],  int i) {
    int pasi = 0;
    while (i - 1 >= 0 && v[i - 1] < v[i]) {
        pasi++;
        i--;
    }
    return pasi;
}


//cati pasi pot merge la dreapta
int pasiLaDreapta(int v[],int dim, int i) {
    int pasi = 0;
    while (i + 1 < dim && v[i] > v[i + 1]) {
        pasi++;
        i++;
    }
    return pasi;
}

int lungimeMaximaMunte(int v[], int dim) {
    int lungimeMaxima = 0;
    for (int i = 0;i < dim;i++) {
        if (esteVarf(v, dim, i) == 1) {
            int lungimeCurenta = pasiLaStanga(v, i) + pasiLaDreapta(v, dim, i) + 1;
            if (lungimeCurenta > lungimeMaxima) {
                lungimeMaxima = lungimeCurenta;
            }
        }
    }
    return lungimeMaxima;
 }

void solVf() {
    int v[100] = {  2,1,4,7,3,2,5 };
    int dim = 7;
    cout << lungimeMaximaMunte(v, dim);
}