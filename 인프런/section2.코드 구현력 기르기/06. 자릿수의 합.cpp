#include <iostream>

using namespace std;

int digit_sum(int x) {
    int number = x;
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    int maxSum = 0;
    int answer;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        int sum = digit_sum(numbers[i]);
        if (sum > maxSum) {
            maxSum = sum;
            answer = numbers[i];
        }
    }
    cout << answer;
}