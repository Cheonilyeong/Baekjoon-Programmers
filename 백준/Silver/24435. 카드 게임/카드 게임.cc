#include <bits/stdc++.h>
using namespace std;

int T, N, ret, visited[11];
string Bob, Alice, t;

void go(string num) {
    if(atoi(num.c_str()) < atoi(Bob.c_str()) && atoi(num.c_str()) < atoi(t.c_str())) 
        ret = max(ret,atoi(num.c_str()));

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;

        visited[i] = 1;
        go(num+Alice[i]);
        visited[i] = 0;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;

        cin >> Bob;
        cin >> Alice;

        memset(visited, 0, sizeof(visited));
        ret = INT_MIN;
        t = Bob; reverse(t.begin(), t.end());
        for(int i = 0; i < N; i++) {
            visited[i] = 1;
            go(Alice.substr(i,1));
            visited[i] = 0;
        }

        cout << ret << '\n';
    }
}