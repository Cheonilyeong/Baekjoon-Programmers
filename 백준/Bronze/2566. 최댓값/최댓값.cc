#include <bits/stdc++.h>
using namespace std;

int n, mx, mx_x, mx_y;
int main(void) {

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> n;
            if(n > mx) {
                mx = n;
                mx_x = j;
                mx_y = i;
            }
        }
    }

    cout << mx << '\n';
    cout << mx_y + 1 << ' ' << mx_x + 1;
    
}