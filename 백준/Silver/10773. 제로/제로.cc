#include <bits/stdc++.h>
using namespace std;

int T, num, ret;
stack<int> st;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> num;

        if(num) st.push(num);
        else st.pop();
    }

    while(st.size()) {
        ret += st.top();
        st.pop();
    }

    cout << ret;
}