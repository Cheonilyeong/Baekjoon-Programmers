#include <bits/stdc++.h>
using namespace std;
#define ll long long

int A, B, C;

ll mod(ll a, ll b, ll c) {
    ll result = 1;
    while(b) {
        if(b&1) result = (result%c * a%c) % c;
        a = (a%c * a%c) % c;
        b >>= 1;
    }
    return result%c;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> A >> B >> C;

    cout << mod(A,B,C);
}