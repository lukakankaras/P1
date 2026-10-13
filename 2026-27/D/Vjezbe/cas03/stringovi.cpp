#include <iostream>
#include <string>

using namespace std;

void print(const string& s) {
    cout << s << endl;
}

void flip(string& s) {
    int n = s.length();

    for(int i = 0; i < n/2; i++) {
        char temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
        // swap(s[i], s[n - 1 - i]);
    }
}

void flip2(string& s) {
    for(int i = 0; i < s.length() - 1; i += 2) {
        // cout << "(" << s[i] << "," << s[i + 1] << ")" << endl;
        swap(s[i], s[i + 1]);
    }
}

int main() {
    string s = "ABCD";
    flip2(s);
    cout << s << endl;

    // string s1 = "Milan";
    // cout << s1 << endl;
    //
    // string s2;
    // // cin >> s2;
    // getline(cin, s2);
    //
    // s2[2] = 'd';
    // cout << s2 << endl;
    // cout << s2.length() << endl;

    return 0;
}