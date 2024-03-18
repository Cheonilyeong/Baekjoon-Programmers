#include <bits/stdc++.h>
using namespace std;

int N, dp[500004][2];
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    
    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // 1 3 4 5 9
    dp[1][0] = v[1] - v[0];
    dp[2][1] = v[2] - v[0];
    for(int i = 3; i < N; i++) {
        if(i & 1) dp[i][0] = dp[i-2][0] + v[i]-v[i-1];
        else dp[i][1] = min(dp[i-3][0]+v[i]-v[i-2], dp[i-2][1]+v[i]-v[i-1]);
    }

    cout << dp[N-1][1];
}