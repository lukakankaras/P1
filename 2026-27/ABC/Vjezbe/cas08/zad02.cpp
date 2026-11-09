#include <iostream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int a[m];
    int prvi_elem[m];

    int p = 1;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        prvi_elem[i] = p;
        p += a[i];
    }

    for(int i = 0; i < k; i++) {
        int trazeni;
        cin >> trazeni;

        int pocetak = 0, kraj = 4;
        // g0 g1 g2 g3 g4

        bool nasli = false;

        while(pocetak <= kraj) {
            int pola = (pocetak + kraj) / 2;

            if(prvi_elem[pola] <= trazeni && trazeni <= prvi_elem[pola] + a[pola] - 1) {
                cout << "Nasli smo ga u grupi " << pola << endl;
                nasli = true;
                break;
            } if(trazeni < prvi_elem[pola]) {
                kraj = pola - 1;
            } else {
                pocetak = pola + 1;
            }
        }

        if(!nasli) cout << "Nijesmo ga nasli" << endl;
    }



    return 0;
}

/*

t = ?

t <= t'

X' = Y' = max(X, Y)

t' = n * X' / 2

t = [1, ..., n * X' / 2]

*/