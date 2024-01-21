#include <bits/stdc++.h>

using namespace std;

int a, n, mx = INT_MIN, mn = INT_MAX;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        mx = max(mx, a);
        mn = min(mn, a);
    }
    cout << mn << ' ' << mx;
}