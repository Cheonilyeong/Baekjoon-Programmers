#include <bits/stdc++.h>

using namespace std;

int a, b, n , pay, sum;

int main(void) {
    cin >> pay;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        sum += (a * b);
    }
    if(sum != pay) cout << "No";
    else cout << "Yes";
}