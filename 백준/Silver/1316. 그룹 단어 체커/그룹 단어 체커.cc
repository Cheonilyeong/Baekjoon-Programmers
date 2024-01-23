#include <bits/stdc++.h>

using namespace std;

int n, cnt, check[26];
char pre;
string s;

int main(void) {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(char c : s) {
            if(pre != c && check[c - 'a']) {
                cnt++;
                break;
            }
            else {
                check[c - 'a']++;
                pre = c;
            }
        }
        fill(&check[0], &check[0] + 26, 0); // memset(check, 0, sizeof(check));
        pre = ' ';
    }
    cout << n - cnt;
}