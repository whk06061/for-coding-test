#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, K;
int answer = 0;
bool arr[26];
vector<string> v;

bool can_read(string word) {
    for(auto c: word) {
        if(!arr[c - 'a']) return false;
    }
    return true;
}

int count_answers() {
    int ret = 0;
    for(auto word: v) {
        if(can_read(word)) ret++;
    }
    return ret;
}

void dfs(int depth, int start) {
    if(depth == K) {
        answer = max(answer, count_answers());
        return;
    }

    for(int i=start; i<26; ++i) {
        if(arr[i]) continue;

        arr[i] = true;
        dfs(depth + 1, i);
        arr[i] = false;
    }
}

void init() {
    vector<char> tmp = {'a', 'n', 't', 'i', 'c'};
    for(auto c: tmp) arr[c - 'a'] = true;
    K -= 5;
}

int main() {
    cin >> N >> K;
    if(K < 5) {
        cout << 0;
        return 0;
    }

    init();

    for(int i=0; i<N; ++i) {
        string s;
        cin >> s;

        s = s.substr(4, s.length()-8);
        v.push_back(s);
    }

    dfs(0, 0);

    cout << answer;

    return 0;
}