#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int start_city, end_city;
int INF = 987654321;
vector<int> d;
vector<bool> visited;
vector<vector<int>> map;

int findSmallIndex() {
    int index = 0;
    int min = INF;
    for (int i = 0; i < N; ++i) {
        if (!visited[i] && d[i] < min) {
            min = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int start) {
    visited.assign(N, false);
    for (int i = 0; i < N; ++i) {
        d[i] = map[start][i];
    }
    visited[start] = true;
    for (int i = 0; i < N; ++i) {
        int current = findSmallIndex();
        visited[current] = true;
        for (int j = 0; j < N; ++j) {
            if (!visited[j]) {
                if (d[j] > d[current] + map[current][j]) {
                    d[j] = d[current] + map[current][j];
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    map.assign(N, vector<int>(N, INF));
    d.assign(N, INF);
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (map[a - 1][b - 1] != INF) {
            map[a - 1][b - 1] = min(map[a - 1][b - 1], c);
        } else {
            map[a - 1][b - 1] = c;
        }
    }
    cin >> start_city >> end_city;
    if (start_city == end_city) cout << 0;
    else {
        dijkstra(start_city - 1);
        cout << d[end_city - 1];
    }
}
