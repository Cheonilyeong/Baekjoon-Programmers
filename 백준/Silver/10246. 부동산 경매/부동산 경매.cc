#include <bits/stdc++.h>
using namespace std;

long long N, psum[1000004], cnt[1000004];

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i = 1; i <= 1000000; i++) {
        psum[i] = psum[i-1] + i+1;
        if (psum[i] - psum[i-1] > 1000000) break;
    }

    for (int i = 1; i <= 1000000; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (psum[i] - psum[j] > 1000000) break;
			cnt[psum[i] - psum[j]]++;
        }
	}

    while(cin >> N) {
        if(N == 0) break;
        
        cout << cnt[N] << '\n';
    }
}