#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
long long ret = 1;
long long N;

int main(void) {
    cin >> N;

    while(N) {
        ret *= N-1;
        ret %= mod;

        N -= 2;
    }

    cout << ret;
}