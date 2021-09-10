// zad-vjezbe15-12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Napisati zadatak kojim æemo funkcijskom dekompozicijom paralelizirati
//trazenje srednje vrijednosti i medijana nad
//nizom od N elemenata.

#include <iostream>
#include <thread>
using namespace std;

void findAvg(int* niz, int N, float* ret) {
    int suma = 0;
    float avg;
    for (int i = 0; i < N; i++) {
        suma = suma + niz[i];
    }
    avg = (float)suma / N;
    *ret = avg;
}

void medijan(int* niz, int N, float* ret) {
    for (int i = 0; i < N-1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (niz[i] > niz[j]) {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
    if (N % 2 == 1) {
        *ret = niz[N / 2 + 1];
    }
    else {
        int suma = niz[N / 2] + niz[N / 2 + 1];
        *ret = (float)suma / 2;
    }
}

int main()
{
    int* niz;
    int N = 100;
    float avg = 0, median = 0;
    thread t1, t2;

    niz = new int[N];
    for (int i = 0; i < N; i++) {
        niz[i] = rand() % N - N / 2;
    }
    t1 = thread(findAvg, niz, N, &avg);
    t2 = thread(medijan, niz, N, &median);
    t1.join();
    t2.join();

    cout << "Prosjecna vrijednost: " << avg << endl;
    cout << "Medijan je: " << median << endl;

    delete[] niz;
    system("pause");
    return 0;
}


