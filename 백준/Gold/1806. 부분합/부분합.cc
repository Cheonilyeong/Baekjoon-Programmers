#include <bits/stdc++.h>
using namespace std;

int N, S, num, sum, l, r, ret=INT_MAX;
vector<int> v;
queue<int> q;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> S;

    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }

    sum = v[0];
    while(1) {
        
        if(sum >= S) {
            ret = min(ret, r-l+1);
            sum -= v[l++];
        }
        else {
            if(r == N-1) break;
            else sum += v[++r];
        }
    }

    if(ret == INT_MAX) cout << 0;
    else cout << ret;
}