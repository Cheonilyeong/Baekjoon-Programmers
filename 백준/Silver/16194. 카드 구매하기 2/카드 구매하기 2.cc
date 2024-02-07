#include <bits/stdc++.h>
using namespace std;

int N, dp[1004];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N; 

    for(int i = 1; i <= N; i++) {
        cin >> dp[i];
        for(int j = 1; j < i; j++) {
            // dp[i] = min(dp[i-1]+dp[1], dp[i-2]+dp[2], dp[i-3],dp[3]....) 
            dp[i] = min(dp[i], dp[i-j]+dp[j]);
        }
    }

    cout << dp[N];
}