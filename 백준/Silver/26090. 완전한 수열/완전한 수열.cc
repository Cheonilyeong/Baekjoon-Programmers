#include <bits/stdc++.h>
using namespace std;

int n, a, psum[504], ret;
const int max_n = 1000000;  // 제일 큰 경우의 수 -> 2000 * 500
bool che[max_n + 1];

// 에라토스테네스의 체
void era() {
    for(int i = 2; i <= max_n; i++) {
        if(che[i]) continue;
        for(int j = 2*i; j <= max_n; j+=i) {
            che[j] = 1;
        }
    }
}
int main(void) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    // 수열 받으면서 누적합 계산
    for(int i = 1; i <= n; i++) {
        cin >> a;
        psum[i] = psum[i-1] + a;
    }

    // 소수 구하기
    che[0] = che[1] = 1;
    era();

    // 브루트포스
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(che[j-i+1] == 0 && che[psum[j]-psum[i-1]] == 0) {
                ret++;
            }
        }
    }

    cout << ret;
}