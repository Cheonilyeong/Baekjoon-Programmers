#include <bits/stdc++.h>
using namespace std;

int N, dp[1000004];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    fill(&dp[0], &dp[1000004], 987654321);
    dp[1] = 0;
    for(int i = 1; i <= N; i++) {
        if(i*3 <= N) dp[i*3] = min(dp[i*3],dp[i]+1);
        if(i*2 <= N) dp[i*2] = min(dp[i*2],dp[i]+1);
        if(i+1 <= N) dp[i+1] = min(dp[i+1],dp[i]+1);
    }

    cout << dp[N];
}