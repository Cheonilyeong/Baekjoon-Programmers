#include <bits/stdc++.h>
using namespace std;

int N, a, mx=INT_MIN;
vector<int> v;

void go(int sum) {
    
    if(v.size() == 2) {
        mx = max(mx, sum);
        return;
    }

    for(int i = 1; i < v.size()-1; i++) {
        int temp = v[i];
        int pl = v[i-1] * v[i+1];
        v.erase(v.begin()+i, v.begin()+i+1);
        go(sum + pl);
        v.insert(v.begin()+i, temp);
    }
}

int main(void) {

    cin >> N; 

    for(int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    go(0);

    cout << mx;
}