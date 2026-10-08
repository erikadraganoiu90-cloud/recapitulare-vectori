#pragma once
#include <iostream>
using namespace std;

 //Ex 1 a)-minimul si aparitia
 
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
	int min = minVector(v, dim);
	for (int i = 0;i < dim;i++) {
		if  (min== v[i]) {
			ct++;
		}
	}
	return ct;
}

void minCtVector(int v[], int dim) {
	cout << minVector(v, dim) << " " << ctMin(v, dim);
}


void solutie1() {
	int v[100]={ 123,34,112,34,234 };
	int d = 5;

	minCtVector(v, d);
}

//Ex1 b)-cifra maxima ,aparitia in afara de elementul minim si maxim
int cifMax(int n) {
	int max = 0;
	while (n > 0) {
		int uc = n % 10;
		if (uc > max) {
			max = uc;
		}
		n = n / 10;
	}
	return max;
 }
int cifMaxVect(int v[], int dim) {
	int max = 0; 
	for (int i = 0;i < dim;i++) {
		if (cifMax(v[i]) > max) {
			max = cifMax(v[i]);
		}
	}
	return max;
}
int ctAparitieCifMaxima(int n) {
	int ct = 0;
	int max = cifMax(n);
	while (n > 0) {
		int uc = n % 10;
		if (uc == max) {
			ct++;
		}
		n = n / 10;
	}
	return ct;
}
int maxVector(int v[], int dim) {
	int max = v[0];
	for (int i = 1;i < dim;i++) {
		if (v[i] > max) {
			max = v[i];
		}
	}

	return max;
}
void ctAparitieCifMaximaVector(int v[], int dim) {
	int ctCifMax = 0;
	int max = cifMaxVect(v, dim);
	int elementmin = minVector(v, dim);
	int elementmaxim = maxVector(v,dim);
	for (int i = 0;i < dim;i++) {
		if (cifMax(v[i]) == max&&v[i]!=elementmin&&v[i]!=elementmaxim) {
			ctCifMax = ctCifMax + ctAparitieCifMaxima(v[i]);
		}
		 
	}
	cout << ctCifMax;
}
void solutie2() {
	int v[100] = { 126,34,116,34,236 };
	int d = 5;

	ctAparitieCifMaximaVector(v, d);
}


//1.4
int aDouaCeaMaiMareVal(int v[], int dim) {
	int max1 = v[0];
	int max2 = v[0];
	for (int i = 1;i < dim;i++) {
		if (v[i] >= max1) {
			max2 = max1;
			max1 = v[i];

		}
	}
	return max2;
} 
void sol4() {
	int v[101] = { 2 ,23 ,34 ,56, 49, 57, 67 };
	int dim = 7;
	cout << aDouaCeaMaiMareVal(v, dim);
}

//1.5
int max3Elemente(int x, int y, int z) {
	int max = x;
	if (y > max ) {
		max = y;
	}
	if (z > max) {
		max = z;
	}
	return max;
}
void max3ElementeVector(int v[], int dim) {
	for (int i = 0;i < dim - 2;i++) {
		cout << max3Elemente(v[i], v[i + 1], v[i + 2]) << " ";
	}
}
void sol5() {
	int v[101] = { 2 ,23 ,34 ,56, 4, 57, 67 };
	int dim = 7;
	max3ElementeVector(v, dim);
}




 


