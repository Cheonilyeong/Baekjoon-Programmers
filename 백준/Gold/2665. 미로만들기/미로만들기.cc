#include <bits/stdc++.h>
using namespace std;

int N, visited[54][54];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char mp[54][54];
priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mp[i][j];
        }
    }

    memset(visited, -1, sizeof(visited));
    visited[0][0] = 0;
    pq.push({0,0,0});

    while(pq.size()) {
        auto it = pq.top(); pq.pop();
        
        int cnt = get<0>(it);
        int y = get<1>(it);
        int x = get<2>(it);
        
        //cout << "{" << y << "," << x << "}" << " cnt는 " << cnt << '\n';
        if(visited[N-1][N-1] != -1) break; 

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nCnt = cnt;

            if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
            if(visited[ny][nx] != -1) continue;
            if(mp[ny][nx] == '0') nCnt++;

            visited[ny][nx] = nCnt;
            pq.push({nCnt, ny, nx});
        }
    }

    cout << visited[N-1][N-1];
}