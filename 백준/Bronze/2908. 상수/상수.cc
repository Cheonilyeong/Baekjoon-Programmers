#include <bits/stdc++.h>

using namespace std;

int a, b;
string s1, s2;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> a >> b;
    string s1 = to_string(a);
    string s2 = to_string(b);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    if(s1 > s2) cout << s1;
    else cout << s2;
}