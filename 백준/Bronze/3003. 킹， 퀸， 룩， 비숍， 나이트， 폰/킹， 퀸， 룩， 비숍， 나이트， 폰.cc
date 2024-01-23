#include <bits/stdc++.h>

using namespace std;

int check[6] = {1, 1, 2, 2, 2, 8};
int cnt[6];

int main(void) {
    
    for(int i = 0; i < 6; i++) {
        cin >> cnt[i];
    }

    for(int i = 0; i < 6; i++) {
        cout << check[i] - cnt[i] << ' ';
    }
}