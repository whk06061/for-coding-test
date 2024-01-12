#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int s = 0, e = 1;
    int current = a[0];
    int answer = 0;

    while(true){
        if(current < M){
            if (e < N){
                current += a[e++];
            }else break;
        }else{
            if (current == M) answer ++;
            current -=a[s++];
        }
    }

    cout << answer;
}