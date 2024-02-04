#include <bits/stdc++.h>
using namespace std;

int T, n;
vector<pair<int, int>> dp(41);

pair<int, int> fibCnt(int num) {
    if (num == 0) return {1, 0};
    if (num == 1) return {0, 1};
    if (dp[num].first > 0 && dp[num].second > 0) return dp[num];

    pair<int, int> a = fibCnt(num - 1);
    pair<int, int> b = fibCnt(num - 2);

    dp[num].first = a.first + b.first;
    dp[num].second = a.second + b.second;

    return dp[num];
}

int main(void) {

    cin >> T;

    // dp.resize(41);

    while (T--) {

        cin >> n;

        pair<int, int> a = fibCnt(n);

        cout << a.first << ' ' << a.second << '\n';
    }

    return 0;
}
