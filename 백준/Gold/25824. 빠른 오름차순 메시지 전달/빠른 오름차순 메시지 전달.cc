#include <bits/stdc++.h>
using namespace std;

int mp[15][15], dp[15], ret;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i = 1; i <= 12; i++) {
        for(int j = 1; j <= 12; j++) {
            cin >> mp[i][j];
        }
    }

    dp[1] = mp[2][1];
    dp[2] = mp[1][2];
    for(int i = 3; i <= 11; i+=2) {
        dp[i] = min(dp[i-2]+mp[i-2][i+1]+mp[i+1][i], dp[i-1]+mp[i-1][i+1]+mp[i+1][i]);
        dp[i+1] = min(dp[i-2]+mp[i-2][i]+mp[i][i+1], dp[i-1]+mp[i-1][i]+mp[i][i+1]);
    }

    cout << min(dp[12], dp[11]);
}