#include <iostream>

using namespace std;

// https://github.com/lukakankaras

/*

MxN

1 8  9 13
2 7 10 14
3 6 11 15
4 5 12 16

i = f(takt)

0         1         2
0 1 2 3   0 1 2 3   8 9 10 11
0 1 2 3   3 2 1 0   0 1 2  3  3 2 1 0

*/
void popunjavanjeMatrice() {
    int r, k;
    cin >> r >> k;

    int mat[r][k];
    int counter = 1;

    while(counter <= r * k) {
        int takt = counter - 1;

        int i;
        if(takt / k % 2 == 0) {
            i = takt % k;
        } else {
            i = (k - 1) - (takt % k);
        }

        int j = takt / k;

        // cout << i << " " << j << endl;

        mat[i][j] = counter++;

        // takt govori koja je iteracija petlje

        // if(takt % k == k - 1) {
        //     j += 1;
        // }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < k; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// bool jeLiLokalniMaksimum(int** niz)

bool jeLiLokalniMaksimum(int* mat[], int r, int k, int i, int j) {
    if(i != 0 && mat[i][j] <= mat[i - 1][j]) {
        return false;
    }
    if(i != r - 1 && mat[i][j] <= mat[i + 1][j]) {
        return false;
    }
    if(j != 0 && mat[i][j] <= mat[i][j - 1]) {
        return false;
    }
    if(j != k - 1 && mat[i][j] <= mat[i][j + 1]) {
        return false;
    }

    return true;
}

void zad50() {
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

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < k; j++) {
            if(jeLiLokalniMaksimum(mat, r, k, i, j)) {
                cout << "(i: " << i << ", j: " << j << ", v: " << mat[i][j] << ")" << endl;
            }
        }
    }

    for(int i = 0; i < r; i++) {
        delete[] mat[i];
    }
}

int main() {
    zad50();
    return 0;
}