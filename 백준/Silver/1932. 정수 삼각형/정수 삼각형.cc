#include <bits/stdc++.h>
using namespace std;

int n, arr[505][505], dp[505][505], ret=INT_MIN;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
            ret = max(ret,dp[i][j]);
        }
    }

    cout << ret;
}