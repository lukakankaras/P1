#include <iostream>
using namespace std;

// Funkcija ispisuje određeni znak zadani broj puta
void print(int num, char c) {
    for(int i = 0; i < num; i++) {
        cout << c;
    }
}

int main() {
    // Unos dimenzija stepenica
    int a, b, N;
    cin >> a >> b >> N;

    // Ispis gornje ivice stepenica
    cout << '.';
    print(a, '_');
    cout << '.' << endl;

    // Petlja prolazi kroz svih N nivoa stepenica
    for(int i = 1; i <= N; i++) {

        // Ispisuje stepenice u zavisnosti od trenutnog nivoa
        for(int j = 0; j < b; j++) {

            // Ispis dijela stepenica koji nije posljednji
            if(j != b - 1) {
                for(int k = 0; k < i; k++) {
                    // Uspravna stranica stepenice
                    cout << '|';

                    // Unutrašnji dio stepenice
                    print(a, ' ');
                }

                // Završna uspravna stranica
                cout << '|' << endl;

            } else {

                // Ako smo došli do posljednjeg nivoa
                if(i == N) {

                    // Crta donji dio posljednje stepenice
                    for(int k = 0; k < i; k++) {
                        cout << '|';

                        // Donja ivica stepenice
                        print(a, '_');
                    }

                    cout << '|' << endl;

                } else {

                    // Crta donju ivicu trenutne stepenice
                    for(int k = 0; k < i + 1; k++) {
                        cout << '|';

                        // Donja ivica stepenice
                        print(a, '_');
                    }

                    // Označava kraj stepenice
                    cout << '.' << endl;
                }
            }
        }
    }

    return 0;
}