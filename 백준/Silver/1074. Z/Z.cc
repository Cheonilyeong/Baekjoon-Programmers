#include <bits/stdc++.h>
using namespace std;

int N, r, c, cnt, ret;
int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};

void go(int y, int x, int size) {
    if(size==0) {
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny==r && nx==c) ret = cnt;
        }
        return;
    }

    int m = (1 << size-1);

    if(r>=y && r<y+m && c>=x && c<x+m) go(y,x,size-1);
    cnt += (m*m);
    if(r>=y && r<y+m && c>=x+m && c<x+2*m) go(y,x+m,size-1);
    cnt += (m*m);
    if(r>=y+m && r<y+2*m && c>=x && c<x+m) go(y+m,x,size-1);
    cnt += (m*m);
    if(r>=y+m && r<y+2*m && c>=x+m && c<x+2*m) go(y+m,x+m,size-1);
    cnt += (m*m);
    
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> r >> c;

    go(0,0,N);

    cout << ret;
}