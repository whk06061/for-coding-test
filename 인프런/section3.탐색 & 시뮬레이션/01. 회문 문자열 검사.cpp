#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool check(string word) {
    for (int i = 0; i < word.size() / 2; ++i) {
        if (tolower(word[i]) != tolower(word[word.size() - 1 - i])) return false;
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        cout << "#" << i + 1 << " ";
        if (check(word)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
