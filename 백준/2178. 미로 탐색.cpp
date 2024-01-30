#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector<vector<int>> visited;
vector<vector<char>> map;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Node {
public:
    int step;
    pair<int, int> currentIndex;

    Node(int step, pair<int, int> currentIndex) {
        this->step = step;
        this->currentIndex = currentIndex;
    }
};

int bfs(int startX, int startY) {
    queue<Node> q;
    q.push(Node(1, {startX, startY}));
    visited[startX][startY] = true;
    while (!q.empty()) {
        Node currentNode = q.front();
        pair<int, int> currentIndex = currentNode.currentIndex;
        q.pop();
        if (currentIndex.first == N && currentIndex.second == M) return currentNode.step;
        for (int i = 0; i < 4; ++i) {
            int nx = currentIndex.first + dx[i];
            int ny = currentIndex.second + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && !visited[nx][ny] && map[nx][ny] == '1') {
                q.push(Node(currentNode.step + 1, {nx, ny}));
                visited[nx][ny] = true;
            }
        }
    }
    return 0;
}

int main() {
    cin >> N >> M;
    map.assign(N + 1, vector<char>(M + 1));
    visited.assign(N + 1, vector<int>(M + 1, false));
    for (int i = 1; i < N + 1; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j < M + 1; ++j) {
            map[i][j] = s[j - 1];
        }
    }
    cout << bfs(1, 1);
}