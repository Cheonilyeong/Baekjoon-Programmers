#include <bits/stdc++.h>
using namespace std;

int R, C, T, startY, startX, visited[104][104], ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char mp[104][104];
set<pair<int,int>> st;

void dfs(int y, int x, int cnt, int sum) {
    if(cnt > T) return;
    ret = max(ret, sum);

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        int nsum = sum;

        if(ny<0 || ny>=R || nx<0 || nx>=C) continue;
        if(mp[ny][nx]=='#') continue;
        if(mp[ny][nx]=='S' && visited[ny][nx]==0) {
            nsum++;
            visited[ny][nx] = 1;
            dfs(ny,nx, cnt+1, nsum);
            visited[ny][nx] = 0;
        }
        else {
            dfs(ny,nx, cnt+1, nsum);
        }
        
    }
}


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> R >> C >> T;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 'G') tie(startY, startX) = {i,j};
        }
    }

    dfs(startY, startX, 0, 0);

    cout << ret;
}