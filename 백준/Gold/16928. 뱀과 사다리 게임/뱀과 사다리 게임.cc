#include <bits/stdc++.h>
using namespace std;
#define move move1

int N, M, a, b, move[104], visited[104];
queue<int> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < 104; i++) {
        move[i] = i;
    }

    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        move[a] = b;
    }

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        move[a] = b;
    }

    visited[1] = 1;
    q.push(1);

    while(q.size()) {
        int now = q.front(); q.pop();

        for(int i = 1; i <= 6; i++) {
            int next = now + i;
            next = move[next];
            
            if(next > 100) continue;
            if(visited[next]==0 || visited[next] > visited[now]+1) {
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }

    cout << visited[100]-1;
}