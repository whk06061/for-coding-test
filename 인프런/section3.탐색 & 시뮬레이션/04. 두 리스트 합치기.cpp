#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sum(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j]) {
            c.push_back(b[j++]);
        } else {
            c.push_back(a[i++]);
        }
    }
    if (i < a.size()) {
        for (int k = i; k < a.size(); ++k) {
            c.push_back(a[k]);
        }
    }
    if (j < b.size()) {
        for (int k = j; k < b.size(); ++k) {
            c.push_back(b[k]);
        }
    }
    return c;
}

int main() {
    int N, M;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    cin >> M;
    vector<int> b(M);
    for (int i = 0; i < M; ++i) {
        cin >> b[i];
    }
    vector<int> c = sum(a, b);
    for (int i: c) {
        cout << i << " ";
    }
}