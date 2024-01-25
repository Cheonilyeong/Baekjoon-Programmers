#include <bits/stdc++.h>

using namespace std;

int a;
long long n, b;
string ret;

int main(void) {
    cin >> n >> b;
    
    while(n != 0) {
        int a = n % b;

        if(a >= 10) {
            ret += (char)(a - 10 + 'A');
        }
        else {
            ret += a + '0';
        }

        n /= b;
    }

    reverse(ret.begin(), ret.end());

    cout << ret;
}