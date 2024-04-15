#include <bits/stdc++.h>
using namespace std;

int N, K, visited[100004];
queue<int> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    visited[N] = 1;
    q.push(N);

    while(q.size()) {
        int now = q.front(); q.pop();

        if(visited[K]) break;

        for(int next : {now+1, now-1, now*2}) {
            if(next >= 0 && next <= 100000 && !visited[next]) {
                visited[next] = visited[now] + 1;
                q.push(next);
            } 
        }
    }

    cout << visited[K]-1;
}