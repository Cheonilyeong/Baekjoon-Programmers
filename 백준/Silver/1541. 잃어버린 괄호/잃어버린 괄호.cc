#include <bits/stdc++.h>
using namespace std;

int ret, num;
bool flag = false;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i]=='+' || s[i] == '-') {
            if(flag) ret -= num;
            else ret += num;

            num = 0;

            if(s[i]=='-') flag = true;
        }
        else {
            num = num*10 + (s[i]-'0');
        }
    }

    if(flag) ret -= num;
    else ret += num;

    cout << ret;
}

    