#include <bits/stdc++.h>
using namespace std;

int n, a, sum, mn=INT_MAX, XOR;

int main(void) {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    while(n--) {
        cin >> a;
        sum += a;
        XOR ^= a;
        mn = min(mn, a);
    }

    if(XOR == 0) {
        cout << sum - mn;
    }
    else cout << 0;
        
}