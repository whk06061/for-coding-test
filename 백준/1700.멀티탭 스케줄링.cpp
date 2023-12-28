#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> multi_tap;
vector<int> appliances;

void init() {
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        int input;
        cin >> input;
        appliances.push_back(input);
    }
}

void replace_multi_tap(int currentApplianceIndex) {
    int count = -1;
    int index = -1;
    for (int i = 0; i < N; ++i) {
        int tmp = 0;
        for (int j = currentApplianceIndex + 1; j < K; ++j) {
            if (multi_tap[i] == appliances[j]) break;
            tmp++;
        }
        if (tmp > count) {
            count = tmp;
            index = i;
        }
    }
    multi_tap[index] = appliances[currentApplianceIndex];
}

int main() {
    init();
    int multi_tap_pointer = 0;
    int answer = 0;
    for (int i = 0; i < K; ++i) {
        // 비어 있으면
        if (multi_tap_pointer < N && find(multi_tap.begin(), multi_tap.end(), appliances[i]) == multi_tap.end()) {
            // 비어 있고 다른 숫자가 들어왓을 때
            multi_tap.push_back(appliances[i]);
            multi_tap_pointer++;
        } else {
            // 플러그 꽂혀있지 않음 & 플러그에 꽂을 자리가 없음
            if (find(multi_tap.begin(), multi_tap.end(), appliances[i]) == multi_tap.end()) {
                replace_multi_tap(i);
                answer++;
            }
        }
    }
    cout << answer;
}