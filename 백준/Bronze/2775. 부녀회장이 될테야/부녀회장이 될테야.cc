#include <bits/stdc++.h>
using namespace std;

int T, k, n, dp[16][16];

int cnt(int k, int n) {

    if(dp[k][n] != 0) return dp[k][n];

    for(int i = 1; i <= n; i++) {
        dp[k][n] += cnt(k-1,i);
    }

    return dp[k][n];
}

int main(void) {

    cin >> T;

    for(int i = 1; i <= 14; i++) {
        dp[0][i] = i;
    }

    while(T--) {
        cin >> k >> n;
        cout << cnt(k,n) << '\n';
    }
}