#include <bits/stdc++.h>
using namespace std;

int T, K, num, dp[504][504], psum[504];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> K;

        for(int i = 1; i <= K; i++) {
            cin >> num;
            psum[i] = psum[i-1] + num;
        }
        
        for(int i = 1; i < K; i++) {
            for(int j = 1; j <= K-i; j++) {
                int s = j;
                int e = j+i;
                
                dp[s][e] = INT_MAX;
                
                for(int m = s; m < e; m++) {
                    dp[s][e] = min(dp[s][e], dp[s][m]+dp[m+1][e]+psum[e]-psum[s-1]);
                }

            }
        }

        cout << dp[1][K] << '\n';
    }
}