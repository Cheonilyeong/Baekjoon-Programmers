#include <bits/stdc++.h>
using namespace std;

int N, M, K, v, w, sum, visited[100004];
vector<int> A;
vector<int> adj[100004];

int findMn(int i) {
    int mn = A[i];

    for(int j : adj[i]) {
        if(visited[j] == 0) {
            visited[j] = 1;
            mn = min(mn,findMn(j));
        }
    }

    return mn;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    A.resize(N+1);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> v >> w;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    for(int i = 1; i <= N; i++) {
        
        if(visited[i] == 0) {
            visited[i] = 1;  
            sum += findMn(i);          
        }
    }

    if(sum > K) cout << "Oh no";
    else cout << sum;
}