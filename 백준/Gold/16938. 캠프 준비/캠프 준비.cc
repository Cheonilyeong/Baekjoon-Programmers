#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ret, visited[17];
ll N, L, R, X, check;
vector<ll> v;

void go(int now, int cnt, ll sum, ll mn, ll mx) {
    if(sum > R) return;
    if(cnt >= 2 && sum >= L && sum <= R && (mx-mn) >= X) {
        //cout << cnt << " " << sum << " " << mn << " " << mx << '\n';
        ret++;
    }

    for(int i = now+1; i < N; i++) {
        if(check & (1 << i)) continue;

        check |= (1 << i);
        go(i, cnt+1, sum+v[i], min(mn,v[i]), max(mx,v[i]));
        check &= !(1 << i);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> L >> R >> X;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int i = 0; i < N; i++) {
        check |= (1 << i);
        go(i, 1, v[i], v[i], v[i]);
        check &= !(1 << i);
    }

    cout << ret;
}