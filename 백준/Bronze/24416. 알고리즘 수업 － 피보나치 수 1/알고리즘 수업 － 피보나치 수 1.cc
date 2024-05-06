#include <bits/stdc++.h>
using namespace std;

int n, cnt;
long long dp1[44];
long long dp2[44];

long long fib1(int num) {
    if(dp1[num]) return dp1[num];
    if(num==1 || num==2) return 1;

    return dp1[num] = fib1(num-1) + fib1(num-2);
}

int fib2(int num) {
    int cnt = 0;

    dp2[1] = dp2[2] = 1;
    for(int i = 3; i <= num; i++, cnt++) {
        dp2[i] = dp2[i-1] + dp2[i-2];
    }

    return cnt;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    cout << fib1(n) <<  ' ' << fib2(n);
}