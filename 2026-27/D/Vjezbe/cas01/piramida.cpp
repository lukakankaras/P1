#include <iostream>

void red(int br) {
    for(int i = 0; i < br; i++) {
        std::cout << "* ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    for(int i = 1; i <= n / 2 + 1; i++) {
        red(i);
    }
    for(int i = n / 2; i >= 1; i--) {
        red(i);
    }


    return 0;
}