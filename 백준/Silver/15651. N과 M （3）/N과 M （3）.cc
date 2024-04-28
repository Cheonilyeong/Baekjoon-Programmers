#include <bits/stdc++.h>
using namespace std;

int N, M;

void go(string num, int cnt) {
    if(cnt == M) {
        cout << num << '\n';
        return;
    }

    for(int i = 1; i <= N; i++) {
        go(num+' '+to_string(i), cnt+1);
    }
}
int main(void) {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        go(to_string(i), 1);
    }
}