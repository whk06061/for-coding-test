#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<vector<char>> map;
vector<vector<int>> c;
int w_sum = 0;
int b_sum = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int start_r, int start_c, char team) {
    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    c[start_r][start_c] = true;
    int cnt = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; ++i) {
            int next_r = current.first + dx[i];
            int next_c = current.second + dy[i];
            if (next_r >= 0 && next_r < M && next_c >= 0 && next_c < N && !c[next_r][next_c] &&
                map[next_r][next_c] == team) {
                q.push({next_r, next_c});
                c[next_r][next_c] = true;
            }
        }
    }
    if (team == 'W') {
        w_sum += cnt * cnt;
    } else {
        b_sum += cnt * cnt;
    }
}

int main() {
    cin >> N >> M;
    map.assign(M, vector<char>(N));
    c.assign(M, vector<int>(N, false));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!c[i][j]) {
                bfs(i, j, map[i][j]);
            }
        }
    }
    cout << w_sum << ' ' << b_sum;
    return 0;
}