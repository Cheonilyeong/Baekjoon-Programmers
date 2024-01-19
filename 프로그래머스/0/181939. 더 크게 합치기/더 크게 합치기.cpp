#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b) {
    string c, d;
    c = to_string(a) + to_string(b);
    d = to_string(b) + to_string(a);
    return (stoi(c) >= stoi(d)) ? stoi(c) : stoi(d);
}