#include <bits/stdc++.h>
using namespace std;

int N, M, num, num2, cnt, pre, arr[1000004];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    // 바이너리 길 상태
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        if(pre == 0 && arr[i] == 1) cnt++;
        pre = arr[i];
    }

    // 시련
    for(int i = 0; i < M; i++) {
        cin >> num;

        // 더렵
        if(num) {
            cin >> num2;

            if(arr[num2] == 1) continue;
            if(N == 1) {cnt = 1; continue;}
            
            arr[num2] = 1;
            if(num2 == 1) {if(arr[num2+1] == 0) cnt++;}
            else if(num2 == N) {if(arr[num2-1] == 0) cnt++;}
            else {
                if(arr[num2-1] == 1 && arr[num2+1] == 1) cnt--;
                if(arr[num2-1] == 0 && arr[num2+1] == 0) cnt++;
            }
        }
        // flip
        else {
            cout << cnt << '\n';
        }
    }
}