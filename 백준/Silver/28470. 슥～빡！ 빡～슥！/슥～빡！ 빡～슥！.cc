#include <bits/stdc++.h>
using namespace std;

int N;
long long ret;
vector<pair<int,int>> v;
vector<float> K;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N); K.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i].first;
    for(int i = 0; i < N; i++) cin >> v[i].second;
    for(int i = 0; i < N; i++) cin >> K[i];

    for(int i = 0; i < N; i++) {
        int a = (floor)((v[i].first * (K[i] * 10))/10) - v[i].second;
        int b = v[i].first - (floor)((v[i].second * (K[i] * 10))/10);
        
        ret += max(a,b);
    }

    cout << ret;
}