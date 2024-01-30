#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
vector<vector<int>> map;
vector<vector<int>> visited;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int answer = 0;

void bfs(int startX, int startY) {
    int cnt = 0;
    queue<pair<int, int>> q;

    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; ++i) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && !visited[nx][ny] && map[nx][ny] == 1) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    if (cnt > answer) answer = cnt;
}

int main() {
    cin >> N >> M >> K;
    map.assign(N + 1, vector<int>(M + 1, 0));
    visited.assign(N + 1, vector<int>(M + 1, false));
    // 맵 초기화
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    // 쓰레기 크기 구하기
    for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j < M + 1; ++j) {
            if (!visited[i][j] && map[i][j] == 1) {
                bfs(i, j);
            }
        }
    }
    cout << answer;
}