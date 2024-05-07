#include <bits/stdc++.h>
using namespace std;

int N, dp[1000004];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    dp[1] = 1;  // 1
    dp[2] = 2;  // 11 or 00

    for(int i = 3; i <= N; i++) {
        dp[i] = (dp[i-2]%15746 + dp[i-1]%15746)%15746;
    }

    cout << dp[N];
}