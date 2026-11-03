#include <iostream>
#include <cmath>

using namespace std;

// Vraca ugao tacke (x, y) u odnosu na pozitivnu x-osu, u intervalu [0, 2*PI).
float ugao_tacke(float x, float y) {
    if (x > 0 && y >= 0)  return atan(y / x);              // I kvadrant i pozitivna x-osa
    if (x < 0)            return atan(y / x) + M_PI;       // II i III kvadrant i negativna x-osa
    if (x > 0 && y < 0)   return atan(y / x) + 2 * M_PI;   // IV kvadrant
    if (x == 0 && y >= 0) return M_PI_2;                   // pozitivna y-osa (ukljucujuci (0, 0))
    if (x == 0 && y < 0)  return M_PI_2 + M_PI;            // negativna y-osa
    return 0;                                              // dostize se samo za NaN
}

// Euklidska udaljenost izmedju tacaka (x1, y1) i (x2, y2).
float udaljenost(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Racuna centar (cx, cy) kruznice opisane oko trougla s tjemenima
// (x1, y1), (x2, y2), (x3, y3).
void centar_opisane(float x1, float y1, float x2, float y2, float x3, float y3,
                    float& cx, float& cy) {
    /*
     * Centar (cx, cy) je jednako udaljen od sva tri tjemena:
     *   (cx-x1)^2 + (cy-y1)^2 = (cx-x2)^2 + (cy-y2)^2
     *   (cx-x1)^2 + (cy-y1)^2 = (cx-x3)^2 + (cy-y3)^2
     *
     * Kvadratni clanovi cx^2 i cy^2 se skrate, pa ostaje linearni sistem:
     *   2(x2 - x1)*cx + 2(y2 - y1)*cy = x2^2 - x1^2 + y2^2 - y1^2
     *   2(x3 - x1)*cx + 2(y3 - y1)*cy = x3^2 - x1^2 + y3^2 - y1^2
     *
     * Sistem oblika
     *   a*cx + b*cy = e
     *   c*cx + d*cy = f
     * rjesava se Kramerovim pravilom:
     *   D  = a*d - c*b
     *   cx = (e*d - b*f) / D
     *   cy = (a*f - e*c) / D
     * Ako je D == 0, tjemena su kolinearna i sistem nema jedinstveno rjesenje.
     */
    float a = 2 * (x2 - x1), b = 2 * (y2 - y1);
    float c = 2 * (x3 - x1), d = 2 * (y3 - y1);
    float e = pow(x2, 2) - pow(x1, 2) + pow(y2, 2) - pow(y1, 2);
    float f = pow(x3, 2) - pow(x1, 2) + pow(y3, 2) - pow(y1, 2);

    float D = a * d - c * b;

    cx = (e * d - b * f) / D;
    cy = (a * f - e * c) / D;
}

// Stampa tjemena sortirana po uglu oko centra opisane kruznice (cx, cy),
// pocevsi od tjemena s indeksom ind_najblizeg.
void stampaj_tjemena(float x[], float y[], int ind_najblizeg, float cx, float cy) {
    float uglovi[3];

    // Translacija: koordinate tjemena relativno u odnosu na centar opisane kruznice
    float rel_x[3] = {x[0] - cx, x[1] - cx, x[2] - cx};
    float rel_y[3] = {y[0] - cy, y[1] - cy, y[2] - cy};

    // Pamti originalni indeks svakog tjemena kroz sortiranje
    int originalni_ind[3] = {0, 1, 2};

    // Ugao svakog tjemena gledano iz centra opisane kruznice
    for (int i = 0; i < 3; i++) {
        uglovi[i] = ugao_tacke(rel_x[i], rel_y[i]);
    }

    // Sortiranje po uglu opadajuce (tjemena idu u smjeru kazaljke na satu)
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (uglovi[i] < uglovi[j]) {
                swap(uglovi[i], uglovi[j]);
                swap(originalni_ind[i], originalni_ind[j]);
                swap(rel_x[i], rel_x[j]);
                swap(rel_y[i], rel_y[j]);
            }
        }
    }

    // Ispis sva tri tjemena kruzno, uz vracanje translacije (+ cx, + cy)
    for (int i = originalni_ind[ind_najblizeg], ispisano = 0; ispisano < 3;
         ispisano++, i = (i + 1) % 3) {
        cout << rel_x[i] + cx << " " << rel_y[i] + cy << endl;
    }
}

// Stampa centar opisane kruznice i tjemena trougla u kruznom redoslijedu.
void stampaj_trougao(float x1, float y1, float x2, float y2, float x3, float y3) {
    float cx, cy;
    centar_opisane(x1, y1, x2, y2, x3, y3, cx, cy);

    float x[] = {x1, x2, x3};
    float y[] = {y1, y2, y3};

    // Indeks tjemena najblizeg koordinatnom pocetku (0, 0)
    int ind_najblizeg = -1;
    float min_udaljenost = MAXFLOAT;

    for (int i = 0; i < 3; i++) {
        float d = udaljenost(0, 0, x[i], y[i]);
        if (d < min_udaljenost) {
            min_udaljenost = d;
            ind_najblizeg = i;
        }
    }

    stampaj_tjemena(x, y, ind_najblizeg, cx, cy);
}

int main() {
    stampaj_trougao(1, 1, 7, 1, 3, 5);

    return 1;
}