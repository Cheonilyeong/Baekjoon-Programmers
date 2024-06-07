#include <bits/stdc++.h>
using namespace std; 

int N;
char a, b, c;
vector<char> v[27];

void preOrder(char now) {
    if(now == '.') return;

    cout << now;
    preOrder(v[now-'A'][0]);
    preOrder(v[now-'A'][1]);
}

void inOrder(char now) {
    if(now == '.') return;
    
    inOrder(v[now-'A'][0]);
    cout << now;
    inOrder(v[now-'A'][1]);
}

void postOrder(char now) {
    if(now == '.') return;
    
    postOrder(v[now-'A'][0]);
    postOrder(v[now-'A'][1]);
    cout << now;
}


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        v[a-'A'].push_back(b);
        v[a-'A'].push_back(c);
    }

    // 전위순회
    preOrder('A');
    cout << '\n';
    // 중위순회
    inOrder('A');
    cout << '\n';
    // 후위순회
    postOrder('A');
    cout << '\n';
}