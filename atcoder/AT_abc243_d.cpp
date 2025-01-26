#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,x;
deque<char> s;
signed main () {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        char ch;
        cin >> ch;
        if (ch == 'U') {
            if (!s.empty() && (s.back() == 'L' || s.back() == 'R')) {
                s.pop_back();
            }else{
                s.push_back(ch);
            }
        }else{
            s.push_back(ch);
        }
    
    }
    while(!s.empty()) {
        if (s.front() == 'U') {
            x /= 2;
        }
        if (s.front() == 'L') {
            x *= 2;
        }
        if (s.front() == 'R') {
            x *= 2;
            ++x;
        }
        s.pop_front();
    }
    cout << x;
    return 0;
}