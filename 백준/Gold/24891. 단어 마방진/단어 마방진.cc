#include <bits/stdc++.h>

using namespace std;

int L, N, visited[24];
string s;
vector<string> words;
vector<string> ret;

bool check() {
    // 대각선 대칭 검사
    for(int i = 0; i<L; i++) {
        for(int j = 0; j<L; j++) {
            if(ret[i][j] != ret[j][i]) return false;
        }
    }
    return true;
}

bool go(int idx, int cnt) {
    if(cnt == L) return check();        // 마방진 완성되면 true 리턴

    for(int i = 0; i<N; i++) {
        if(visited[i]) continue;
        ret.push_back(words[i]); visited[i] = 1;
        if(go(i+1, cnt+1)) return true; // 마방진 완성되면 완전탐색 중단하고 계속 빠져나옴
        ret.pop_back();          visited[i] = 0;
    }

    return false;
}
int main(void) {
    cin >> L >> N;

    for(int i = 0; i<N; i++) {
        cin >> s;
        words.push_back(s);
    }

    sort(words.begin(), words.end());   // 사전순으로 빠르게 만들기 위해서

    if(go(0,0)) for(string s : ret) cout << s << '\n';
    else cout << "NONE";

    return 0;
}