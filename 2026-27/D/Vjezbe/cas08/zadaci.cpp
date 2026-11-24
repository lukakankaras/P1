#include <iostream>
#include <forward_list>

using namespace std;

void print_list(const forward_list<int>& l) {
    for(int x : l) {
        cout << x << " ";
    }
    cout << endl;
}

void zad44(forward_list<int>& l) {
    if(l.begin() == l.end()) return;

    auto it = l.begin();
    while(next(it) != l.end()) {
        l.insert_after(it, *next(it) - *it);
        advance(it, 2);
    }
}

void zad45(forward_list<int>& l, int k) {
    for(auto it = l.begin(); it != l.end(); ++it) {
        if(*it % k == 0) {
            l.insert_after(it, -1);
        }
    }
}

int main() {
    forward_list<int> l = { 1, 3, 5 };

    print_list(l);
    zad44(l);
    print_list(l);

    return 0;
}