#include <iostream>

using namespace std;

void stampajNiz(int* niz, int n) {
    for(int i = 0; i < n; i++) {
        cout << &(niz[i]) << " " << niz[i] << "\n";
    }
}

void zad01(int niz[], int n) {
    for(int i = 0; i < n; i++) {
        if(niz[i] % 2 == 0) { // paran
            niz[i] = niz[i] * 2; // niz[i] *= 2;
        } else { // neparan
            niz[i] += 3;
        }

        cout << niz[i] << " ";
    }
    cout << endl;
}

int* zad02(int n) { // Pravimo fibbonachi niz
    // int niz[n];
    int* niz = new int[n]; // U C alternativa je malloc()
    niz[0] = 1;
    niz[1] = 1;

    for(int i = 2; i < n; i++) {
        niz[i] = niz[i - 1] + niz[i - 2];
    }

    return niz;
}

int main() {
    int n = 30;

    int* fib = zad02(n);
    stampajNiz(fib, n);
    delete[] fib; // Ako je niz ono sto brisemo, ide delete[], inace ide samo delete

    /*int n; // velicina niza
    cin >> n;

    int niz[n];
    for(int i = 0; i < n; i++) {
        cin >> niz[i];
    }

    zad01(niz, n);*/

    // int* == int[]
    // int niz1[] = {1, 2, 3, 4, 5}; // U pozadini je to int* koji ukazuje na prvi element
    // cout << "Adresa prvog elementa: " << &niz1[0] << endl;
    // stampajNiz(niz1, 5);

    return 0;
}
