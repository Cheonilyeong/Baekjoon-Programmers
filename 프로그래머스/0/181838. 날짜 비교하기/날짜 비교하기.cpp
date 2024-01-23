#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> date1, vector<int> date2) {
    if(date1[0] == date2[0]) {
        if(date1[1] == date2[1]) {
            return date1[2] < date2[2];
        }
        else return date1[1] < date2[1];
    }
    else return date1[0] < date2[0];
}