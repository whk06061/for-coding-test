#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> n;
vector<int> c;

void dfs(int start) {
    if (c[start]) return;
    c[start] = true;
    cout << start << " ";
    for (int i = 0; i < n[start].size(); ++i) {
        dfs(n[start][i]);
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    c[start] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int i = 0; i < n[x].size(); ++i) {
            if (!c[n[x][i]]) {
                q.push(n[x][i]);
                c[n[x][i]] = true;
            }

        }
    }
}

int main() {
    cin >> N >> M >> V;
    n.assign(N + 1, vector<int>());
    c.assign(N + 1, false);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        n[a].push_back(b);
        n[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i) {
        sort(n[i].begin(), n[i].end());
    }
    dfs(V);
    cout << endl;
    c.assign(N + 1, false);
    bfs(V);
}