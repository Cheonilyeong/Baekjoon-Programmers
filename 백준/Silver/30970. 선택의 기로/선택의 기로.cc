#include <bits/stdc++.h>
using namespace std;

int N, a, b;
vector<pair<int,int>> v1;
vector<pair<int,int>> v2;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        v1.push_back({a,(-1*b)});
        v2.push_back({b,(-1*a)});
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    cout << v1[v1.size()-1].first << ' ' << v1[v1.size()-1].second*-1 << ' ' << v1[v1.size()-2].first << ' ' << v1[v1.size()-2].second*-1<< '\n';
    cout << v2[0].second*-1 << ' ' << v2[0].first << ' ' << v2[1].second*-1 << ' ' << v2[1].first << '\n';
}