#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<int> cardSums;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int l = j + 1; l < n; ++l) {
                cardSums.push_back(numbers[i] + numbers[j] + numbers[l]);
            }
        }
    }
    sort(cardSums.begin(), cardSums.end());
    cardSums.erase(unique(cardSums.begin(), cardSums.end()), cardSums.end());

    cout << cardSums[cardSums.size() - k];
}