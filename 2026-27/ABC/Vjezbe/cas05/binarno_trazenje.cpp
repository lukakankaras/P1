#include <iostream>
#include <limits.h>

using namespace std;

int main() {

    int n = 5;
    int niz[5] = {1, 2, 3, 5, 4};

    // Selection sort
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(niz[i] > niz[j]) {
                swap(niz[i], niz[j]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;

    int trazeni = 4;

    return 0;
}
