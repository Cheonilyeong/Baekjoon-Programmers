#include <bits/stdc++.h>
using namespace std;

int N, mp[130][130];
int white, blue;

void go(int y, int x, int size) {

    int b_cnt = 0;

    for(int i = y; i < y+size; i++) {
        for(int j = x; j < x+size; j++) {
            if(mp[i][j]) b_cnt++; 
        }
    }

    if(b_cnt == 0) white++;
    else if(b_cnt == size*size) blue++;
    else {
        go(y,x,size/2);
        go(y,x+size/2,size/2);
        go(y+size/2,x,size/2);
        go(y+size/2,x+size/2,size/2);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mp[i][j];
        }
    }

    go(0,0,N);

    cout << white << '\n' << blue;
}