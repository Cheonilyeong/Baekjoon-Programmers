#include <bits/stdc++.h>
using namespace std;

int T, n, dp[13];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    dp[1] = 1;
    dp[2] = 2; // 11 2
    dp[3] = 4; // 111 12 21 3
    dp[4] = 7; // 1111 121 211 31, 112 22, 13
    // dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    for(int i = 4; i < 12; i++) {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }

    while(T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}