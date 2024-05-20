#include <bits/stdc++.h>
using namespace std;

int N, ret, cnt[52];
double XY[52][52];
vector<double> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // 브루트포스
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            // 기울기 구하기
            XY[i][j] = (v[j]-v[i]) / (j-i);
        }
    }

    // 브루트포스
    for(int i = 0; i < N; i++) {
        double mx = -9999999999;
        for(int j = i+1; j < N; j++) {
            if(XY[i][j] > mx) {
                cnt[i]++;
                cnt[j]++;
                mx = XY[i][j];
            }
        }
    }

    for(int i = 0; i < N; i++) {
        ret = max(ret, cnt[i]);
    }

    cout << ret;
}