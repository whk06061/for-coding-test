#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    int answer = 0;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int s = 0, e = 0;
    int current = 0;
    while (s <= e && e <= N) {
        if (current < M) {
            current += a[e++];
        } else {
            if (current == M) answer++;
            current -= a[s++];
        }
    }
    while (s <= N) {
        if (current < M) break;
        if (current == M) answer++;
        current -= a[s++];
    }
    cout << answer;
}