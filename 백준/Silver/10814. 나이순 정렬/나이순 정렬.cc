#include <bits/stdc++.h>
using namespace std;

int N, age;
string name;
vector<tuple<int,int,string>> v;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> age >> name;
        v.push_back({age,i,name});
    }

    sort(v.begin(), v.end());

    for(auto it : v) {
        age = get<0>(it); name = get<2>(it);
        cout << age << ' ' << name << '\n';
    }
}