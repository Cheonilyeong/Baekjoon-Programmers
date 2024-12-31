#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
set<vector<int>> results;

int main() {
    cin >> N >> M;

    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    do {
        vector<int> combination;
        for (int i = 0; i < M; i++) {
            combination.push_back(v[i]);
        }
        results.insert(combination);
    } while (next_permutation(v.begin(), v.end()));

    for (const auto& combination : results) {
        for (int num : combination) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}
