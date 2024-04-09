#include <bits/stdc++.h>
using namespace std;

int a, b;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a,b);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b;

    cout << gcd(a,b) << '\n';
    cout << lcm(a,b) << '\n';
}