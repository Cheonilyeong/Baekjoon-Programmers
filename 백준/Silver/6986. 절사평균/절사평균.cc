#include <bits/stdc++.h>
using namespace std;

int N, K;
double num;
vector<double> v;


int main(void) {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    // 점수
    for(int i = 0; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    // 정렬
    sort(v.begin(), v.end());

    // 절사평균
    double sum = 0, avg;
    for(int i = K; i < (N-K); i++) {
        sum += v[i];
    }    
    avg = round((sum / (N-2*K)) * 100) / 100 ;
    printf("%.2lf\n", avg);


    // 보정평균
    sum = 0;
    for(int i = 0; i < K; i++) {
        sum += v[K];
    }
    for(int i = K; i < (N-K); i++) {
        sum += v[i];
    }
    for(int i = 0; i < K; i++) {
        sum += v[N-K-1];
    }
    avg = round((sum / (N)) * 100) / 100 ;
    printf("%.2lf\n", avg);
}