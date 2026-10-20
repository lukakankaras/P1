#include <iostream>

using namespace std;

void printZvijezdice(int x) {
    for(int i = 0; i < x; i++) {
        cout << "*";
    }
}

void zad03() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        printZvijezdice(i);
        cout << endl;
    }

    for(int i = n - 1; i >= 1; i--) {
        printZvijezdice(i);
        cout << endl;
    }
}

void zad05() {
    int br;
    cin >> br;

    int copy = br;

    int pojavljivanja[10] = {0};

    for(int c = copy % 10; copy > 0; copy /= 10, c = copy % 10) {
        pojavljivanja[c] += 1;
    }

    int max = -1;
    int maxCifra = -1;

    for(int i = 0; i < 10; i++) {
        if(pojavljivanja[i] > max) {
            max = pojavljivanja[i];
            maxCifra = i;
        }
    }

    cout << "Najvise ima cifara " << maxCifra << ": " << max << endl;
}

int main() {
    zad05();
    return 0;
}