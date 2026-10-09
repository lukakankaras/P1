#include <iostream>

using namespace std;

int nasaFunkcija(int a, int b) {
    int s = 3;

    return a + b;
}

void brojac() { // Static mijenja ponasanje promijenjive unutar funkcije
    static int x = 0;
    x = x + 1;
    cout << x << endl;
} // x ce imati vrijednost na pocetku funkcije koju je imao na kraju proslog poziva

int main() {
    brojac();
    brojac();
    return 0;
}