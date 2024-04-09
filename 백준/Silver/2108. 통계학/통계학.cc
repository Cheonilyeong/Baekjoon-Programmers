#include <bits/stdc++.h>
using namespace std;

int N, num, sum;
vector<int> v;
map<int,int> mp;
vector<pair<int,int>> cnt;

bool compare(pair<int,int> &a, pair<int,int> &b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        mp[v[i]]++;
        sum += v[i];
    }

    sort(v.begin(), v.end());

    for(const auto &it : mp) {
        cnt.push_back({it.second, it.first});
    }
    
    sort(cnt.begin(), cnt.end(), compare);

    if(round((double)sum/N) == -0) cout << 0 << '\n';
    else cout << round((double)sum/N) << '\n';
    cout << v[N/2] << '\n';
    if(cnt.size() == 1 || cnt[0].first != cnt[1].first) cout << cnt[0].second << '\n';
    else cout << cnt[1].second << '\n';    
    cout << v[N-1] - v[0];
}