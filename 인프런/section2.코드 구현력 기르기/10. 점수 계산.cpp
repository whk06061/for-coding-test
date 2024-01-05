#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    int plus = 0;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int score;
        cin >> score;
        if (score == 1) {
            plus += 1;
            sum += 1 * plus;
        } else {
            plus = 0;
        }
    }
    cout << sum;
}
