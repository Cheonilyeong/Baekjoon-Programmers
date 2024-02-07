#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> num;
long long dp[2004][2004], ret = 1;
const long long MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

long long combi(int n, int r) {
    if(dp[n][r] > 0) return dp[n][r];
    if(n == r || r == 0) return dp[n][r] = 1;

    return dp[n][r] = combi(n - 1, r) % MOD + combi(n - 1, r - 1) % MOD;
}
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    num.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    
    ret = (combi(N, K) % MOD) * (power(2, K-1) % MOD);

    cout << ret % MOD;
}