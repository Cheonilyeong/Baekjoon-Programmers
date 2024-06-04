#include <bits/stdc++.h>
using namespace std;

int T, N;
char c;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;

        vector<char> v(N);
        for(int i = 0; i < N; i++) {
            cin >> v[i];
        }

        deque<char> dq;
        for(char c : v) {
            if(dq.size() == 0) dq.push_back(c);
            else if(c <= dq.front()) dq.push_front(c);
            else dq.push_back(c);
        }

        while(dq.size()) {
            cout << dq.front();
            dq.pop_front();
        }

        cout << '\n';
    }
}