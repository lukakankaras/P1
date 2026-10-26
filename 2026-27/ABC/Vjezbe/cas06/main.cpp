#include <iostream>

using namespace std;

bool pripada(char x, string s) {
    for(char c : s) {
        if(x == c) return true;
    }
    return false;
}

void zad01() {
    string s;
    cin >> s;

    // for(int i = 0; i < s.length(); i++) {
    //     // s[i]
    // }

    string samoglasnici = "aeiouAEIOU";

    for(char c : s) {
        if(pripada(c, samoglasnici)) cout << c;
    }

    for(char c : s) {
        if(!pripada(c, samoglasnici)) cout << c;
    }
    cout << endl;
}

void zad02() {
    string s;
    getline(cin, s);

    for(char& c : s) {
        if(c >= 'A' && c <= 'Z') {
            // cout << c << endl;
            c += ('a' - 'A');
        }
    }

    cout << s << endl;
}

void increment(int& a) {
    a = a + 1;
}

bool ciklicno(const string& s, const string& t, int k) {
    if(s.length() != t.length()) return false;

    int n = s.length();

    k = k % n;

    bool udesno = true;
    for(int i = 0, j = n - k; i < n; i++, j = (j + 1) % n) {
        if(s[i] != t[j]) {
            udesno = false;
            break;
        }
    }



    bool ulijevo = true;
    for(int i = 0, j = k; i < n; i++, j = (j + 1) % n) {
        if(s[i] != t[j]) {
            ulijevo = false;
            break;
        }
    }

    return udesno || ulijevo;

    // 0123
    // ABCDEFG
    // GABCDEF
    // BCDEFGA

    // k = 2

    // 0 - 2
    // 1 - 3
    // 2 - 0
    // 3 - 1

    // 0123
    // CDAB
}

void zad08() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int k;
    cin >> k;

    cout << ciklicno(s1, s2, k) << endl;
}

int main() {
    zad08();
    return 1;
}