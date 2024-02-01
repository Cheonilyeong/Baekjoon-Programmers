#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, cnt;
set<string> st;

void go(string s, int cnt) {
    if(cnt > 5) return;

    // ex) s = 11

    // 1111 저장
    string t = s;
    reverse(t.begin(), t.end());
    st.insert(s+t);

    // 11011 ~ 11911 저장
    for(int i = 0; i <= 9; i++) {
        st.insert(s + to_string(i) + t);
    }
    
    // 브루트포스
    for(int i = 0; i <= 9; i++) {
        go(s + to_string(i) , cnt+1);
    }
}

int main(void) {
    cin >> n;

    // 1 ~ 9 저장
    for(int i = 1; i <= 9; i++) {
        st.insert(to_string(i));
    }
    // 11 ~ 1e10 저장
    for(int i = 1; i <= 9; i++) {
        go(to_string(i), 1);
    }

    // 개수 세기
    string ns = to_string(n); // n을 string으로 변환
    for(auto it : st) {
        if(it.size() < ns.size()) cnt++;
        else if(it.size() == ns.size() && it <= ns)  cnt++;
    }

    cout << cnt;
}