// Vj4zad1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Dekompozicijom domene paralelno izvr�iti pretragu najve�eg elementa niza

#include <iostream>
#include <thread>
using namespace std;

void maxInt(int* niz, int rez[], int poc, int brEl, int id) {
    int max = niz[poc];
    int kraj = poc + brEl;
    for (int i = poc; i < kraj; i++) {
        if (max < niz[i]) {
            max = niz[i];
        }
    }
    rez[id] = max;
}

int main()
{
    int* niz, n = 100, rez[4] , max;
    thread t1, t2;

    niz = new int[n];
    for (int i = 0; i < n; i++) {
        niz[i] = rand();
        cout << niz[i] << ", ";
    }

    t1 = thread(maxInt, niz, rez, 0, 50, 0);
    t2 = thread(maxInt, niz, rez, 50, 50, 1);
    t1.join();
    t2.join();

    cout << "\nNajveci broj 1. podniza: " << rez[0] << endl;
    cout << "\nNajveci broj 2. podniza: " << rez[1] << endl;

    if (rez[0] > rez[1]) {
        max = rez[0];
    }
    else {
        max = rez[1];
    }
    cout << "\nMaksimum je: " << max << endl;
    delete[] niz;
    system("pause");
    return 0;
}


