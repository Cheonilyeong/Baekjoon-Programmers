#include <bits/stdc++.h>
using namespace std;

int N, M, num;
map<int,int> mp;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    v.resize(N);
    // 배열받기
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    // mp에 처음나온 위치 넣기
    for(int i = N-1; i >= 0; i--) {
        mp[v[i]] = i;
    }

    // 질문받기
    for(int i = 0; i < M; i++) {
        cin >> num;

        if(mp.find(num) == mp.end()) {
            cout << -1 << '\n';
        }
        else cout << mp[num] << '\n';
    }
}