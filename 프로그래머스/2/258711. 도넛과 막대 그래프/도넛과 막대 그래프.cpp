#include <bits/stdc++.h>
using namespace std;

int v, visited[1000004];
vector<int> adj[1000004];
map<int,int> cntIn;
map<int,int> cntOut;

int check(int start, int i) {
    
    int type;   // 1:도넛 2:막대 3:8자

    // 사이클이 없으면 막대
    if(adj[i].size() == 0) return 2;

    // 진출차수가 2개인 정점이 있으면 8자
    if(adj[i].size() == 2) return 3;

    for(int next : adj[i]) {
        // 사이클이 생기면 도넛
        if(start == next) return 1;

        type = check(start, next);
    }

    return type;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    
    // 임의의 정점은 진출차수가 2 이상, 진입차수는 0이다.

    // 진출차수, 진입차수 개수 세기
    for(vector<int> e : edges) {
        cntOut[e[0]]++;
        cntIn[e[1]]++;
        adj[e[0]].push_back(e[1]);
    }
    // 진출차수가 2개 이상 있는데 진입차수가 없으면 임의의 정점이다.
    for(auto it : cntOut) {
        if(it.second  >= 2 && cntIn[it.first] == 0) {
            v = it.first;
            answer[0] = v;
        }
    }

    // 임의의 정점에서 연결되어있는 각 그래프 확인
    for(int i : adj[v]) {
        answer[check(i, i)]++;
    }

    return answer;
}