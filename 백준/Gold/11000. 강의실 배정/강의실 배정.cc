#include <bits/stdc++.h>

using namespace std;

int N, a, b, ret;
vector<pair<int,int>> v;       // S, T
priority_queue<int, vector<int>, greater<int>> pq;  // T

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    while(N--) {
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), less<pair<int,int>>());

    for(auto it : v) {
        if(pq.empty()) {
            pq.push(it.second);
            ret = max(ret, (int)pq.size());
        }
        else {
            if(it.first >= pq.top()) {
                pq.pop();
                pq.push(it.second);
            }
            else {
                pq.push(it.second);
                ret = max(ret, (int)pq.size());
            }
        }
    }

    cout << ret;
}