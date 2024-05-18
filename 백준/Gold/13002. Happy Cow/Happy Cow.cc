#include <bits/stdc++.h>
using namespace std;

int N;
long long dp[2003][2003];
vector<int> v;

long long go(int l, int r, int day) {

    if(l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    
    dp[l][r] = max(dp[l][r], go(l+1, r, day+1)+v[l]*day);
    dp[l][r] = max(dp[l][r], go(l, r-1, day+1)+v[r]*day);

    return dp[l][r];
}


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N+2);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    fill(&dp[0][0], &dp[0][0]+2003*2003, -1);
    cout << go(0, N-1, 1);
}