#include <bits/stdc++.h>

using namespace std;

int n, arr[3], dp[3][2], tmp_dp[3][2];
int mx = INT_MIN, mn = INT_MAX;

int main() {
    cin >> n;

    for (int y = 0; y < n; y++) {
        cin >> arr[0] >> arr[1] >> arr[2];

        if (y == 0) {
            for (int x = 0; x < 3; x++) {
                dp[x][0] = arr[x];
                dp[x][1] = arr[x];
            }
        } else {
            for (int x = 0; x < 3; x++) {
                tmp_dp[x][0] = dp[x][0];
                tmp_dp[x][1] = dp[x][1];
            }

            for (int x = 0; x < 3; x++) {
                dp[x][0] = INT_MIN; // 최대값 초기화
                dp[x][1] = INT_MAX; // 최소값 초기화

                for (int d : {1, 0, -1}) {
                    int nx = x + d;

                    if (nx < 0 || nx >= 3) continue;

                    dp[x][0] = max(dp[x][0], tmp_dp[nx][0] + arr[x]);
                    dp[x][1] = min(dp[x][1], tmp_dp[nx][1] + arr[x]);
                }
            }
        }
    }

    for (int x = 0; x < 3; x++) {
        mx = max(mx, dp[x][0]);
        mn = min(mn, dp[x][1]);
    }

    cout << mx << ' ' << mn;
}
