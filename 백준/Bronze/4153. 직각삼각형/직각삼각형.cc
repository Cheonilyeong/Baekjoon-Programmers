#include <bits/stdc++.h>
using namespace std;

int x, y, z;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(cin >> x >> y >> z) {
        if(!x && !y && !z) break;
        if(!x || !y || !z) {cout << "wrong\n"; continue;}

        int mx = max(max(x,y), max(y,z));

        if(mx*mx == x*x + y*y + z*z - mx*mx) cout << "right\n";
        else cout << "wrong\n";
    }
}