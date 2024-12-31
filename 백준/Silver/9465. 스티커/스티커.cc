#include <bits/stdc++.h>
using namespace std;

int TC, n, arr[2][100004], dp[3][100004];

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> TC;

    while(TC--) {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));

        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> arr[0][i];
        }
        for(int i = 0; i < n; i++) {
            cin >> arr[1][i];
        }

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[2][0] = 0;

        for(int i = 1; i < n; i++) {
            dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + arr[0][i];
            dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + arr[1][i];
            dp[2][i] = max(dp[0][i-1], dp[1][i-1]);
        }

        int mx = INT_MIN;
        for(int i = 0; i < 3; i++) {
            mx = max(mx, dp[i][n-1]);
        }

        cout << mx << '\n';
    }
}