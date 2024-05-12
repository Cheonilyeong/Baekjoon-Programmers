#include <bits/stdc++.h>
using namespace std;

int N, K, num;
long long sum;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < N; i++) {
        cin >> num;
        if(num >= 0) v1.push_back(num);
        else v2.push_back(num);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end());

    for(int i = 0; i < v1.size(); i+=K) {
        sum += v1[i]*2;
    }
    for(int i = 0; i < v2.size(); i+=K) {
        sum += v2[i]*2*-1;
    }

    cout << sum;
}