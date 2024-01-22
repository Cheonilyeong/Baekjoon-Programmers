#include <bits/stdc++.h>

using namespace std;

int n, sum;
string s;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++) {
        sum += (s[i] - '0');
    }
    cout << sum;
}