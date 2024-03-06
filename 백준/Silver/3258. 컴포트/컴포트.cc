#include <bits/stdc++.h>
using namespace std;

int N, Z, M, n, a[1004], ret;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> Z >> M;

    // 장애물
    for(int i = 0; i < M; i++) {
        cin >> n;
        a[n] = 1;
    }

    // 브루트포스
    for(int K = 1; K <= N-1; K++) {
        int here = 1, cnt = 0;
        bool flag = true;

        while(1) {
            here += K;
            if(here > N) here -= N;
            // 장애물이 있으면
            if(a[here]) {
                flag = false;
                break;
            }
            // 도착지에 도착하면
            if(here == Z) {
                break;
            }
            // 무한루프 방지
            if(here == 1 && cnt) {
                flag = false;
                break;
            }
            cnt++;
        }

        if(flag) {
            ret = K;
            break;
        }
    }

    cout << ret;
}