#include <bits/stdc++.h>
using namespace std;

long long N, ret;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    // 앞자리 수
    for(int i = 1; i <= 9; i++) {
        if(i <= N) ret++;
        else break;
        // 등차
        for(int j = -9; j < 9; j++) {

            string num = to_string(i);
            int n = i;
            // 등차 더해가기
            while(1) {
                n += j;
                if(n >= 0 && n < 10) {
                    num += to_string(n);
                }
                else break;
                
                if(atoll(num.c_str()) <= N) ret++;
                else break;
            }
        }
    }


    cout << ret;
}