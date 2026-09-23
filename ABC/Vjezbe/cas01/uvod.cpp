#include <iostream> // header za input/output (primarno za cin i cout)
#include <cmath> // header za matematičke funkcije

using namespace std; // using-direktiva: omogućava korištenje imena iz std (standard namespace) bez prefiksa std::

// definicija funkcije
// int - povratni tip
// brojCifara - ime funkcije
// int broj - prvi i jedini parametar funkcije

int brojCifara(int broj) {
    return (int)(log10(broj)) + 1; // (int)(...) - konverzija rezultata izraza ... u int
    // return ... - funkcija vraća rezultat izraza ...
    // istražiti: šta se dešava za broj 0 ili negativne brojeve?
}

int main() { // funkcija main mora vraćati int - statusni kod
    cout << "hello world" << endl; // cout služi za ispisivanje teksta u konzolu

    int t1 = 0; // definicija int-a sa inicijalizacijom
    int t2; // definicija int-a bez inicijalizacije, vrijednost je neodređena
    // čitanje t2 prije dodjele vrijednosti je greška (nedefinisano ponašanje)

    int t3, t4; // definicija više int-ova u jednoj liniji
    int t5 = 2, t6 = 3; // definicija i inicijalizacija više int-ova u jednoj liniji

    cin >> t3 >> t4; // unošenje vrijednosti pomoću konzole u t3 i t4

    cout << "[ t5 = " << t5 << " ]" << endl; // ispisivanje vrijednosti promjenljive

    // if, else if i else
    if (t5 > t6) {
        cout << "if" << endl;
    } else if (t5 == t6) {
        cout << "else if" << endl;
    } else {
        cout << "else" << endl;
    }

    // for petlja
    for (int i = 0; i < 10; i++) {
        cout << i << " "; // ispisivanje bez endl ne prelazi u novi red
    }
    cout << "\n"; // vizuelno isto kao endl; istražiti koja je razlika između \n i endl

    // while petlja
    while (t5 < 3 * t6) {
        t5++; // postfiksna inkrementacija; istražiti razliku između ++t5 i t5++
        // alternativa: t5 += 1;
    }

    const float POLA_OD_PI = 1.570796327f; // const - vrijednost promjenljive se ne može naknadno promijeniti
    // float - tip za decimalne brojeve; standard ne garantuje veličinu,
    // ali je u praksi gotovo uvijek 32-bitni
    // istražiti ostale tipove, kao što su bool, char, short, long, long long, double...

    int rezultat = brojCifara(t5 * t6); // poziv funkcije koja je definisana gore
    // funkcija mora biti deklarisana iznad mjesta gdje se dešavaju pozivi

    // istražiti razliku između definicije i deklaracije
    // istražiti razliku između parametra i argumenta funkcije
    // !!! parametri i argumenti ne moraju imati isti naziv; vrijednost argumenta se kopira i šalje funkciji pri pozivu

    return 0; // samo u funkciji main: ako izostavimo return, podrazumijeva se 0
}