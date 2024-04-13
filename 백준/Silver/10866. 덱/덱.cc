#include <bits/stdc++.h>
using namespace std;

int N, num;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    deque<int> dq;
    while(N--) {
        cin >> s;
        
        if(s == "push_front") {
            cin >> num;
            dq.push_front(num);
        }
        if(s == "push_back") {
            cin >> num;
            dq.push_back(num);
        }
        if(s == "pop_front") {
            if(dq.empty()) cout << -1 << '\n';
            else {cout << dq.front() << '\n'; dq.pop_front();}
        }
        if(s == "pop_back") {
            if(dq.empty()) cout << -1 << '\n';
            else {cout << dq.back() << '\n'; dq.pop_back();}
        }
        if(s == "front") {
            if(dq.empty()) cout << -1 << '\n';
            else {cout << dq.front() << '\n';}
        }
        if(s == "back") {
            if(dq.empty()) cout << -1 << '\n';
            else {cout << dq.back() << '\n';}
        }
        if(s == "size") {
            cout << dq.size() << '\n';
        }
        if(s == "empty") {
            cout << dq.empty() << '\n';
        }   
    }
}