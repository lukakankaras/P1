#include <iostream>
#include <cmath>

using namespace std;

// f = (9/5)*c + 32
// C = (F - 32)*5/9

void zad01() {
    double f;
    cin >> f;

    double c = (f - 32) * 5 / 9;
    cout << c << endl;
}

/* Napisati program koji učitava prirodan n manji od 1000 i štampa njegove proste
faktore. Na primjer, za broj 60 prosti faktori su 2, 3 i 5. */
void zad10() {
    int n;
    cin >> n;

    int i = 2;
    while(n != 1) {
        bool divisible = false;
        while(n % i == 0) {
            n /= i;
            divisible = true;
        }
        if(divisible) {
            cout << i << endl;
        }
        i++;
    }
}

void zad13() {
    int n;
    cin >> n;

    double s = 0;

    for(int i = 1; i <= n; i++) {
        s += -1.0 * (i % 2 * 2 - 1) / i;
    }

    cout << s << endl;
}

int faktorijel(int x) {
    int p = 1;
    for(int i = 1; i <= x; i++) {
        p *= i;
    }
    return p;
}

void zad15() {
    double x;
    cin >> x;
    int n;
    cin >> n;

    double s = 0;
    int p = 1;
    for(int i = 1; i <= n; i++) {
        p *= i;
        s += (i % 2 == 0 ? -1 : 1) * pow(sin(x - 2), 2) / p;
    }

    cout << s << endl;
}

void zad17() {
    int h, w;
    cin >> h >> w;

    for(int i = 0; i < h; i++) { // po redovima
        for(int j = 0; j < w; j++) { // po kolonama
            if(i == 0 || j == 0 || i == h - 1 || j == w - 1) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

void zad28() {
    int n;
    cin >> n;

    int niz[n];
    for(int i = 0; i < n; i++) {
        cin >> niz[i];
    }

    int res[2*n];
    for(int i = 0; i < n; i++) {
        res[2 * i] = niz[i];
        res[2 * i + 1] = niz[i];
    }

    for(int i = 0; i < 2 * n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void zad29() {
    int n;
    cin >> n;

    int niz[n];
    for(int i = 0; i < n; i++) {
        cin >> niz[i];
    }

    int i = 0;
    int j = n - 1;

    while(i < j) {
        while(niz[i] % 2 == 0) i += 1;
        while(niz[j] % 2 == 1) j -= 1;

        if(i < j) {
            int temp = niz[i];
            niz[i] = niz[j];
            niz[j] = temp;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << niz[i] << " ";
    }
    cout << endl;
}

void zad49() {
    int n;
    cin >> n;

    int mat[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    bool sim = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(mat[i][j] != mat[j][i]) {
                sim = false;
                break;
            }
        }
        if(!sim) break;
    }

    cout << (sim ? "DA" : "NE") << endl;
}

int main() {
    zad49();

    return 0;
}