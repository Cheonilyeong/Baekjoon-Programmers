#include <bits/stdc++.h>
using namespace std;

int N, M, A, B, L, R, mn = INT_MAX;
int LR[100004];
int dp[100004];
const int INF = 1e9 + 7;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> A >> B;

    while(M--) {
        cin >> L >> R;
        for(int i = L; i <= R; i++) {
            LR[i] = 1;
        }
    }

    fill(&dp[0], &dp[100004], INF);
    dp[0] = 0;

    for(int i = 1; i <= N; i++) {
        if (LR[i] == 1) continue; // 장애물이 있는 경우 건너뛰기

        if (i - A >= 0) dp[i] = min(dp[i], dp[i - A] + 1);
        if (i - B >= 0) dp[i] = min(dp[i], dp[i - B] + 1);
    }

    if(dp[N] == INF) cout << -1; 
    else cout << dp[N];
}