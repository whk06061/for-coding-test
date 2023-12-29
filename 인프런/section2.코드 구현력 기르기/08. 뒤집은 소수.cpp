#include <iostream>

using namespace std;

int N;

bool isPrime(int number) {
    if (number == 1) return false;
    for (int i = 2; i < number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

int reverse(int number) {
    int result = 0;
    while (number > 0) {
        result = result * 10 + number % 10;
        number /= 10;
    }
    return result;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        int reverseNumber = reverse(number);
        if (isPrime(reverseNumber)) cout << reverseNumber << " ";
    }
}