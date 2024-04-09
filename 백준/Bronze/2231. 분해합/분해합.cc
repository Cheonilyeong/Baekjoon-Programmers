#include <bits/stdc++.h>
using namespace std;

int N, ret;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        string s = to_string(i);
        int sum = i;
        for(char c : s) sum += c-'0';

        if(sum == N) {ret = i; break;}
    }

    cout << ret;
}