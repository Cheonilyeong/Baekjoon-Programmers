#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
vector<pair<ll,ll>> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    sort(v.begin(), v.end());

    ll pre = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(pre == 0 || v[i].first > pre) {
            cnt++;
            pre = v[i].first + v[i].second;
        }
        else if(v[i].first <= pre) {
            pre = v[i].first+v[i].second;
        }
    }

    cout << cnt;
}