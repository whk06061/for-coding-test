#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

void topologySort(vector<int> inDegree, vector<vector<int>> a) {
    vector<int> result(N + 1, 0);
    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    for (int i = 1; i <= N; ++i) {

        if (q.empty())return;
        int x = q.front();
        q.pop();
        result[i] = x;

        for (int y: a[x]) {
            if (--inDegree[y] == 0) {
                q.push(y);
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        printf("%d ", result[i]);
    }
}

int main() {
    cin >> N >> M;
    vector<vector<int>> a(N + 1, vector<int>());
    vector<int> inDegree(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        inDegree[y]++;
    }
    topologySort(inDegree, a);
}