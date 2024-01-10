#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 부모 노드를 찾는 함수
int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b) return 1;
    return 0;
}

// 간선 클래스 선언
class Edge {
public:
    int node[2];
    int distance;

    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }

    bool operator<(const Edge &edge) const {
        return this->distance < edge.distance;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> v;

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(Edge(a, b, c));
    }

    // 간선의 비용을 기준으로 오름차순 정렬
    // 클래스에서 정렬의 기준을 명시해줬기 때문에 자동으로 간선의 비용을 기준으로 정렬
    sort(v.begin(), v.end());

    // 각 정점이 포함된 그래프가 어디인지 저장
    int parent[V + 1];
    for (int i = 1; i <= V; ++i) {
        parent[i] = i;
    }
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        //사이클이 발생하지 않는 경우 그래프에 포함
        if (!findParent(parent, v[i].node[0], v[i].node[1])) {
            sum += v[i].distance;
            unionParent(parent, v[i].node[0], v[i].node[1]);
        }
    }
    printf("%d\n", sum);
}
