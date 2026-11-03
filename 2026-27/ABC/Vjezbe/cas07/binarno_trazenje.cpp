#include <iostream>
#include <climits>

using namespace std;

// 0 1 2 3 4 5
// 1 2 3 4 5 6

void sort_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        // Svaka iteracija ove petlje je nalazenje minimuma u podnizu
        int min_ind = i;
        int min = INT_MAX;

        for(int j = i; j < n; j++) {
            if(arr[j] < min) {
                min = arr[j];
                min_ind = j;
            }
        }

        // Zamijeniti prvi element sa elementom dje je minimum
        swap(arr[i], arr[min_ind]);
    }
}

int binary_searh(int arr[], int n, int x) {
    // Ako x nema u nizu, vratiti -1, inace vratiti poziciju x u nizu

    int p = 0, k = n - 1;

    while(p != k) {
        int ind_polovina = (p + k) / 2;

        if(arr[ind_polovina] == x) return ind_polovina;

        if(x < arr[ind_polovina]) {
            k = ind_polovina - 1;
        } else {
            p = ind_polovina + 1;
        }
    }

    if(arr[p] == x) {
        return p;
    }

    return -1;
}

void zad01() {
    int X, A, B, K, M;
    cin >> X >> A >> B >> K >> M;

    // Najgori slucaj je da oboje drvosjeca svaki drugi dan imaju odmor,
    // pa onda svaki dan se posijece (A / 2 + B / 2) stabala

    int p = 1, k = X / ((A / 2 + B / 2) + 1);
    int rezultat;

    while(p != k) {
        int D = (p + k) / 2;

        cout << "D = " << D << endl;

        // D dana
        // A * D - A * (D / K) = A * (D - D / K)
        // B * D - B * (D / M) = B * (D - D / M)

        int posjecenih = A * (D - D / K) + B * (D - D / M);
        cout << posjecenih << endl;

        if(posjecenih == X) {
            rezultat = D;
            break;
        }
        if(posjecenih < X) {
            p = D + 1;
        } else { // posjecenih > X
            rezultat = D; // Pamcenje najboljeg za sada rezultata
            k = D - 1;
        }
    }

    if(p == k) {
        rezultat = p;
    }

    cout << rezultat << endl;
}


int main() {
    /*int arr[] = {6, 4, 2, 3, 1, 5};
    sort_array(arr, 6);

    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i = 1; i <= 6; i++) {
        cout << binary_searh(arr, 6, i);
    }*/

    zad01();

    return 0;
}