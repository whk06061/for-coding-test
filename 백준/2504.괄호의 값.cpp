#include <iostream>
#include <stack>

using namespace std;

string brackets;
stack<char> save;
int multiple = 1;
int answer = 0;

int main() {
    cin >> brackets;
    for (int i = 0; i < brackets.size(); ++i) {
        if (brackets[i] == '(') {
            save.push('(');
            multiple *= 2;
        } else if (brackets[i] == '[') {
            save.push('[');
            multiple *= 3;
        } else if (brackets[i] == ')') {
            if (save.empty() || save.top() != '(') {
                cout << 0;
                return 0;
            }
            if (brackets[i - 1] == '(') answer += multiple;
            save.pop();
            multiple /= 2;
        } else if (brackets[i] == ']') {
            if (save.empty() || save.top() != '[') {
                cout << 0;
                return 0;
            }
            if (brackets[i - 1] == '[') answer += multiple;
            save.pop();
            multiple /= 3;
        }
    }
    if (!save.empty()) cout << 0;
    else cout << answer;
    return 0;
}