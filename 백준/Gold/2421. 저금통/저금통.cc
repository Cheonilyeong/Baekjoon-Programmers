#include <bits/stdc++.h>
using namespace std;

int N, che[1000000], dp[999][999];

void era(int mx_n) {
    for(int i = 2; i <= mx_n; i++) {
        if(che[i]) continue;
        for(int j = 2*i; j <= mx_n; j+=i) {
            che[j] = 1;
        }
    }
}

int memoization(int i, int j) {
    if(i < 1 || j < 1) return 0;
    if(dp[i][j] > -1) return dp[i][j];

    string s = "";
    s += to_string(i);
    s += to_string(j);

    if(che[atoi(s.c_str())] == 0) {
        return dp[i][j] = max(memoization(i-1,j), memoization(i,j-1)) + 1;
    }
    else {
        return dp[i][j] = max(memoization(i-1,j), memoization(i,j-1));
    }
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    era(999999);

    memset(dp, -1, sizeof(dp));
    dp[1][1] = 0;
    cout << memoization(N, N);
}