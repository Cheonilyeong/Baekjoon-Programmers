#include <bits/stdc++.h>
using namespace std;

int a, b, t, cnt;
char m[104][104];
string s;

int main(void) {

    cin >> t;
    while(t--) {
        cin >> a >> b;
        for(int i = b; i < b + 10; i++) {
            for(int j = a; j < a + 10; j++) {
                m[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(m[i][j]) cnt++;
        }
    }
    
    cout << cnt;
}