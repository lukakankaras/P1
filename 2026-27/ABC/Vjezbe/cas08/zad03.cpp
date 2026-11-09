#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, X, Y;
    cin >> n >> X >> Y;

    int p = 1, k = ceil((n - 1) * max(X, Y) / 2.0);

    while(p < k) {
        int t_pola = (p + k) / 2;

        if(n - 1 <= (t_pola / X + t_pola / Y)) { // Dovoljno vremena
            k = t_pola;
        } else {
            p = t_pola + 1;
        }
    }

    cout << p + min(X, Y) << endl;

    return 0;
}