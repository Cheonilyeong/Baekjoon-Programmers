#include <bits/stdc++.h>
using namespace std;

int N;

bool check(int n) {
    if(n <= 1) return 0;
	if(n == 2) return 1;
	if(n % 2 == 0) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

void go(string s) {

    if(s.size() == N) {
        cout << s << '\n';
        return;
    }

    for(int i = 1; i <= 9; i++) {
        string t = s + to_string(i);
        if(check(atoi(t.c_str()))) go(t);
    }
}
int main(void) {
    
    cin >> N;

    go("2");
    go("3");
    go("5");
    go("7");
}