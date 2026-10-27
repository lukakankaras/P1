#include <iostream>
#include <cmath>

using namespace std;

float dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

float ugao(float x, float y) {
    if(x >= 0 && y >= 0) { // Prvi kvadrant
        return asin(y);
    }
    if(x < 0 && y >= 0) { // Drugi kvadrant
        return M_PI / 2 + asin(y);
    }
    if(x < 0 && y < 0) { // Treci kvadrant
        return M_PI + asin(y);
    }
    // Cetvrti kvadrant
    return 3.0 / 4 * M_PI + asin(y);
}

void stampaj_ostale_dvije(float x1, float y1, float x2, float y2, float d1, float d2) {
    float d = dist(0, 0, d1, d2);

    float a1 = ugao(x1 / d, y1 / d), a2 = ugao(x2 / d, y2 / d);

    if(a1 > a2) {
        cout << x1 + d1 << " " << y1 + d2 << endl;
        cout << x2 + d1 << " " << y2 + d2 << endl;
    } else {
        cout << x2 + d1 << " " << y2 + d2 << endl;
        cout << x1 + d1 << " " << y1 + d2 << endl;
    }
}

void stampaj_trougao(float x1, float y1, float x2, float y2, float x3, float y3) {
    float min_dist_x = x1;
    float min_dist_y = y1;

    if(dist(0, 0, x2, y2) < dist(0, 0, min_dist_x, min_dist_y)) {
        min_dist_x = x2;
        min_dist_y = y2;
    }

    if(dist(0, 0, x3, y3) < dist(0, 0, min_dist_x, min_dist_y)) {
        min_dist_x = x3;
        min_dist_y = y3;
    }

    // Translacija trougla
    x1 -= min_dist_x;
    x2 -= min_dist_x;
    x3 -= min_dist_x;

    y1 -= min_dist_y;
    y2 -= min_dist_y;
    y3 -= min_dist_y;

    cout << min_dist_x << " " << min_dist_y << endl;

    float x[3] = {x1, x2, x3};
    float y[3] = {y1, y2, y3};

    int center_index = 0;
    for(int i = 0; i < 3; i++) {
        if(x[i] == 0 && y[i] == 0) center_index = i;
    }

    if(center_index == 0) {
        stampaj_ostale_dvije(x2, y2, x3, y3, min_dist_x, min_dist_y);
    } else if(center_index == 1) {
        stampaj_ostale_dvije(x1, y1, x3, y3, min_dist_x, min_dist_y);
    } else {
        stampaj_ostale_dvije(x1, y1, x2, y2, min_dist_x, min_dist_y);
    }
}

int main() {

    return 1;
}