#include <bits/stdc++.h>

using namespace std;

int n;
long long ret;
string s;

int main(void) {
    cin >> s >> n;
    
    for(int i = 0; i<s.size(); i++) {
        if(isalpha(s[i])) {
            ret += (s[i]-'A'+10) * pow(n, s.size()-i-1);
        }
        else ret += (s[i]-'0') * pow(n, s.size()-i-1);
    }

    cout << ret;
}