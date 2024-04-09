#include <bits/stdc++.h>
using namespace std;

int N, cnt;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    int i;
    for(i = 666; ; i++) {
        string s = to_string(i);
        if(s.find("666") != string::npos) cnt++;
        if(cnt == N) break;
    }

    cout << i;
}