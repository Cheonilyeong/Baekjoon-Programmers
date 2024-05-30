#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int,int>> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first;
    }
    for(int i = 0; i < N; i++) {
        cin >> v[i].second;
    }
    
    // 연습으로 람다 써봤어요
    sort(v.begin(), v.end(), [](auto & a, auto & b) {
        if(a != b) return a.second < b.second;
        else return a.first < b.first;
    });

    long long sum = 0;
    for(int i = 0; i < N; i++) {
        sum += v[i].first + v[i].second * i;
    }

    cout << sum;
}