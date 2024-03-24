#include <bits/stdc++.h>
using namespace std;

long long K, N, l, r, m, mx=INT_MIN, sum, ret=INT_MIN;
vector<long long> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> K >> N;

    v.resize(K);
    for(int i = 0; i < K; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    l = 1;
    r = mx;

    while(l <= r) {
        m = (l + r) / 2;
        sum = 0;

        for(int i = 0; i < K; i++) {
            sum += (v[i] / m);
        }

        if(sum < N) {
            r = m-1;
        }
        else {
            ret = max(ret, m);
            l = m+1;
        }
    }

    cout << ret;
}