#include <bits/stdc++.h>

using namespace std;

int N, M, visited[10];

void go(int now, int cnt) {
    if(cnt == M) {
        for(int i = 1; i <= N; i++) {
            if(visited[i] == 1) cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = now + 1; i <= N; i++) {
        visited[i] = 1;
        go(i, cnt+1);
        visited[i] = 0;
    }
}

int main() {
    
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        visited[i] = 1;
        go(i, 1);
        visited[i] = 0;
    }
}