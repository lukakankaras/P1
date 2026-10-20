#include <iostream>

using namespace std;

void printMatrix(int* mat, int r, int k) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < k; j++) {
            cout << mat[i * r + j] << " ";
        }
        cout << endl;
    }
}

void printMatrix2(int* mat[], int r, int k) {
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < k; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    /*int mat[2][2]; // Stack allocation

    for(int i = 0; i < 2; i++) { // For koji prolazi kroz redove
        for(int j = 0; j < 2; j++) { // For koji prolazi kroz kolone
            cin >> mat[i][j];
        }
    }

    printMatrix(2, 2, mat);*/


    // int* niz = new int[5];

    int r, k;
    cin >> r >> k;

    int* mat[r];

    for(int i = 0; i < r; i++) {
        mat[i] = new int[k];
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < k; j++) {
            cin >> mat[i][j];
        }
    }

    printMatrix2(mat, r, k);

    for(int i = 0; i < r; i++) {
        delete[] mat[i];
    }


    /*int** mat = new int*[5];

    for(int i = 0; i < 5; i++) {
        mat[i] = new int[5];
    }

    for(int i = 0; i < 5; i++) { // For koji prolazi kroz redove
        for(int j = 0; j < 5; j++) { // For koji prolazi kroz kolone
            cin >> mat[i][j];
        }
    }



    for(int i = 0; i < 5; i++) {
        delete[] mat[i];
    }

    delete[] mat;*/

    return 0;
}