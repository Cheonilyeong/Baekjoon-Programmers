#include <bits/stdc++.h>
using namespace std;

int N, num;
map<int, vector<int>> mp;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> num;
        mp[num].push_back(i);
    }

    int cnt = 0;
    vector<int> ret(N);
    for(auto it : mp) {
        for(int i : it.second) {
            ret[i] = cnt;
        }
        cnt += 1;
    }

    for(int i : ret) {
        cout << i << ' ';
    }
}