#include <bits/stdc++.h>
using namespace std;

int N, ret, psum;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i : v) {
        psum = psum+i;
        ret += psum;
    }

    cout << ret;
}