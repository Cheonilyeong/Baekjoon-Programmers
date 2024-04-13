#include <bits/stdc++.h>
using namespace std;

int N, M, num;
map<int,int> mp;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i  = 0; i < N; i++) {
        cin >> num;
        mp[num]++;
    }

    cin >> M;

    for(int i = 0; i < M; i++) {
        cin >> num;
        cout << mp[num] << ' ';
    }
}