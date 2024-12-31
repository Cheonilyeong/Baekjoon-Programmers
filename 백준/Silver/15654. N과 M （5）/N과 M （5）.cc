#include <bits/stdc++.h>

using namespace std;

int N, M, visited[10];
vector<int> v;

void go(string str, int now, int cnt) {
    if(cnt == M) {
        cout << str << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = 1;
        go(str + ' ' + to_string(v[i]), i, cnt+1);
        visited[i] = 0;
    }
}

int main() {
    
    cin >> N >> M;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++) {
        visited[i] = 1;
        go(to_string(v[i]), i, 1);
        visited[i] = 0;
    }
}