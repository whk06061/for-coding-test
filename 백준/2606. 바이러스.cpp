#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector<vector<int>> map;
vector<int> visited;
int answer = 0;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < map[current].size(); ++i) {
            int next = map[current][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                answer++;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    map.assign(N + 1, vector<int>());
    visited.assign(N + 1, false);
    // 맵 초기화
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    bfs(1);
    cout << answer;
}