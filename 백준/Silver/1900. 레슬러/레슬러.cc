#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int,int>> v;
vector<pair<int,int>> cnt;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N); cnt.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for(int i = 0; i < N; i++) cnt[i].second = i;

    for(int i = 0; i < N-1; i++) {
        for(int j = i + 1; j < N; j++) {

            int a = v[i].first + v[j].first * v[i].second;
            int b = v[j].first + v[i].first * v[j].second;
            
            if(a > b) cnt[i].first++;
            else if(a < b) cnt[j].first++;
        }
    }
    
    sort(cnt.begin(), cnt.end(), greater<pair<int,int>>());
    for(auto it : cnt) cout << it.second+1 << '\n';
}