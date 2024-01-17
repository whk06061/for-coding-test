#include <iostream>
#include <vector>

using namespace std;

// 접두사와 접미사의 최대 길이를 포함하고 있는 테이블 만들기
vector<int> makeTable(string pattern) {
    int pattern_size = pattern.size();
    vector<int> table(pattern_size, 0);
    int j = 0;
    for (int i = 1; i < pattern_size; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

bool KMP(string parent, string pattern) {
    vector<int> table = makeTable(pattern);
    int parent_size = parent.size();
    int pattern_size = pattern.size();
    int j = 0;
    for (int i = 0; i < parent_size; ++i) {
        while (j > 0 && parent[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (parent[i] == pattern[j]) {
            if (j == pattern_size - 1) {
                return true;
            } else {
                j++;
            }
        }
    }
    return false;
}

int main() {
    string S, P;
    cin >> S >> P;
    bool result = KMP(S, P);
    if (result) cout << 1;
    else cout << 0;
    return 0;
}