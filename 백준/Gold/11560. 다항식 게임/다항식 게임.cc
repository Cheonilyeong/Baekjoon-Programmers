#include <bits/stdc++.h>
using namespace std;

long long T, K, N, dp[22][222];

int main(void) {

    cin >> T;

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= 20; i++) {
        for(int j = 0; j <= (i*(i-1)/2); j++) {
            for(int k = 0; k <= i; k++) {
                dp[i][j+k] += dp[i-1][j];
            }
        }
    }

    while(T--) {
        
        cin >> K >> N;

        cout << dp[K][N] << '\n';
    }
}