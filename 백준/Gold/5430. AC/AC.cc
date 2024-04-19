#include <bits/stdc++.h>
using namespace std;

int T, N;
string s, NS;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> s;
        cin >> N;
        cin >> NS;

        deque<int> dq;
        int num = 0;
        for(int i = 1; i < NS.size(); i++) {
            if(NS[i] == ',' || NS[i] == ']' && num != 0) {
                dq.push_back(num);
                num = 0;
            }
            else {
                num = num*10 + NS[i]-'0';
            }
        }

        int mode = 0;
        vector<int> ret;
        bool flag = true;
        for(char c : s) {
            if(c == 'R') mode = !mode;
            if(c == 'D') {
                if(dq.size()) {
                    if(!mode) dq.pop_front();
                    else dq.pop_back();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) {
            cout << '[';
            if(!mode) {
                while(dq.size()) {
                    cout << dq.front(); dq.pop_front();
                    if(dq.size()) cout << ',';
                }
            }
            else {
                while(dq.size()) {
                    cout << dq.back(); dq.pop_back();
                    if(dq.size()) cout << ',';
                }
            }
            cout << ']'; cout << '\n';
        }
        else {
            cout << "error\n";
        }
    }
}