#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, w;
    int answer = 0;
    cin >> h >> w;
    vector<int> blocks(w);
    for (int i = 0; i < w; ++i) {
        cin >> blocks[i];
    }
    for (int i = 1; i < w - 1; ++i) {
        int leftHeight = *max_element(blocks.begin(), blocks.begin() + i);
        int rightHeight = *max_element(blocks.begin() + i + 1, blocks.end());
        answer += max(0, min(leftHeight, rightHeight) - blocks[i]);
    }
    cout << answer;
}