#include <iostream>
#include <random>
#include <vector>
#define pos pair<int, int>
using namespace std;
int image[5][3] = {};
vector<string> colors = {
    "\033[31m",
    "\033[32m",
    "\033[33m",
    "\033[34m",
    "\033[36m"
};
int rint(int from, int to) {
    random_device random_device;
    mt19937 engine{ random_device() };
    uniform_int_distribution<> dist(from, to);
    return dist(engine);
}
void make(int amount) {
    vector<pos> positions;
    for (int i = 0; i < 5; i++) for (int j = 0; j < 3; j++) positions.push_back({i, j});
    for (int i = 0; i < amount; i++) {
        int ind = rint(0, 14 - i);
        pos p = positions[ind];
        image[p.first][p.second] = 1;
        positions.erase(positions.begin() + ind);
    }
}
void fancy_display(int color_index) {
    string c = colors[color_index];
    cout << c;
    for (int i = 0; i < 5; i++) {
        int m = 1;
        for (int j = 0; j >= 0; j += m) {
            if (j == 2)m = -1;
            cout << (image[i][j] == 1 ? '#':' ');
        }
        cout << "\n";
    }
    cout << "\033[0m";
}

int main(void) {
    make(rint(4, 8));
    fancy_display(rint(0, 4));
}
