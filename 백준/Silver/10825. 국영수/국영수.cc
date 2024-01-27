#include <bits/stdc++.h>

using namespace std;

typedef struct student{
    string name;
    int korean, english, math;

    bool operator<(const student& other) const {
        if(this->korean == other.korean) {
            if(this->english == other.english) {
                if(this->math == other.math) {
                    return this->name < other.name;
                }
                return this->math > other.math;
            }
            return this->english < other.english;
        }
        return this->korean > other.korean;
    }
}studnet;

int N;
student s;
vector<student> v;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    while(N--) {
        cin >> s.name >> s.korean >> s.english >> s.math;
        v.push_back(s);
    }
    sort(v.begin(), v.end());

    for(student s : v) {
        cout << s.name << '\n';
    }
}