// #include "stdio.h"
#include <iostream>

int main() {
    // printf("Hello world\n");
    // System.out.println("String 1" + " " + "string 2")
    std::cout << "Hello world" << std::endl;

    int x = 0;

    std::cout << "x = " << x << std::endl;

    // std::cin >> x;

    // std::cout << "poslije unosa x = " << ++x << std::endl;
    // std::cout << "poslije unosa x = " << x++ << std::endl;

    int t1 = 3, t2 = 5;

    if(t1 < t2) {
        std::cout << "t1 je manje\n";
    }
    else if(t1 > t2) {
        std::cout << "t2 je manje\n";
    }
    else {
        std::cout << "jednaki su\n";
    }

    while(t1 < t2) {
        // t1 = t1 + 1;
        // t1++;
        // ++t1;
        t1 += 1;
    }
    std::cout << t1 << std::endl;

    for(int i = 0; i < 50; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}