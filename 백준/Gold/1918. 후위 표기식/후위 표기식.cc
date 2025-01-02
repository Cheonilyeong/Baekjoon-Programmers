#include <bits/stdc++.h>
using namespace std;

string str;
stack<char> s;

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> str;

    for (char c : str) {
        if (c >= 'A' && c <= 'Z') { 
            cout << c;
        } else if (c == '(') { 
            s.push(c);
        } else if (c == ')') { 
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        } else { 
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
