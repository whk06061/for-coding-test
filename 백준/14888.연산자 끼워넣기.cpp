#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> numbers;
vector<int> operators(4);
int myMin = 2147000000;
int myMax = -2147000000;

void operate(int depth, int result) {
    if (depth == n) {
        cout << result<<endl;
        if (result > myMax) myMax = result;
        if (result < myMin) myMin = result;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (operators[i] > 0) {
            operators[i]--;
            if (i == 0) {
                operate(depth + 1, result + numbers[depth]);
            } else if (i == 1) {
                operate(depth + 1, result - numbers[depth]);
            } else if (i == 2) {
                operate(depth + 1, result * numbers[depth]);
            } else {
                operate(depth + 1, result / numbers[depth]);
            }
            operators[i]++;
        }
    }
    return;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        numbers.push_back(input);
    }
    for (int i = 0; i < 4; ++i) {
        cin >> operators[i];
    }
    operate(1, numbers[0]);
    cout << myMax << endl;
    cout << myMin;
}