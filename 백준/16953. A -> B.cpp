#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long x, y;

class Node {
public:
    int step;
    long result;

    Node(int step, long result) {
        this->step = step;
        this->result = result;
    }
};

void bfs(long start) {
    queue<Node> q;
    q.push(Node(1, start));
    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        if (current.result > y) continue;
        if (current.result == y) {
            cout << current.step;
            return;
        }
        q.push(Node(current.step + 1, current.result * 2));
        q.push(Node(current.step + 1, current.result * 10 + 1));
    }
    cout << -1;
}

int main() {
    cin >> x >> y;
    bfs(x);
}