#include <bits/stdc++.h>
using namespace std;

int N, cnt[54];
vector<pair<int,int>> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(v[i].first > v[j].first && v[i].second > v[j].second) cnt[j]++;
            if(v[i].first < v[j].first && v[i].second < v[j].second) cnt[i]++;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << cnt[i]+1 << ' ';
    }
}