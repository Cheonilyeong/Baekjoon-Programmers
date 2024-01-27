#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20004];
int ret, mx = INT_MIN, visited[20004];

int solution(int n, vector<vector<int>> edge) {    
    
    // 간선 저장
    for(vector<int> v : edge) {
        int A = v[0], B = v[1];
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    // 1부터 BFS
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    
    while(q.size()) {
        int from = q.front();
        q.pop();
        
        for(int to : adj[from]) {
            if(visited[to]) continue;
            q.push(to);
            visited[to] = visited[from] + 1;
            mx = max(mx, visited[to]);
        }
    }
    
    // 가장 멀리 떨어진 노드 개수 구하기 (1부터 n까지)
    for(int i = 1; i<n+1; i++) {
        if(visited[i] == mx) ret++;
    }
    
    return ret;
}