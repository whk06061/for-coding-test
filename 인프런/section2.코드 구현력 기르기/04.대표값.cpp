#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> score(n);
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }
    // 1. 평균 구하기
    int avg = round(accumulate(score.begin(), score.end(), 0.0) / n);
    cout << avg << " ";

    // 2. 평균에 가장 가까운 학생은 몇 번째 학생인지 출력
    int answerGap = avg;
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        int gap = abs(score[i] - avg);
        if ((gap < answerGap) || ((gap == answerGap) && (score[i] > score[answer]))) {
            answerGap = gap;
            answer = i;
        }
    }
    cout << answer + 1;
}