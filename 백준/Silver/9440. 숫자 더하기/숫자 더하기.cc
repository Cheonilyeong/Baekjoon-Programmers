#include <bits/stdc++.h>
using namespace std;

int N, zero;
vector<int> v;
string a, b;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(cin >> N) {

        if(N == 0) break;

        v.resize(N);
        for(int i = 0; i < N; i++) {
            cin >> v[i];
            if(v[i] == 0) zero++;
        }

        sort(v.begin(), v.end());
        if (zero == 1) { swap(v[0], v[2]);}
        else if (zero > 1) {
            swap(v[0], v[zero]);
            swap(v[1], v[zero + 1]);
        }

        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) { a += to_string(v[i]); }
            else { b += to_string(v[i]); }
        }

        cout << atoi(a.c_str()) + atoi(b.c_str()) << '\n';

        a = b = "";
        v.clear();
        zero = 0;
    }
}