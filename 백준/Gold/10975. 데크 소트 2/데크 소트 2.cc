#include <bits/stdc++.h>
using namespace std;

int N, num, mode, pre=-11111, cnt;
vector<pair<int,int>> v;

int main(void) {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back({num, i});
    }

    sort(v.begin(), v.end());
    if(v[0].second < v[1].second) cnt++;
    if(v[N-2].second > v[N-1].second) cnt++;
    for(int i = 1; i < N-1; i++) {
        if(v[i-1].second > v[i].second && v[i].second < v[i+1].second) cnt++;
    }

    if(cnt == 0) cout << 1;
    else cout << cnt;
}