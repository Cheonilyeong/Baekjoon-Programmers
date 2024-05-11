#include <bits/stdc++.h>
using namespace std;

int N, num, T, arr[103][103], new_arr[103][103];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    // 배열 받기
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    // 연산
    cin >> T;
    while(T--) {
        cin >> num;

        // 1이면
        if(num == 1) {
            cin >> num;
            int t = arr[num][N];
            for(int i = N; i >= 0; i--) {
                arr[num][i] = arr[num][i-1];
            }
            arr[num][1] = t;
        }
        // 2면
        else if(num == 2) {
            // 시계방향 90도 회전
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    new_arr[j][N-i+1] = arr[i][j];
                }
            }

            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    arr[i][j] = new_arr[i][j];
                }
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << arr[i][j] << ' ' ;
        }
        cout << '\n';
    }
}