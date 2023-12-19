#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, s, e, k;
        vector<int> numbers;
        cin >> n >> s >> e >> k;
        for (int j = 0; j < n; ++j) {
            int number;
            cin >> number;
            numbers.push_back(number);
        }
        vector<int> subStringNumbers(numbers.begin() + s - 1, numbers.begin() + e);
        sort(subStringNumbers.begin(), subStringNumbers.end());
        cout << "#" << i + 1 << " " << subStringNumbers[k - 1] << endl;
    }
    return 0;
}