#include <iostream>

/*namespace MyNamespace {
    int x; // MyNamespace::x
    void print() {
        std::cout << "Hello world" << std::endl;
    } // MyNamespace::print

    void f2() {
        print();
    }
}*/

using namespace std;

int sabiranje(int x, int y) {
    return x + y;
}

void stampa() {
    static int x = 0; // Inicijalno dodjeljivanje vrijednosti samo jednom
    x = x + 1;
    cout << "Vrijednost x je: " << x << endl;
}

int main() {

    /*int a, b;
    cin >> a >> b;

    cout << "Zbir: " << sabiranje(a, 5) << endl;
    */

    return 0;
}