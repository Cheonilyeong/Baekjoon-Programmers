#include <bits/stdc++.h>
using namespace std;

int mx = INT_MIN;
string ret;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(1) {
        cin >> s;
        if(s == "E-N-D") break;
        
        int start = -1, cnt = 0, i = 0;
        for(i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) {
                if(start == -1) start = i;
                cnt++;
                if(mx < cnt) {
                    mx = cnt;
                    ret = s.substr(start,i-start+1);
                }
            }
        }
    }

    for(char &c : ret) {
        c = tolower(c);
    }

    cout << ret;
}