#include <iostream>
#include <limits.h>

using namespace std;

int* fibonachi(int velicina) {
    int* niz = new int[velicina];
    niz[0] = 1;
    niz[1] = 1;

    for(int i = 2; i < velicina; i++) {
        niz[i] = niz[i - 1] + niz[i - 2];
    }

    return niz; // niz je pokazivac na prvi element
}

int main() {
    // int n;
    // cin >> n;
    //
    // int* niz = fibonachi(n);
    //
    // for(int i = 0; i < n; i++) {
    //     cout << niz[i] << endl;
    // }
    //
    // delete[] niz;

    int x = INT_MAX;
    cout << x << endl;

    x = x + 1;

    cout << x << endl;

    return 0;
}