#include <iostream>
#include <forward_list>

using namespace std;

/*
bool nasKomparator(const int& a, const int& b) {
    // true if a < b
    // false
    return a < b;
}
*/

int main() {
    forward_list<int> l = { 1, 2, 3, 4 };

    /*forward_list<int>::iterator it = l.begin();

    cout << *it << endl;

    *it = 5;

    cout << *it << endl;
    */

    /*auto i = l.begin();

    for(auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;*/

    /*l.sort([](const int& a, const int& b) -> bool {
        return a % 2 < b % 2;
    });*/

    int x = 5;

    l.remove_if([](const int& a) -> bool {
        return a % 2 == 0;
    });

    // for(auto it = l.begin(); it != l.end(); ++it) {
    //     cout << *it << " ";
    // }

    for(int i : l) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}