#include <bits/stdc++.h>
using namespace std;
#define time time2

int N, s, e, cnt, time;
vector<pair<int,int>> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    while(N--) {
        cin >> s >> e;
        v.push_back(make_pair(e,s));
    }

    sort(v.begin(),v.end());

    for(auto it : v) {
        if(time <= it.second) {
            time = it.first;
            cnt++;
        }
    }

    cout << cnt;
}