#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> numbers(N + 1);
    for (int i = 2; i <= N; ++i) {
        for (int j = i * 2; j <= N; j = j + i) {
            numbers[j] = 1;
        }
    }
    int answer = 0;
    for (int i = 2; i <= N; ++i) {
        if (numbers[i] == 0) answer++;
    }
    cout << answer;
}