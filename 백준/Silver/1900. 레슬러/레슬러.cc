#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int,double>> v;
vector<pair<double,int>> cnt;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N); cnt.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        cnt[i].first = (v[i].second-1) / v[i].first;
    }

    for(int i = 0; i < N; i++) cnt[i].second = i;
 
    sort(cnt.begin(), cnt.end(), greater<pair<double,int>>());
    for(auto it : cnt) cout << it.second+1 << '\n';
}