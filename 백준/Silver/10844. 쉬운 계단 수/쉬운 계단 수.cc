#include <bits/stdc++.h>
using namespace std;

int N;
long long dp[104][10], ret;

int main(void) {
    cin >> N;

    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    dp[1][5] = 1;
    dp[1][6] = 1;
    dp[1][7] = 1;
    dp[1][8] = 1;
    dp[1][9] = 1;
    
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == 0) dp[i][j] = dp[i-1][j+1];
            else if(j == 9) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
    }

    for(int i = 0; i <= 9; i++) {
        ret += dp[N][i] % 1000000000;
    }
    
    cout << ret % 1000000000;
}