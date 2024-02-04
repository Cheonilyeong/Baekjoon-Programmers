#include <bits/stdc++.h>
using namespace std;

int N, ret;
string s, storeName;

int main(void) {
    
    cin >> N;
    cin >> storeName;

    while(N--) {
        cin >> s;

        // 브루트포스
        for(int jump = 1; 2*jump <= s.size(); jump++) {
            bool flag = false;
            int pos;
            
            for(int i = 0; i < s.size(); i++) {
                string temp = "";
                for(int j = i; j < s.size(); j+=jump) {
                    temp += s[j]; 
                }

                if((pos = temp.find(storeName)) != string::npos) {
                    ret++;
                    flag = true;
                    break;
                }
            }

            if(flag) break;
        }
    }

    cout << ret;
}