// Vj4zad3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <thread>
using namespace std;

void findMax(int* niz, int* rez, int poc, int brEl) {
	int max = niz[poc];
	for (int i = poc; i < poc + brEl; i++) {
		if (niz[i] > max) {
			max = niz[i];
		}
		*rez = max;
	}
}

int main()
{
	int* niz, n = 100, max[4];
	thread t1, t2, t3, t4;

	niz = new int[n];
	for (int i = 0; i < n; i++) {
		niz[i] = rand();
		cout << niz[i] << " ";
	}
	t1 = thread(findMax, niz, &max[0], 0, 25);
	t2 = thread(findMax, niz, &max[1], 25, 25);
	t3 = thread(findMax, niz, &max[2], 50, 25);
	t4 = thread(findMax, niz, &max[3], 75, 25);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	for (int i = 0; i < 4; i++) {
		cout << "\nMaksimum je: " << i + 1 << ". podniza je: " << max[i] << endl;
	}

	delete[] niz;

	system("pause");
	return 0;


}
