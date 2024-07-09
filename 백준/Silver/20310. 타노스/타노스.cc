#include <bits/stdc++.h>
using namespace std;

string str;
int cnt0, cnt1;

int main() {
    ios_base::sync_with_stdio; cin.tie(0); cout.tie(0);

    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '0') cnt0++;
        if(str[i] == '1') cnt1++;
    }
    cnt0 /= 2;
    cnt1 /= 2;

    int show0=0, show1=0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '0') {
            if(show0 < cnt0) {
                cout << '0';
                show0++;
            }
        }
        if(str[i] == '1') {
            if(show1 >= cnt1) {
                cout << '1';
            }
            else show1++;
        }
    }
}