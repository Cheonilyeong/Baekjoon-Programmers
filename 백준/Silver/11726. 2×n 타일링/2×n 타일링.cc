#include <bits/stdc++.h>
using namespace std;

int N, dp[1004];

int memoization(int i) {
    if(i == 0) return 0;
    if(i == 1) return 1;
    if(i == 2) return 2; 
    if(dp[i] != 0) return dp[i];

    return dp[i] = (memoization(i-1) + memoization(i-2)) % 10007;
}

int main(void) {
    
    cin >> N; 

    cout << memoization(N);
}