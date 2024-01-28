#include <bits/stdc++.h>

using namespace std;

int adj[104][104];
int visited[104], ret=INT_MAX;

int go(int here, int n) {
    int sum = 1;
    
    for(int there = 1; there < n+1; there++) {
        if(visited[there] || adj[there][here] == 0) continue;
        visited[there] = 1;
        sum += go(there, n);
    } 
    
    return sum;
}

int solution(int n, vector<vector<int>> wires) {
    
    // 간선 저장
    for(vector<int> edge : wires) {
        adj[edge[0]][edge[1]] = 1;
        adj[edge[1]][edge[0]] = 1;
    }
    
    // 브루트포스
    for(int i = 0; i<wires.size(); i++) {
        vector<int> cnt;
        
        // 지울 간선 뽑기
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        // 간선 지우기
        adj[v1][v2] = 0; adj[v2][v1] = 0;
        // 개수 세기
        for(int j = 1; j<n+1; j++) {
            if(visited[j]) continue;
            visited[j] = 1;
            cnt.push_back(go(j, n));
        }
        // 두 전력망 차이 구하기
        ret = min(ret, abs(cnt[0] - cnt[1]));
        
        // 원상복구
        adj[v1][v2] = 1; adj[v2][v1] = 1;
        memset(visited, 0, sizeof(visited));
    }
    
    return ret;
}