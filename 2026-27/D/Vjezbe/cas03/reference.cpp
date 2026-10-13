#include <iostream>
#include <string>

using namespace std;

void func0(const int x) {

}

void func1(int* x) {
    if(x != nullptr) {
        // cout << "Func: " << &x << endl;
        *x = *x + 1;
    }
}

void func2(int& b) {
    cout << "Func2: " << &b << endl;
    b = b + 1;
}

void func3(const int& c) {
    cout << &c << " " << c << endl;
}

int main() {
    // int b = 5;
    // int* ptr = &b;
    //
    // *ptr += 1;
    // cout << b << endl;

    int* ptr = nullptr;

    int a = 0;
    cout << &a << endl;
    func3(5);

    return 0;
}