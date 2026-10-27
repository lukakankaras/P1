#include <iostream>

using namespace std;

int suma_podmatrice(int* mat[], int start_i, int start_j, int p_r, int p_k) {
    int suma = 0;
    for(int i = start_i; i < start_i + p_r; i++) {
        for(int j = start_j; j < start_j + p_k; j++) {
            suma += mat[i][j];
        }
    }

    return suma;
}

void increment(int& x) {
    x = x + 1;
}

// x = 0
// increment(x)
// cout << x

void prodji_kroz_podmatrice_odredjene_dimenzije(int* mat[], int r, int k, int p_r, int p_k,
    int& max_sum, int& max_p_r, int& max_p_k, int& max_start_i, int& max_start_j) {

    for(int start_i = 0; start_i < r + 1 - p_r; start_i++) {
        for(int start_j = 0; start_j < k + 1 - p_k; start_j++) {

            // Sada kada imamo dimenziju i pocetak (gornji lijevi element)
            int suma = suma_podmatrice(mat, start_i, start_j, p_r, p_k);

            if(suma > max_sum) {
                max_sum = suma;
                max_p_r = p_r;
                max_p_k = p_k;
                max_start_i = start_i;
                max_start_j = start_j;
            }
        }
    }
}

void prodji_kroz_svake_dimenzije_podmatrica(int* mat[], int r, int k,
    int& max_sum, int& max_p_r, int& max_p_k, int& max_start_i, int& max_start_j) {

    for(int p_k = 1; p_k <= k; p_k++) {
        for(int p_r = 1; p_r <= r; p_r++) {
            // Sada za fiksiranu dimenziju p_r x p_k,
            // prolazimo kroz sve takve podmatrice

            // r + 1 - p_r - redova
            // k + 1 - p_k - kolona

            // cout << "============ Podmatrice dimenzija " << p_r  << "x" << p_k << endl;

            prodji_kroz_podmatrice_odredjene_dimenzije(
                mat, r, r, p_r, p_k, max_sum, max_p_r, max_p_k, max_start_i, max_start_j
            );
        }
    }
}

int main() {
    int* mat[5] = {
        new int[]{-5, -6,  3,  1,  0},
        new int[]{9,   7,  8,  3,  7},
        new int[]{-6, -2, -1,  2, -4}, // start_i = 2, start_j = 2
        new int[]{-7,  5,  5,  2, -6},
        new int[]{3,   2, -9, -5,  1}
    };

    int r = 5, k = 5;

    int max_sum = 0;
    int max_p_r = 0, max_p_k = 0, max_start_i = 0, max_start_j = 0;

    prodji_kroz_svake_dimenzije_podmatrica(
        mat, r, k, max_sum, max_p_r, max_p_k, max_start_i, max_start_j
    );

    for(int i = max_start_i; i < max_start_i + max_p_r; i++) {
        for(int j = max_start_j; j < max_start_j + max_p_k; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < r; i++) {
        delete[] mat[i];
    }

    return 0;
}