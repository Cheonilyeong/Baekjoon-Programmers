#include <bits/stdc++.h>
using namespace std;

int N, M, ret=INT_MIN;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int l = 0, r = 1000000000;
    while(l <= r) {
        int m = (l + r) / 2;

        long long sum = 0;
        for(int &i : v) {
            sum += max(0, (i-m));
        }

        if(sum >= M) {
            ret = max(ret, m);
            l = m+1;
        }
        else {
            r = m-1;
        }
    }

    cout << ret;
}