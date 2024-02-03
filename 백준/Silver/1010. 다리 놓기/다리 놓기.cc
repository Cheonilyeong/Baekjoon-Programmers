#include <bits/stdc++.h>
using namespace std;

int T, N, M;
long long dp[33][33];

long long combi(int n, int r) {

    if(dp[n][r] > 0) return dp[n][r];
    if(r == 0 || n == r) return dp[n][r] = 1;

    return dp[n][r] = combi(n - 1, r) + combi(n - 1,r - 1);
}
int main(void) {

    cin >> T;

    while(T--) {
        cin >> N >> M;

        // nCr = n-1Cr + n-1Cr-1
        // ret = mCn
        cout << combi(M, N) << '\n';
    }
}