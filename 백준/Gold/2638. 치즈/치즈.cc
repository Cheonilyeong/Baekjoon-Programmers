#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, arr[111][111], cnt[111][111], visited[111][111], cz, day;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void airDFS(int y, int x) {
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx]) continue;
        if(arr[ny][nx] == 1) cnt[ny][nx]++;
        if(arr[ny][nx] == 0) airDFS(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) cz++;
        }
    }

    while(cz) {
        day++;
        memset(cnt, 0, sizeof(cnt));
        memset(visited, 0, sizeof(visited));

        airDFS(0, 0);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(cnt[i][j] >= 2) {
                    arr[i][j] = 0;
                    cz--;
                }
            }
        }
    }
    
    cout << day;
}