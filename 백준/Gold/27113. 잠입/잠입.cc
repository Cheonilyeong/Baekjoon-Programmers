#include <bits/stdc++.h>
using namespace std;

int N, M, num, current=1;
int a, c;
char b, d;
bool flag = true;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N-1; i++) {
        cin >> num;

        if(num==2) {
            cin >> a >> b >> c >> d;
            if(b=='R' && d=='L') {
                if(current < a) {current = current;}
                else if(current >= a && current <= c) {current = c+1;}
                else if(current > c) {current = current;}
            }
            if(b=='L' && d=='R') {
                if(a + 1 == c) {current = M+1;}
                else if(current <= a) {current = a+1;}
                else if(current > a && current < c) {current = current;}
                else if(current >= c) {current = M+1;}
            }
            if(b=='L' && d=='L') {
                if(current <= c) {current = c+1;}
                else if(current > c) {current = current;}
            }
            if(b=='R' && d=='R') {
                if(current < a) {current = current;}
                else if(current >= a) {current = M+1;}
            }
        }
        else if(num==1) {
            cin >> a >> b;
            if(b=='R') {
                if(current < a) {current = current;}
                else if(current >= a) {current = M+1;}
            }
            if(b=='L') {
                if(current <= a) {current = a+1;}
                else if(current > a) {current = current;}
            }
        }
        //cout << current << '\n';
        if(current == M+1) flag = false;
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";

}