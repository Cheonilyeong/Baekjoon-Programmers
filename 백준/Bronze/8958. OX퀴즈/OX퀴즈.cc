#include <bits/stdc++.h>
using namespace std;

int N, pl = 1, score;
string s;
char pre;

int main(void) {
    
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> s;

        for(char c : s) {
            if(pre == 'O' && c == 'O') pl++;
            else pl = 1;

            if(c == 'O') score += pl;
            pre = c;
        }

        cout << score << '\n';
        score = 0;
        pl = 1;
        pre = ' ';
    }
}