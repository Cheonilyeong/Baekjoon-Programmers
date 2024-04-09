#include <bits/stdc++.h>
using namespace std;

int N, num, cnt=1;
queue<int> q;
stack<int> st;
vector<char> ret;
bool flag = true;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> num;
        q.push(num);
    }

    while(q.size()) {

        if(st.empty()) {
            st.push(cnt++);
            ret.push_back('+');
            continue;
        }

        int numQ = q.front();
        int numSt = st.top();

        if(numQ == numSt) {
            ret.push_back('-');
            st.pop();
            q.pop();
        }
        else {
            if(numQ > numSt) {
                st.push(cnt++);
                ret.push_back('+');
            }
            else if(numQ < numSt) {
                flag = false;
                break;
            }
        }
    }

    if(flag) {
        for(char c : ret) {
            cout << c << '\n';
        }
    }
    else cout << "NO";

}