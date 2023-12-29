#include <iostream>

using namespace std;

int N;
int result = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        int score;
        cin >> a >> b >> c;
        if (a == b && b == c) {
            score = 10000 + a * 1000;
        } else if (a == b || a == c) {
            score = 1000 + a * 100;
        } else if (b == c) {
            score = 1000 + b * 100;
        } else {
            score = max(max(a, b), c) * 100;
        }
        if (result < score) result = score;
    }
    cout << result;
}