#include <iostream>
#include <algorithm>

using namespace std;

int cards[21];

void reverse(int s, int e) {
    while (s < e) {
        swap(cards[s], cards[e]);
        s++;
        e--;
    }
}

int main() {
    for (int i = 0; i < 21; ++i) {
        cards[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        int s, e;
        cin >> s >> e;
        reverse(s, e);
    }
    for (int i = 1; i < 21; ++i) {
        cout << cards[i] << " ";
    }
}