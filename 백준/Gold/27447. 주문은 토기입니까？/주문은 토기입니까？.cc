#include <bits/stdc++.h>
using namespace std;

int N, M, n, t, c;
bool flag = true;
queue<int> p1;
queue<int> p2;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> n;
        p1.push(n);
        p2.push(n);
    }


    for(int i = 0; i <= 1000000; i++) {
        // 손님이 다 왔으면
        if(p1.empty()) break;
        
        // 손님이 있으면
        if(p1.front() == i) {
            if(c < 1) {flag = false; break;}
            else {
                c--;
                p1.pop();
            }
        }
        // 손님이 없으면
        else {
            // 손님이 올 예정이면 커피 담기
            if(p2.size() && (p2.front() - i) <= M && t > 0) {
                t--;
                c++;
                p2.pop();
            }
            // 토기 만들기
            else {
                t++;
            }
        }
    }

    if(flag) cout << "success" << '\n';
    else cout << "fail" << '\n';
}