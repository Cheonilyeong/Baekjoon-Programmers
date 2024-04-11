#include <bits/stdc++.h>
using namespace std;

int N, dp[5004][2];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    dp[3][0] = 1;
    dp[5][1] = 1;

    for(int i = 5; i <= N; i++) {
        int pre1 = dp[i-3][0] + dp[i-3][1];
        int pre2 = dp[i-5][0] + dp[i-5][1];

        if(pre1 == 0 && pre2 == 0) continue;
        else if(pre1 == 0) {
            dp[i][0] = dp[i-5][0];
            dp[i][1] = dp[i-5][1] + 1;
        }
        else if(pre2 == 0) {
            dp[i][0] = dp[i-3][0] + 1;
            dp[i][1] = dp[i-3][1];
        }
        else if(pre1 >= pre2) {
            dp[i][0] = dp[i-5][0];
            dp[i][1] = dp[i-5][1] + 1;
        }
        else if(pre1 < pre2) {
            dp[i][0] = dp[i-3][0] + 1;
            dp[i][1] = dp[i-3][1];
        }
    }

    int ret = dp[N][0] + dp[N][1];
    if(ret == 0) cout << -1;
    else cout << ret;
}