#include <bits/stdc++.h>

using namespace std;

int N, strong, mx=INT_MIN;
vector<int> v[10004];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i<N; i++) {
        cin >> strong;
        v[strong].push_back(i);
        mx = max(mx, strong);
    }

    if(v[mx].size() == 1) cout << (N/2 > v[mx][0] ? "R" : "B");
    else if(v[mx].size() > 1) {
        int leftMx = v[mx][0];
        int rightMx = v[mx].back();

        if(leftMx < N-1 - rightMx) cout << "R";
        else if(leftMx == N-1 - rightMx) cout << "X";
        else if(leftMx > N-1 -rightMx) cout << "B";
    }

}