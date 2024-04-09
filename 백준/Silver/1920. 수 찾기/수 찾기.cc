#include <bits/stdc++.h>
using namespace std;

int N, num;
set<int> st;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    while(N--) {
        cin >> num;
        st.insert(num);
    }

    cin >> N;
    while(N--) {
        cin >> num;
        if(st.find(num) == st.end()) cout << "0\n";
        else cout << "1\n";
    }
}