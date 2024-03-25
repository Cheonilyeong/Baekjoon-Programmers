#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> a >> b;

        int num = 1;
        for(int i = 0; i < b; i++) {
            num *= a;
            num %= 10;
        }
        if(num == 0) num = 10;
        
        cout << num << '\n';
    }
}