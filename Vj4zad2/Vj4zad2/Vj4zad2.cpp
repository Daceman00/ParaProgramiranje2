// Vj4zad2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Napisati zadatak kojim �emo funkcijskom dekompozicijom paralelizirati
//tra�enje srednje vrijednosti i medijana nad
//nizom od 99 elemenata.

#include <iostream>
#include <thread>
using namespace std;

void findMed(int* niz, int* med, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (niz[i] > niz[j]) {
                int pom = niz[j];
                niz[j] = niz[i];
                niz[i] = pom;
            }
        }
        *med = niz[n / 2];
    }
}

void findArt(int* niz, double* art, int n) {
    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += niz[i];
    }
    *art = suma / n;
}

int main()
{
    int* niz, med, n=99;
    double art;
    thread t1, t2;

    niz = new int[n];
    for (int i = 0; i < n; i++) {
        niz[i] = rand();
        cout << niz[i] << ", ";
    }

    t1 = thread(findMed, niz, &med, n);
    t2 = thread(findArt, niz, &art, n);

    t1.join();
    t2.join();

    cout << "\nArtimeticka sredina je: " << art << endl;
    cout << "\nMedijan je: " << med << endl;

    delete[] niz;
    system("pause");
    return 0;



}


