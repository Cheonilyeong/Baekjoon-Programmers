#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int A;
    int B;
    int C;
}city;

int N, M, a;
long long ret, cnt[100004], psum[100004];;
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
        int from = P[i];
        int to = P[i+1];
        if(from > to) swap(from,to);
        cnt[from]++;
        cnt[to]--;
    }
    for(int i = 0; i < N; i++) {
        psum[i] = psum[i-1] + cnt[i];
    }

    // 계산
    for(int i = 0; i < N-1; i++) {
        ret += min(C[i].A * psum[i], C[i].C + psum[i] * C[i].B);
    }

    cout << ret;
}