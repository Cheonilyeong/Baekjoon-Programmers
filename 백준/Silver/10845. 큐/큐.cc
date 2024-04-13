#include <bits/stdc++.h>
using namespace std;

int N, num;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    queue<int> q;
    while(N--) {
        cin >> s;
        
        if(s == "push") {
            cin >> num;
            q.push(num);
        }
        if(s == "pop") {
            if(q.empty()) cout << -1 << '\n';
            else {cout << q.front() << '\n'; q.pop();}
        }
        if(s == "front") {
            if(q.empty()) cout << -1 << '\n';
            else {cout << q.front() << '\n';}
        }
        if(s == "back") {
            if(q.empty()) cout << -1 << '\n';
            else {cout << q.back() << '\n';}
        }
        if(s == "size") {
            cout << q.size() << '\n';
        }
        if(s == "empty") {
            cout << q.empty() << '\n';
        }   
    }
}