#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b) {
    int c = stoi(to_string(a) + to_string(b));
    return (c >= 2*a*b) ? c : 2*a*b;
}