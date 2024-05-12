#include <bits/stdc++.h>
using namespace std;

int T, N, M, num;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {

        cin >> N >> M;

        vector<int> v(N);
        double sum1 = 0, avg1;
        for(int i = 0; i < N; i++) {
            cin >> num;
            v[i] = num;
            sum1 += num;
        }
        avg1 = sum1/N;

        double sum2 = 0, avg2;
        for(int i = 0; i < M; i++) {
            cin >> num;
            sum2 += num;
        }
        avg2 = sum2/M;

        int ret = 0;
        for(int it : v) {
            if(it < avg1 && it > avg2) ret++;
        }

        cout << ret << '\n';
    }

    
}