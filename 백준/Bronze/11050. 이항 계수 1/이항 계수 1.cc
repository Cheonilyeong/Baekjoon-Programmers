#include <bits/stdc++.h>
using namespace std;

int N, K, dp[11][11];

int combi(int n, int r) {
    if(dp[n][r]) return dp[n][r];
    if(r == 0) return 1;
    if(r == n) return 1;

    // nCr = n-1Cn-1 + n-1Cr
    return dp[n][r] = combi(n-1, r-1) + combi(n-1,r);
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    cout << combi(N,K);
}