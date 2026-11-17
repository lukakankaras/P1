#include <iostream>

using namespace std;

struct Point {
    float y = 0;
    char a;
    char x;
};

void print_point(Point p) {
    cout << p.x << " " << p.y << endl;
}

Point& add_1(Point& p) {
    cout << &p << endl;

    p.x += 1;
    p.y += 1;
    return p;
}

int main() {
    Point p{1, 2};
    cout << &p << endl;

    Point& p2 = add_1(p);
    cout << &p2 << endl;

    print_point(p);

    // cout << alignof(Point) << endl;

    return 0;
}