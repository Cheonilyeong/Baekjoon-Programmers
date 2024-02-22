#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, ret, visited[100];
vector<int> v[100][2];

int cntL(int i) {
    visited[i] = 1;
    int sum = 1;
    for(int n : v[i][0]) {
        if(visited[n] == 0) {
            sum += cntL(n);
        }
    }

    return sum;
}

int cntR(int i) {
    visited[i] = 1;
    int sum = 1;
    for(int n : v[i][1]) {
        if(visited[n] == 0) {
            sum += cntR(n);
        }
    }

    return sum;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a][0].push_back(b);
        v[b][1].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        if(cntL(i) > ((N+1)/2)) {ret++; continue;}
        memset(visited, 0, sizeof(visited));
        if(cntR(i) > ((N+1)/2)) {ret++; continue;}
    }

    cout << ret;
}