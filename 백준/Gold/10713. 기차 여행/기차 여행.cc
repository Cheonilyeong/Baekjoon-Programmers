#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int A;
    int B;
    int C;
}city;

int N, M, a, cnt[100004];
long long ret;
city c;
vector<int> P;
vector<city> C;


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    // 방문 예정 도시 받기
    for(int i = 0; i < M; i++) {
        cin >> a;
        P.push_back(a-1);
    }
    // 도시 티켓 정보 받기
    for(int i = 0; i < N-1; i++) {
        cin >> c.A >> c.B >> c.C;
        C.push_back(c);
    }

    // 각 도시 방문 횟수 조회
    for(int i = 0; i < M-1; i++) {
        if(P[i] > P[i+1]) {
            for(int j = P[i]; j > P[i+1]; j--) {
                cnt[j-1]++;
            }
        }
        if(P[i] < P[i+1]) {
            for(int j = P[i]; j < P[i+1]; j++) {
                cnt[j]++;
            }
        }
    }
    
    // 계산
    for(int i = 0; i < N-1; i++) {
        //cout << C[i].A << ' ' << C[i].B << ' ' << C[i].C << ' ' << cnt[i] << '\n';
        ret += min(C[i].A * cnt[i], C[i].C + cnt[i] * C[i].B);
    }

    cout << ret;
}