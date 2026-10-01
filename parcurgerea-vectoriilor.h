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

//Ex 1 c)
bool UltimaPrimaCif(int n) {
	if (n < 10) {
		return true;
	}
	int uc = n % 10;
	while (n > 10) {
		n = n / 10;
	}
	if (uc == n) {
		return true;
	}
	else {
		return false;
	}

}
int rasturnat(int n) {
	int x = n;
	int ras=0;
	 
		int p = 1;
		while (x > 0) {
			int cif = x % 10;
			ras = ras*p + cif;
			p =  10;
			x = x/10;
		}
    return ras;
	 
	 
	
}

void afisareNrRast(int v[], int dim) {
	for (int i = 0;i < dim;i++) {
		if (UltimaPrimaCif(v[i]) == 1) {
			v[i] = rasturnat(v[i]);
			cout<<v[i]<<" ";
		}
	}
}
void sol5() {
	int v[100] = { 607, 6246, 8, 8932, 7841, 2024, 1921, 960, 8, 13 };
	int dim = 10;
	afisare(v, dim);
	cout << endl;
	 
	 
	 afisareNrRast(v, dim);
}
//Ex 1 d)
bool kDivPrp(int n,int k) {
	
	
	int ct = 0;
	for (int d = 2;d <= n / 2;d++) {
		if (n % d == 0) {
			ct++;
		}
	}
	if (ct == k) {
		return true;
	}
	else {
		return false;
	}
}
bool proprietateVect(int v[],int dim,int k) {
	
	for (int i = 0;i < dim;i++) {
		if (kDivPrp(v[i],k) == 0) {
			return false;
		}
	}
	return true;
}

void sol6() {
	int k;
	int v[100] = { 24, 30, 42, 66, 70, 78, 40, 54, 56, 88 };
	int dim = 10;
	afisare(v, dim);
 
	cin >> k;
	cout<< proprietateVect(v, dim,k);

	 
}
//Ex 1 e)

int prodParitate(int v[], int dim) {
	int p = 1;
	int gasit = 0;
	int start = dim / 3;
	int stop = 2 * dim / 3;
	for (int i = start; i < stop; i++) {
		if (v[i] % 2 == i % 2) {
			p = p * v[i];
			gasit = 1;
		}
	}
	if (gasit == 0) return 0;
	return p;
}

 

//Ex 1 f)
int nrZeroBinar(int n) {
	int ct = 0;
	while (n > 0) {
		if (n % 2 == 0) ct++;
		n = n / 2;
	}
	return ct;
}
int nrUnuBinar(int n) {
	int ct = 0;
	while (n > 0) {
		if (n % 2 == 1) ct++;
		n = n / 2;
	}
	return ct;
}
void sol8(int v[], int dim) {
	int s = 0;
	int start = 2 * dim / 4 ;
	int stop =3*dim/4;  
	for (int i = start; i < stop; i++) {
		if (nrZeroBinar(v[i]) == nrUnuBinar(v[i]))
			s = s + v[i];
	}
	cout<< s;
}

//Ex 1 g)
int cifraControl(int n) {
	while (n >= 10) {
		int s = 0;
		while (n > 0) {
			s = s + n % 10;
			n = n / 10;
		}
		n = s;
	}
	return n;
}
int prodCifre(int n) {
	int p = 1;
	while (n > 0) {
		p = p * (n % 10);
		n = n / 10;
	}
	return p;
}
void sol9(int v[], int dim) {
	for (int i = 0; i < dim; i++) {
		if (cifraControl(v[i]) % 2 == 0) {
            cout << prodCifre(v[i]) << " ";
		}
			
	}
}
//Ex 1 h)
bool ePrim(int n) {
	if (n < 2) return false;
	for (int d = 2; d <= n / 2; d++) {
		if (n % d == 0) {
			return false;
		}
	}
		
	return true;
}
bool eSuperprim(int n) {
	while (n > 0) {
		if (ePrim(n) == false) {
			return false;
		}
		n = n / 10; 
	}
	return true;
}
void sol10(int v[], int dim) {
	for (int i = dim - 1; i >= 0; i--) {  
		if (eSuperprim(v[i])) {
             cout << v[i] << " ";
		}
			
	}
}

//Ex 2 b)
bool ePatratPerfect(int n) {
	for (int i = 0;i * i <= n;i++) {
		if (i * i == n) {
			return true;
		}
	}
	return false;
}
bool cifreMijlocPatrate(int n) {
	if (n<100) {
		if (ePatratPerfect(n) == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	int ct = 0;
	int x = n;
	while (n > 0) {
		n = n / 10;
		ct++;
	 }
	 
	int p = 1;
	while (ct > 1) {
		p = p * 10;
		ct--;
	}
		if (x >= 100) {

			 int  aux = (x - (x / p) *p) / 10;
			if (ePatratPerfect(aux) == 1) {
				return true;
			}
			else {
				return false;
			}
		}
	 
}
bool palindrom(int n) {
	 
	int pal = 0;
	int y = n;
	while (n > 0) {
		 
		  pal = n%10 + 10 * pal;
		 
		n = n / 10;
	}
	 
	if (y == pal) {
		return true;
	}
	else {
		return false;
	}

	
}
 void sol11( ) {
	 int v[100] = { 67, 9, 5252, 81, 3, 24, 7, 11210, 808, 103,90,121 };
	 int dim = 12;
		for (int i = dim-1;i>=0;i--) {

			if (cifreMijlocPatrate(v[i]) == 1 && palindrom(v[i]) == 1) {
				cout << v[i] << " ";
			}
		}
	}

  
 //Ex 2 d)
 int cmmdc(int n, int m) {
	 while (n != m) {
		 if (n >= m) {
			 n = n- m;
		 }
		 else {
			 m = m - n;
		 }
	 }
	 return m;
 }
 int cmmdc2(int n, int m) {
	 while (n % m != 0) {
		 int rest = n % m;
		 n = m;
		 m = rest;
	 }
	 return m;
  }
 void sol13() {
	 int v[100] = { 67, 9, 5252, 81, 3, 24, 7, 11210, 808, 103,90,121 };
	 int dim = 12;
	 for (int i = 1;i <= dim;i++) {

		 if (cmmdc2(v[i],i)==1) {
			 cout << v[i] << " ";
		 }
	 }
 }

 //Ex 2 e)
 bool cifCons(int n) {
	 if (n < 10) {
		 return true;
	 }
	 while (n >= 10) {
		 int cif = n % 10;
         n = n / 10;
		 if (cif <  n% 10) {
			 return false;
		 }
		 
	 }
	 return true;
 }
 bool sol14() {
	  
	 int v[100] = { 67, 9, 56, 89, 3, 24, 7, 112, 8, 13,9,12 };
	 int dim = 12;
	 for (int i = 0;i < dim;i++) {
		 if (cifCons(v[i]) == 0) {
			 return false;
		 }
	 }
	 return true;
	 
 }

 //Ex 3 a)
  
 bool nrPar(int n) {
	 if (n % 2 == 0) {
		 return true;
	 }
	 else {
		 return false;
	 }
 }
 bool forma2k(int n )
 {
	 int k;
	 cin >> k;
	 if (n % 2 != 0) {
		 return false;
	 }
	 int ct = 0;
	 while (n %2==0) {
		 n = n / 2;
		 ct++;
	 }
	 if (ct == k) {
		 return true;
	 }
	 else {
		 return false;
	 }
 }
 bool sol15(int m,int v[]) {
	 
	  
	 for (int i = 1;i < m;i++) {
		 if (nrPar(v[i]) == 1) {
			 if (forma2k(v[i])== 0) {
				 return false;
			 }
		 }
	 }
	 return true;

 }

 //Ex 3b)
 void descomp(int n) {
	 int ct[10000] = { 0 };
	 int x = n;
	 for (int d = 2;d < x&&n!=1;d++) {
		 
		 while (n % d == 0) {
			 n = n / d;
			 ct[d]++;
		 }
		 
	 } 
	 if (n > 1) {
		 ct[n]++;
	  }
	 for (int i = 2;i < x;i++) {
		 if (ct[i] != 0) {

			 cout << x << "=" << i << "^" << ct[i]; cout << "+";
		 }
	 }
		 

	 
	
 }
 void sol16(int m, int v[]) {
	 for (int i = 1;i < m-1;i++) {
		 if (ePatratPerfect(v[i]) == 0 && v[i - 1] % 2 == v[i] % 2 && v[i] % 2 == v[i + 1] % 2) {
			 descomp(v[i]);
			 
			 cout << endl;
		 }
	 } }
 
 //ex 3 c)
 bool cifegale(int n) {
	 if (n < 10) {
		 return true;
	 }
	 else {
		 while (n >10) {
			 int uc = n % 10;
			 n = n / 10;
			 if (uc != n % 10) {
				 return false;
			 }
		 }
	 }
	 return true;

 }
 bool sol17(int m, int v[]) {
	 for (int i = m / 7 - 1;i < 2 * m -1/ 7;i++) {
		 if (cifegale(v[i]) != cifegale(v[i + 1])) {
			 return false;
		 }
	 }
	return true;
 }

 //ex 3 d)
 int stergereCif3sauPara(int n) {
	 int p = 1;
	 int nr = 0;
	 while (n > 0) {
		 int uc = n % 10;
		 if (uc != 3 &&  uc%2!=0 ) {
			    
			 nr = nr + uc * p;
		     p = p * 10;

		 }
		  
		 n = n / 10;
		 
	 }
	 return nr;
 }
 void sol18(int m, int v[]) {
	 for (int i = 0;i < m;i++) {
		 cout << stergereCif3sauPara(v[i]);
		 cout << " ";
	 }
 }

 //ex 3 e)
 int ctNrPrimeNuCuPoz(int m, int v[]) {
	 int ct = 0;
	 for (int i = 1;i < +m;i++) {
		 if (cmmdc(v[i], i) != 1 && ePrim(v[i]) == 1) {
			 ct++;
		 }
	 }
	 return ct;
 }

 //Ex 3f)
 int cmmmc(int n, int m) {
	 int p = n * m;
	 int cmmmc = p / cmmdc(n, m);
	 return cmmmc;
	  
 }
 int cmmmc2(int n, int m) {
	 int s = n;
	 while (s % m != 0) {
		 s = s + n;
	 }
	 return s;
 }
 
void sol19(int m, int v[]){
	 cout << cmmmc(v[7], v[11]);
	 }