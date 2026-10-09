#include <iostream>

using namespace std;

int main() {
    int r, k;
    cin >> r >> k;

    // int** mat = new int*[r];
    int* mat[r];
    // int niz[r];

    for(int i = 0; i < r; i++) {
        mat[i] = new int[k];
    }

    cout << "i j" << endl;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < k; j++) {
            cin >> mat[i][j];
            // cout << i << " " << j << endl;
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < k; j++) {
            // cout << mat[i][j] << " ";
            cout << "(" << mat[i][j] << " " << &mat[i][j] << ") ";
        }
        cout << endl;
    }

    return 0;
}