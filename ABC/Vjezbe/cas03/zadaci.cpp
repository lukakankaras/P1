#include <iostream>

using namespace std;

// Lokalni maksimum - niz
void zad01() {
    int n;
    cin >> n;

    int niz[n];
    for(int i = 0; i < n; i++) {
        cin >> niz[i];
    }

    for(int i = 0; i < n; i++) {
        bool veciOdLijevog = i == 0 || niz[i] > niz[i-1];
        bool veciOdDesnog = i == n-1 || niz[i] > niz[i+1];

        /*if(i == 0 || niz[i] > niz[i-1]) {
            veciOdLijevog = true;
        }
        if(i == n-1 || niz[i] > niz[i+1]) {
            veciOdDesnog = true;
        }*/

        if(veciOdLijevog && veciOdDesnog) {
            cout << niz[i] << endl;
        }
    }
}



int main() {
    zad01();
    return 0;
}