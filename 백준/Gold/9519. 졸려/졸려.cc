#include <bits/stdc++.h>

using namespace std;

int n, cnt;
string s, pre;

int main(void) {

    cin >> n;
    cin >> s;

    pre = s; 

    while(n--) {
        string t = "";
        for(int i = 0; i<s.size(); i+=2) t += pre[i];
        if(s.size() & 1) 
            for(int i = s.size()-2; i>=0; i-=2) t += pre[i];
        else 
            for(int i = s.size()-1; i>=0; i-=2) t += pre[i];
        pre = t;

        cnt++;

        // 사이클 구해서 생략하기
        if(t == s) {
            n %= cnt;
        }
    }

    cout << pre;
}