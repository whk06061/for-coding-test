#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> count(n+m+1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            count[i+j] ++;
        }
    }
    int maxCount = *max_element(count.begin(), count.end());
    for (int i = 0; i < count.size(); ++i) {
        if (count[i] == maxCount) cout << i << " ";
    }
}