#include <bits/stdc++.h>
using namespace std;

int N, psum[2004];
int dif=INT_MAX, sum=INT_MIN;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    vector<int> v(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
        psum[i] = psum[i-1] + v[i];
    }

    // 임의의 학생 골라
    // i ~ i+j / i+j+1 ~ ..
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < N-i; j++) {

            int iSum, jSum = 0;
            // iSum 구하기
            iSum = psum[i+j] - psum[i-1];

            // jSum 구하기
            int l = i+j+1, r = N;
            while(l <= r) {
                int m = (l + r) / 2;

                jSum = psum[m] - psum[i+j];
                // jSum이 적으면 더해줘도 됨.
                if(iSum - jSum >= 0) {
                    l = m + 1;
                }
                // jSum이 크면 줄여줘도 됨.
                else if(iSum-jSum < 0) {
                    r = m - 1;
                }

                if(dif > abs(iSum-jSum)) {
                    dif = abs(iSum-jSum);
                    sum = iSum+jSum;
                }
                else if(dif == abs(iSum-jSum)) {
                    sum = max(sum,iSum+jSum);
                }
            }
        }
    }

    cout << sum;
}