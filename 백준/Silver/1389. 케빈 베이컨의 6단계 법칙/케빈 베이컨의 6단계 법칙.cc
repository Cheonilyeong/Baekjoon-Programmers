#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, dist[104][104];
int mn=INT_MAX, ret=INT_MAX;
const int INF = 1e9;
vector<int> v[104];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fill(&dist[0][0], &dist[103][103], INF);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        dist[a-1][b-1] = 1;
        dist[b-1][a-1] = 1;
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            sum += dist[i][j];
        }
        if(mn>sum) mn=sum, ret=i;
    }

    cout << ret+1;
}