// zad-vjezbe13-01.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <thread>
using namespace std;

void transponiraj(int** mat, int **transponirana, int poc, int kraj) {
    int i, j;
    for (i = 0; i < poc; i++) {
        for (j = 0; j < kraj; j++) {
            transponirana[j][i] = mat[i][j];
        }
    }
}

void transponirajParal(int** mat, int **transponirana, int poc, int kraj, int n) {
    int i, j;
    for (i = poc; i < kraj; i++) {
        for (j = 0; j < n; j++) {
            transponirana[i][j] = mat[i][j];
        }
    }
}
int main()
{
    int** mat, int **transponirana;
    thread t[4];

    mat = new int* [20];
    for (int i = 0; i < 20; i++) {
        mat[i] = new int[35];
    }
    transponirana = new int* [35];
    for (int i = 0; i < 35; i++) {
        transponirana[i] = new int[20];
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 35; j++) {
            mat[i][j] = rand() % 100;
        }
    }

    transponiraj(mat, transponirana, 20, 35);

    for (int i = 0; i < 4; i++) {
        int korak = 20 / 4;
        t[i] = thread(transponirajParal, mat, transponirana, 35, i * korak, (i + 1) * korak);
    }
    for (int i = 0; i < 4; i++) {
        t[i].join();
    }
    for (int i = 0; i < 5; i++) {
        cout << "\n\n"<<endl;
        for (int j = 0; j < 5; j++) {
            cout << mat[i][j] << ", ";
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << "\n\n" << endl;
        for (int j = 0; j < 5; j++) {
            cout << transponirana[i][j] << ", ";
        }
    }
    return 0;
}


