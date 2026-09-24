#pragma once
#include <iostream>
using namespace std;

void afisare(int v[], int n) {
	
	for (int i = 1;i <= n;i++) {
		cout << v[i] << "";
	}
	
}

void sol1() {

	int v[100] = { 23, 43, 65, 21, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int dim = 20;

	afisare(v, dim);

}