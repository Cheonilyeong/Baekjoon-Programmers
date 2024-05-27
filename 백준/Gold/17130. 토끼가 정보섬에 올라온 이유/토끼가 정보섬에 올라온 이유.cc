#include <bits/stdc++.h>
using namespace std;

int N, M, y, x, dp[1004][1004], ret=-1;
int dy[] = {0, 1, -1};
int dx[] = {1, 1, 1};
char mp[1004][1004];
queue<pair<int,int>> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    // map
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> mp[i][j];
        }
    }

    // dp
    memset(dp, -1, sizeof(dp));
    for(int j = 0; j < M-1; j++) {
        for(int i = 0; i < N; i++) {
            if(mp[i][j] == '#') continue;
            if(mp[i][j] == 'R') dp[i][j] = 0;
            if(dp[i][j] == -1) continue;
            
            //cout << i << ' ' << j << '\n';

            for(int k = 0; k < 3; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                int cnt = dp[i][j];

                if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
                if(mp[ny][nx] == '#') continue;
                if(mp[ny][nx] == 'C') cnt++;

                dp[ny][nx] = max(dp[ny][nx], cnt);

                if(mp[ny][nx] == 'O') ret = max(ret, dp[ny][nx]);
            }
        }
    }

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << ret;
}