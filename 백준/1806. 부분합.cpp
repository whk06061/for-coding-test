#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> numbers;
int left_pointer = 0;
int right_pointer = 0;
int sum = 0;
int answer = 2147000000;

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    while (right_pointer <= N) {
        if (sum >= S) {
            answer = min(answer, right_pointer - left_pointer);
            sum -= numbers[left_pointer++];
        } else {
            sum += numbers[right_pointer++];
        }
    }
    if (answer == 2147000000) answer = 0;
    cout << answer;
}