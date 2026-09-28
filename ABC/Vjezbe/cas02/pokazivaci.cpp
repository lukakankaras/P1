#include <iostream>

using namespace std;

void povecaj(int x) {
    printf("Adresa od x unutar funkcije: %p\n", &x);
    x = x + 1;
}

void povecaj2(int* x) {
    // *x -> operator dereferenciranja
    // od adrese dobijamo vrijednost
    printf("Adresa od x unutar funkcije 2: %p\n", x);

    *x = *x + 1;
}

int main() {
    int x = 3;
    printf("Adresa od x u main:          %p\n", &x);
    povecaj2(&x);

    cout << x << endl;
    return 0;




    // 0x7ffc0cd88e9c
    //  Adresa je (u vecini slucajeva) 64-bitni broj
    // int y = -x;
    // x -> vrijednost od x
    // &x -> adresa od x
    // pokazivac cuva adresu
    int* pokazivac = &x;

    printf("Vrijednost x: %d\n", x);
    printf("Adresa od x: %p\n", pokazivac);

    return 0;
}