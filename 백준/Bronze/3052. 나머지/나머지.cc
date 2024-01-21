#include <bits/stdc++.h>

using namespace std;

int a, cnt[44], ret;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 10; i++) {
        cin >> a;
        cnt[a % 42]++;
    }
    for(int i = 0; i < 42; i++) {
        if(cnt[i]) ret++;
    }
    cout << ret;
}