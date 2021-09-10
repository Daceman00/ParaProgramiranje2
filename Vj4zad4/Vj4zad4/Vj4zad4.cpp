// Vj4zad4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//napisati funkciju za aritmeti�ku sredinu
//i medijan

#include <iostream>
#include <thread>
using namespace std;

void artFunc(int* niz, int n, double* rez) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += niz[i];
    }
    *rez = suma/n;
}

void medFunc(int* niz, int n, int* rez) {
    int i, j, pom;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j <n;j++){
            if (niz[i] > niz[j]) {
                pom = niz[i];
                niz[i] = niz[j];
                niz[j] = pom;
            }
        }
    }
    *rez = niz[n / 2];
}

int main()
{
    int* niz, n = 99, med;
    double art;

    niz = new int[n];
    for (int i = 0; i < n; i++) {
        niz[i] = rand();
    }
    
    thread t1, t2;
    t1 = thread(artFunc, niz,n, &art);
    t2 = thread(medFunc, niz,n, &med);
    t1.join();
    t2.join();

    cout << "\nArtimeticka funkcija: " << art << endl;
    cout << "\nMedijan je: " << med << endl;

    delete[] niz;
    
    return 0;
}

