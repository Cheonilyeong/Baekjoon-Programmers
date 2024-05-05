#include <bits/stdc++.h>
using namespace std;

int N, X, num, psum[250004];
vector<int> v;
map<long long, int> mp;

int main(void) {
    ios_base::sync_with_stdio(0);

    cin >> N >> X;

    for(int i = 1; i <= N; i++) {
        cin >> num;
        psum[i] = psum[i-1] + num;
    }

    for(int i = X; i <= N; i++) {
        mp[psum[i]-psum[i-X]]++;
    }

    auto it = *mp.rbegin();
    if(it.first == 0) cout << "SAD";
    else cout << it.first << ' ' << it.second;
}