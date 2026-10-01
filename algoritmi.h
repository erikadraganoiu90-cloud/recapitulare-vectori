#ifndef ALGORITMI_H_INCLUDED
#define ALGORITMI_H_INCLUDED

#include <iostream>

using namespace std;

void afisare(int v[], int d)
{
    for (int i = 0; i < d; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int pozMinim(int v[], int d)
{
    int poz = 0;
    for (int i = 1; i < d; i++)
    {
        if (v[i] < v[poz])
        {
            poz = i;
        }
    }

    return poz;
}

int pozMaxim(int v[], int d)
{
    int poz = 0;
    for (int i = 1; i < d; i++)
    {
        if (v[i] > v[poz])
        {
            poz = i;
        }
    }

    return poz;
}

int cautareBinara(int v[], int d, int key)
{
    int inf = 0;
    int sup = d - 1;

    while (inf <= sup)
    {
        int mij = inf + (sup - inf) / 2;
        if (v[mij] == key)
        {
            return mij;
        }
        if (v[mij] < key)
        {
            inf = mij + 1;
        }
        else
        {
            sup = mij - 1;
        }
    }

    return -1;
}

void sortareCrescator(int v[], int d)
{
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
            }
        }
    }
}

void sortareDescrescator(int v[], int d)
{
    bool sortat = false;
    while (sortat == false)
    {
        sortat = true;
        for (int i = 0; i < d - 1; i++)
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

void sortareSelectie(int v[], int d)
{
    for (int i = 0; i < d - 1; i++)
    {
        int pmin = i;
        for (int j = i + 1; j < d; j++)
        {
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
    }
}

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
}

void sortareVale(int v[], int d, int varf)
{
    sortareIntervalDescrescator(v, 0, varf);
    sortareInterval(v, varf, d - 1);
}

void interclasare(int a[], int da, int b[], int db, int c[], int& dc)
{
    int i = 0;
    int j = 0;
    dc = 0;

    while (i < da && j < db)
    {
        if (a[i] <= b[j])
        {
            c[dc] = a[i];
            i++;
        }
        else
        {
            c[dc] = b[j];
            j++;
        }
        dc++;
    }

    while (i < da)
    {
        c[dc] = a[i];
        i++;
        dc++;
    }

    while (j < db)
    {
        c[dc] = b[j];
        j++;
        dc++;
    }
}

void stergereElement(int v[], int& d, int poz)
{
    for (int i = poz; i < d - 1; i++)
    {
        v[i] = v[i + 1];
    }
    d--;
}

void inserareElement(int v[], int& d, int poz, int elem)
{
    for (int i = d; i > poz; i--)
    {
        v[i] = v[i - 1];
    }
    v[poz] = elem;
    d++;
}

void ceaMaiLungaSecventaEgale(int v[], int d, int& start, int& lungime)
{
    start = -1;
    lungime = 0;

    for (int i = 0; i < d; i++)
    {
        int j = i;
        while (j + 1 < d && v[j + 1] == v[i])
        {
            j++;
        }

        if (j - i + 1 > lungime)
        {
            start = i;
            lungime = j - i + 1;
        }

        i = j;
    }
}

int pozitieSecventa(int v[], int d, int y[], int dy)
{
    for (int i = 0; i <= d - dy; i++)
    {
        bool potrivire = true;
        for (int j = 0; j < dy; j++)
        {
            if (v[i + j] != y[j])
            {
                potrivire = false;
                break;
            }
        }

        if (potrivire)
        {
            return i;
        }
    }

    return -1;
}

bool existaSecventaCuSuma(int v[], int d, int s, int& start, int& lungime)
{
    start = -1;
    lungime = 0;

    int stanga = 0;
    int suma = 0;

    for (int i = 0; i < d; i++)
    {
        suma = suma + v[i];

        while (suma > s && stanga <= i)
        {
            suma = suma - v[stanga];
            stanga++;
        }

        if (suma == s)
        {
            start = stanga;
            lungime = i - stanga + 1;
            return true;
        }
    }

    return false;
}

int sumaMaximaSecventa(int v[], int d, int& start, int& lungime)
{
    start = -1;
    lungime = 0;

    if (d == 0)
    {
        return 0;
    }

    int sumaMax = v[0];
    int suma = v[0];
    int stangaCurent = 0;
    start = 0;
    lungime = 1;

    for (int i = 1; i < d; i++)
    {
        if (suma < 0)
        {
            suma = v[i];
            stangaCurent = i;
        }
        else
        {
            suma = suma + v[i];
        }

        if (suma > sumaMax)
        {
            sumaMax = suma;
            start = stangaCurent;
            lungime = i - stangaCurent + 1;
        }
    }

    return sumaMax;
}

void frecventaValori(int v[], int d, int f[], int valoareMax)
{
    for (int i = 0; i <= valoareMax; i++)
    {
        f[i] = 0;
    }

    for (int i = 0; i < d; i++)
    {
        if (v[i] >= 0 && v[i] <= valoareMax)
        {
            f[v[i]]++;
        }
    }
}

void frecventaCifre(int v[], int d, int f[])
{
    for (int i = 0; i <= 9; i++)
    {
        f[i] = 0;
    }

    for (int i = 0; i < d; i++)
    {
        int n = v[i];
        if (n < 0)
        {
            n = -n;
        }

        if (n == 0)
        {
            f[0]++;
        }

        while (n > 0)
        {
            f[n % 10]++;
            n = n / 10;
        }
    }
}

void exemple()
{
    cout << "--- afisare ---" << endl;
    int v1[100] = { 7, 2, 9, 4, 5 };
    int d1 = 5;
    afisare(v1, d1);

    cout << endl << "--- pozMinim / pozMaxim ---" << endl;
    cout << "vectorul: ";
    afisare(v1, d1);
    cout << "minimul " << v1[pozMinim(v1, d1)] << " pe pozitia " << pozMinim(v1, d1) << endl;
    cout << "maximul " << v1[pozMaxim(v1, d1)] << " pe pozitia " << pozMaxim(v1, d1) << endl;

    cout << endl << "--- cautareBinara (cere vector sortat) ---" << endl;
    int v2[100] = { 5, 10, 14, 16, 19, 21, 26 };
    int d2 = 7;
    cout << "vectorul: ";
    afisare(v2, d2);
    cout << "19 -> pozitia " << cautareBinara(v2, d2, 19) << endl;
    cout << "20 -> pozitia " << cautareBinara(v2, d2, 20) << " (nu exista)" << endl;

    cout << endl << "--- sortareCrescator ---" << endl;
    int v3[100] = { 32, 56, 19, 42 };
    int d3 = 4;
    cout << "inainte: ";
    afisare(v3, d3);
    sortareCrescator(v3, d3);
    cout << "dupa:    ";
    afisare(v3, d3);

    cout << endl << "--- sortareDescrescator ---" << endl;
    int v4[100] = { 32, 56, 19, 42 };
    int d4 = 4;
    cout << "inainte: ";
    afisare(v4, d4);
    sortareDescrescator(v4, d4);
    cout << "dupa:    ";
    afisare(v4, d4);

    cout << endl << "--- sortareSelectie ---" << endl;
    int v5[100] = { 8, 2, 9, 4, 5, 7 };
    int d5 = 6;
    cout << "inainte: ";
    afisare(v5, d5);
    sortareSelectie(v5, d5);
    cout << "dupa:    ";
    afisare(v5, d5);

    cout << endl << "--- sortareInterval (doar pozitiile 1..3) ---" << endl;
    int v6[100] = { 50, 8, 2, 9, 4, 1 };
    int d6 = 6;
    cout << "inainte: ";
    afisare(v6, d6);
    sortareInterval(v6, 1, 3);
    cout << "dupa:    ";
    afisare(v6, d6);

    cout << endl << "--- sortareIntervalDescrescator (doar pozitiile 1..3) ---" << endl;
    int v7[100] = { 50, 8, 2, 9, 4, 1 };
    int d7 = 6;
    cout << "inainte: ";
    afisare(v7, d7);
    sortareIntervalDescrescator(v7, 1, 3);
    cout << "dupa:    ";
    afisare(v7, d7);

    cout << endl << "--- sortareMunte (varful pe pozitia 3) ---" << endl;
    int v8[100] = { 99, 31, 54, 16, 17, 63 };
    int d8 = 6;
    cout << "inainte: ";
    afisare(v8, d8);
    sortareMunte(v8, d8, 3);
    cout << "dupa:    ";
    afisare(v8, d8);

    cout << endl << "--- sortareVale (varful pe pozitia 3) ---" << endl;
    int v9[100] = { 99, 31, 54, 16, 17, 63 };
    int d9 = 6;
    cout << "inainte: ";
    afisare(v9, d9);
    sortareVale(v9, d9, 3);
    cout << "dupa:    ";
    afisare(v9, d9);

    cout << endl << "--- interclasare (cere ambii vectori sortati) ---" << endl;
    int a[100] = { 1, 4, 7, 9 };
    int da = 4;
    int b[100] = { 2, 3, 8 };
    int db = 3;
    int c[200];
    int dc = 0;
    cout << "a: ";
    afisare(a, da);
    cout << "b: ";
    afisare(b, db);
    interclasare(a, da, b, db, c, dc);
    cout << "c: ";
    afisare(c, dc);

    cout << endl << "--- stergereElement (pozitia 2) ---" << endl;
    int v10[100] = { 12, 54, 21, 76, 32 };
    int d10 = 5;
    cout << "inainte: ";
    afisare(v10, d10);
    stergereElement(v10, d10, 2);
    cout << "dupa:    ";
    afisare(v10, d10);
    cout << "dimensiunea a devenit " << d10 << endl;

    cout << endl << "--- inserareElement (99 pe pozitia 2) ---" << endl;
    int v11[100] = { 12, 54, 21, 76, 32 };
    int d11 = 5;
    cout << "inainte: ";
    afisare(v11, d11);
    inserareElement(v11, d11, 2, 99);
    cout << "dupa:    ";
    afisare(v11, d11);
    cout << "dimensiunea a devenit " << d11 << endl;

    cout << endl << "--- ceaMaiLungaSecventaEgale ---" << endl;
    int v12[100] = { 5, 5, 1, 1, 1, 1, 2, 2 };
    int d12 = 8;
    int start = 0;
    int lungime = 0;
    cout << "vectorul: ";
    afisare(v12, d12);
    ceaMaiLungaSecventaEgale(v12, d12, start, lungime);
    cout << "incepe pe pozitia " << start << ", are lungimea " << lungime << endl;

    cout << endl << "--- pozitieSecventa ---" << endl;
    int v13[100] = { 8, 5, 8, 5, 2, 3, 10, 7 };
    int d13 = 8;
    int y[100] = { 5, 2, 3 };
    int dy = 3;
    cout << "vectorul: ";
    afisare(v13, d13);
    cout << "cautam:   ";
    afisare(y, dy);
    cout << "gasita pe pozitia " << pozitieSecventa(v13, d13, y, dy) << endl;

    cout << endl << "--- existaSecventaCuSuma (cere elemente pozitive) ---" << endl;
    int v14[100] = { 12, 10, 15, 7, 17 };
    int d14 = 5;
    cout << "vectorul: ";
    afisare(v14, d14);
    if (existaSecventaCuSuma(v14, d14, 32, start, lungime))
    {
        cout << "suma 32 se obtine din pozitia " << start << ", pe " << lungime << " elemente" << endl;
    }
    else
    {
        cout << "nu exista secventa cu suma 32" << endl;
    }

    cout << endl << "--- sumaMaximaSecventa (merge si cu numere negative) ---" << endl;
    int v15[100] = { -4, 1, -5, 1, 4, -2, 2, 3, -4 };
    int d15 = 9;
    cout << "vectorul: ";
    afisare(v15, d15);
    int sm = sumaMaximaSecventa(v15, d15, start, lungime);
    cout << "suma maxima " << sm << ", din pozitia " << start << ", pe " << lungime << " elemente" << endl;

    cout << endl << "--- frecventaValori ---" << endl;
    int v16[100] = { 5, 5, 5, 2, 2, 7 };
    int d16 = 6;
    int f[101];
    cout << "vectorul: ";
    afisare(v16, d16);
    frecventaValori(v16, d16, f, 100);
    for (int i = 0; i <= 100; i++)
    {
        if (f[i] > 0)
        {
            cout << i << " apare de " << f[i] << " ori" << endl;
        }
    }

    cout << endl << "--- frecventaCifre ---" << endl;
    int v17[100] = { 21, 42, 21 };
    int d17 = 3;
    int fc[10];
    cout << "vectorul: ";
    afisare(v17, d17);
    frecventaCifre(v17, d17, fc);
    for (int i = 0; i <= 9; i++)
    {
        if (fc[i] > 0)
        {
            cout << "cifra " << i << " apare de " << fc[i] << " ori" << endl;
        }
    }
}

#endif // ALGORITMI_H_INCLUDED
