#pragma once
#include <iostream>
using namespace std;

 
 
int minVector(int v[], int dim) {
	int min = v[0];
	for (int i = 1;i < dim;i++) {
		if (v[i] < min) {
			min = v[i];
		}
	}
	  
	return min   ;
}

int ctMin(int v[], int dim) {
	int ct = 0;
	for (int i = 0;i < dim;i++) {
		if (minVector(v,dim) == v[i]) {
			ct++;
		}
	}
	return ct;
}

void minCtVector(int v[], int dim) {
	cout << minVector(v, dim) << " " << ctMin(v, dim);
}

 


