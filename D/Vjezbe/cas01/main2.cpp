#include <iostream>



void brojac() {
    static int x = 0;
    x += 1;
    std::cout << x << std::endl;
}

int sabiranje(int a, int b) {
    int resultat = a + b;
    return resultat;
}

int main() {
    // int x;
    // std::cin >> x;

    // for(; x > 0; x /= 10) {
        // std::cout << x % 10 << std::endl;
    // }
    int x, y;

    std::cin >> x >> y;

    std::cout << sabiranje(x, y) << std::endl;
    // int a = 3;
    // int b = 2;
    //
    // brojac();
    // brojac();
    // if(1 < 2) {
    //     int y = 0;
    // }

    return 0;
}




// lukankaras.ucg@gmail.com
// https://github.com/lukakankaras/P1