#pragma once
#include <iostream>
using namespace std;
//8.4
int mediAritmetica(int v[], int dim) {
	int s = 0;
	int ct = 0;
	for (int i = 0;i < dim;i++) {
		s = s + v[i];
		ct++;
	}
	int media = s / ct;
	return media;
}
void stergereElement(int v[], int& dim)
{
	int media = mediAritmetica(v, dim);
	for (int i = 0; i < dim ; i++)
	{
		if (v[i] < media ) {
			for (int j = i;j < dim-1;j++) {
               v[j] = v[j + 1];
			}
			dim--;
		i--;
		}

	    
		 
	}
	 

}
void sol17() {
	int v[100] = { 1, 3, 5, 6, 7 };
	int dim = 5;

	stergereElement(v, dim);
	for (int i = 0;i < dim;i++) {
		cout << v[i] << " ";
	}
}

//8.5
int ctAparitie(int v[],int dim,int n) {
	int ct  =  0 ;
	for (int i = 0;i < dim;i++) {
		if (v[i] == n) {
			ct++;
		 }
		 
	}
	return ct;

}
void stergereNr(int v[], int dim) {
	int a[1000];
	int k = 0;
	for (int i = 0;i < dim;i++) {
		if (ctAparitie(v, dim,v[i]) == 1) {
			a[k++] = v[i  ];

		}
	}
	for (int i = 0;i < k;i++) {
		cout << a[i] << " ";
	}
}
void sol18() {
	int v[100] = { 2,2,2,2,3,4,4,5,6,6 };
	int dim = 10;
	stergereNr(v, dim);
}
