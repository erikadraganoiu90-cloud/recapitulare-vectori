#pragma once
#include <iostream>
using namespace std;

void afisare(int v[], int n) {

	for (int i = 0;i < n;i++) {
		cout << v[i] << " ";
	}

}

void sol1() {

	int v[100] = { 23, 43, 65, 21, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int dim = 20;

	afisare(v, dim);

}

//todo:
//Ex 1 a)

//todo functie ce verifica daca un numar este prim

bool nrPrim(int n) {
	if (n < 2) {
		return false;
	}
	for (int d = 2;d * d <= n;d++) {
		if (n % d == 0) {
			return false;
		}
	}
	return true;
}

int ctPrimeVec(int v[], int dim) {
	int ct = 0;
	for (int i = 0;i < dim;i++) {
		if (nrPrim(v[i])) {
			ct++;
		}
	}

	return ct;
}


void sol2() {

	int v[100] = { 67, 62, 98, 89, 78, 24, 19, 96, 88, 13 };
	int dim = 10;

	cout << "elementele vectorului" << endl;
	afisare(v, dim);
	cout << endl;
	cout << ctPrimeVec(v, dim) << " nr prime" << endl;
}

//Exercitiu extra


int minElemVec(int v[], int dim) {
	int min = 9999;
	for (int i = 0;i < dim;i++) {
		if (v[i] < min) {
			min = v[i];
		}
	}
	return min;
}

//functie ce returneaza cifra minima dintr-un numar
int cifMinima(int n) {
	int min = 9;
	while (n > 0) {
		int cif = n % 10;
		if (cif < min) {
			min = cif;
		}
		n = n / 10;
	}
	return min;
}
int cifMinimaVect(int v[], int dim) {
	int cifMinim = 9;
	for (int i = 0;i < dim;i++) {
		int cif = cifMinima(v[i]);
		if (cif < cifMinim) {

			cifMinim = cif;
		}
	}
	return cifMinim;
}


int cifMax(int n) {
	int max = 0;
	while (n > 0) {
		int cif = n % 10;
		if (cif > max) {
			max = cif;
		}
		n = n / 10;
	}
	return max;
}

int cifMaxVect(int v[],int dim) {
	int cifMaxima = 0;
	for (int i = 0;i < dim;i++) {
		int cif = cifMax(v[i]);
		if (cif > cifMaxima) {
			cifMaxima = cif;
		}
	}
	return cifMaxima;
}

void sol3() {
	int v[100] = { 67, 62, 98, 89, 78, 24, 19, 96, 88, 13 };
	int dim = 10;
	afisare(v, dim);
	cout << endl;
	cout << cifMinimaVect(v, dim);
	cout << endl;
	cout << cifMaxVect(v, dim);

}

//functie ce verifica daca un nuamr contine o anumita cifra

bool contineCifra(int n, int x) {
	while (n > 0) {
		int cif = n % 10;
		if (cif == x) {
			return true;
		}
		n = n / 10;
	}
	return false;
}

void  afisareNumereCeContinCifraMinima(int v[],int dim) {
	int cifMin = cifMinimaVect(v, dim);
	for (int i = 0;i < dim;i++) {
		if (contineCifra(v[i], cifMin)) {
			cout << v[i] << endl;
		}
	}
}

void sol4() {
	int v[100] = { 67, 62, 98, 89, 78, 24, 19, 96, 88, 13 };
	int dim = 10;
	afisare(v, dim);
	cout << endl;
	cout << cifMinimaVect(v, dim);
	cout << endl;
	afisareNumereCeContinCifraMinima(v, dim);
}