#include <bits/stdc++.h>
using namespace std;

int n, num, arr[100004], dp[100004][2];
const int INF = -1111111111;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> num;
        arr[i] = num;
    }

    fill(&dp[0][0], &dp[0][0]+100004*2, INF);
    dp[0][0] = 0;
    
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + arr[i];
        dp[i][1] = max(dp[i-1][1],dp[i][0]);
        
        dp[i][0] = max(0, dp[i][0]);    // if(dp[i][0]<0)dp[i][0]=0;
    }

    cout << dp[n][1];
}