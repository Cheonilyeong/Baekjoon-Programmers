#include <bits/stdc++.h>
using namespace std;

int T, N;
long long dp[104]={0,1,1,1,2,2,3,4,5,7,9};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    for(int i = 11; i < 103; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }

    while(T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }
}