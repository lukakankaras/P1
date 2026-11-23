#include <iostream>
#include <forward_list>

// it -> 1
// next_it -> 3

// 1 2 3 5

// it -> 1
// next_it -> 3

using namespace std;

void print_list(const forward_list<int>& l) {
    for(int i : l) {
        cout << i << " ";
    }
    cout << endl;
}

void zad44(forward_list<int>& l) {
    auto it = l.begin();

    while(it != l.end() && next(it) != l.end()) {
        auto next_it = next(it);
        l.insert_after(it, *next_it - *it);
        it = next_it;
    }
}

void zad45(forward_list<int>& l, int k) {
    for(auto it = l.begin(); it != l.end(); ++it) {
        if(*it % k == 0) {
            l.insert_after(it, -1);
            ++it;
        }
    }
}

int zad51(const forward_list<int>& l) {
    auto it_slow = l.begin();
    auto it_fast = l.begin();

    while(it_slow != l.end()) {
        ++it_slow;
        if(it_slow != l.end()) {
            ++it_slow;
            if(it_slow != l.end()) {
                ++it_fast;
            }
        }
    }

    if(it_fast != l.end()) return *it_fast;
    return 0;
}

bool zad55(const forward_list<int>& l) {
    forward_list<int> l_inv;

    for(int e : l) {
        l_inv.push_front(e);
    }

    auto it_1 = l.begin();
    auto it_2 = l_inv.begin();

    while(it_1 != l.end()) {
        if(*it_1 != *it_2) return false;
        ++it_1;
        ++it_2;
    }

    return true;
}

int main() {
    forward_list<int> l = { 1, 2, 2, 1 };
    cout << zad55(l) << endl;

    return 0;
}