#include <bits/stdc++.h>
using namespace std;
int n;
string s;
queue<int> d,r;
int main () {
    cin >> n >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'D' ) {
            d.push(i);
        }else{
            r.push(i);
        }
    }
    while (!d.empty() && !r.empty()) {
        if (d.front() < r.front()) {
            r.pop();
            d.push(d.front()+n);
            d.pop();
        }else{
            d.pop();
            r.push(r.front()+n);
            r.pop();
        }
    }
    cout << (r.empty() ? 'D' : 'R') << '\n';
    return 0;
}