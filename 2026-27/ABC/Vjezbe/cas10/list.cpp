#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<int> l;

    int x = 5;

    l.push_front(4);
    l.push_front(5);
    l.push_front(3);

    // l.insert_after(l.before_begin(), 10);

    l.sort([](const int& a, const int& b) {
        return a < b;
    });

    for(forward_list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}