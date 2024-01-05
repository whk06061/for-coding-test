#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string word;
int number = 0;
int divisor_count = 0;

int main() {
    cin >> word;
    for (char c: word) {
        if (c >= 48 && c <= 57) {
            number = number * 10 + c - 48;
        }
    }
    for (int i = 1; i <= number; ++i) {
        if (number % i == 0) {
            divisor_count++;
        }
    }
    cout << number << endl;
    cout << divisor_count;
}
