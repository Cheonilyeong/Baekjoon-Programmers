#include <bits/stdc++.h>
using namespace std;

int R, G, N=1;

// 최대공약수 (0 <= a <= b)
int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}

// 약수
vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int main(void) {

    cin >> R >> G;

    // 경우의 수 구하기
    int g = gcd(min(R, G), max(R, G));
    vector<int> d = findDivisors(g);

    for(int i : d) {
        cout << i << ' ' << R/i << ' ' << G/i << '\n';
    }
}