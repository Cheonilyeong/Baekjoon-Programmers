#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, u, v, w, start, target;
int adj[1004][1004], parent[1004];
long long dist[1004];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<int> way;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> m;

    fill(&adj[0][0], &adj[0][0]+1004*1004, INF);
    fill(&dist[0], &dist[0]+1004, INF);

    while(m--) {
        cin >> u >> v >> w;
        if(w < adj[u][v]) {
            adj[u][v] = w;
        }
    }

    cin >> start >> target;

    dist[start] = 0;
    pq.push({0, start});

    while(pq.size()) {
        auto it = pq.top(); pq.pop();

        for(int i = 1; i <= n; i++) {
            if(adj[it.second][i] != INF && dist[it.second] + adj[it.second][i] < dist[i]) {
                dist[i] = dist[it.second] + adj[it.second][i];
                parent[i] = it.second;
                pq.push({dist[i], i});
            }
        }
    }

    int current = target;
    while(current != start) {
        way.push_back(current);
        current = parent[current];
    }
    way.push_back(start);

    cout << dist[target] << '\n' << way.size() << '\n';
    
    reverse(way.begin(), way.end());
    for(auto node : way) {
        cout << node << ' ';
    }
}