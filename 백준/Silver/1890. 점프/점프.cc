#include <bits/stdc++.h>
using namespace std;

int N, mp[104][104];
long long dp[104][104];

long long dfs(int y, int x) {
    if(dp[y][x] > 0) return dp[y][x];
    if(y == N-1 && x == N-1) return 1;
    if(mp[y][x] == 0) return 0;
    
    int ny, nx;
    // 오른쪽으로 이동
    ny = y;
    nx = x + mp[y][x];
    if(ny >= 0 && ny < N && nx >= 0 && nx < N) dp[y][x] += dfs(ny,nx);
    // 아래로 이동
    ny = y + mp[y][x];
    nx = x;
    if(ny >= 0 && ny < N && nx >= 0 && nx < N) dp[y][x] += dfs(ny,nx);

    return dp[y][x];
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mp[i][j];
        }
    }

    dfs(0,0);

    cout << dp[0][0];
}