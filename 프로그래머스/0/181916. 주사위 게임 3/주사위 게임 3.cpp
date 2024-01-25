#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;

int solution(int a, int b, int c, int d) {
    mp[a]++;
    mp[b]++;
    mp[c]++;
    mp[d]++;
    
    if(mp.size() == 1) {
        return 1111 * a;
    }
    else if(mp.size() == 2) {
        int p= 0, q, c = 1;
        for(auto it : mp) {
            if(it.second == 3) p = it.first;
            else if(it.second == 2) {
                if(p == 0) p = it.first;
                else q = it.first;
                c = 0;
            }
            else if(it.second == 1) q = it.first;
        }
        if(c) return pow((10 * p + q), 2);
        else return (p + q) * abs(p - q);
    }
    else if(mp.size() == 3) {
        int p, q = 0, r;
        for(auto it : mp) {
            if(it.second == 2) p = it.first;
            else if(it.second == 1) {
                if(q == 0) q = it.first;
                else r = it.first;
            }
        }
        return q * r;
    }
    else if(mp.size() == 4) {
        int mn = INT_MAX;
        mn = min(mn, a);
        mn = min(mn, b);
        mn = min(mn, c);
        mn = min(mn, d);
        return mn;
    }
}