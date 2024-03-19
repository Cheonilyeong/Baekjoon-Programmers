#include <bits/stdc++.h>
using namespace std;

int T, H, W, N;

int main(void) {

    cin >> T;

    while(T--) {
        cin >> H >> W >> N;

        int h = N % H;
        int w = N / H + 1;

        if(h == 0) {
            h = H;
            w -= 1;
        }
        printf("%d%02d\n", h, w);        
    }
}