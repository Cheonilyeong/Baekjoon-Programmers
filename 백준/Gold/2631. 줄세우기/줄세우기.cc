#include <bits/stdc++.h>
using namespace std;

int N, dp[204], ret=INT_MIN;
vector<int> v;
vector<int> A;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // LIS구하기 O(n2)
    fill(&dp[0], &dp[204], 1);
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                ret = max(ret,dp[i]);
            }
        }
    }

    // LIS구하기 O(nlogn)
    for(int i = 0; i < N; i++) {
        auto idx = lower_bound(A.begin(), A.end(), v[i]);
        if(idx == A.end()) {
            A.push_back(v[i]);
        }
        else {
            A[idx-A.begin()] = v[i];    // *idx = v[i];
        }
    }

    cout << N - A.size();
}