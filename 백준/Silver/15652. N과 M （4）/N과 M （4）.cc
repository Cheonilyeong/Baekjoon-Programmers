#include <bits/stdc++.h>

using namespace std;

int N, M;

void go(string str, int now, int cnt) {
    if(cnt == M) {
        cout << str << '\n';
        return;
    }

    for(int i = now; i <= N; i++) {
        go(str + ' ' + to_string(i), i, cnt+1);
    }
}

int main() {
    
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        go(to_string(i), i, 1);
    }
}