#include <bits/stdc++.h>
using namespace std;

int N, n, a, t, ret;
stack<pair<int,int>> st;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> n;
        if(n == 1) {
            cin >> a >> t;
            if(t == 1) ret += a;
            else st.push({a, t-1});
        }
        else {
            if(st.empty()) continue;
            tie(a,t) = st.top();
            st.pop();
            if(t == 1) ret += a;
            else st.push({a, t-1});
        }
    }

    cout << ret;
}