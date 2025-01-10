#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
int n,a[100005];
stack<int> s;
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (s.empty()) {
            cout << -1 << ' ';
            s.push(a[i]);
            continue;
        }
        if (s.top() < a[i]) {
            cout << s.top() <<' ';
            s.push(a[i]);
            continue;
        }else{
            while (!s.empty() && s.top() >= a[i]) {
                s.pop();
            }
            if(s.empty()) {
                cout << -1 <<' ';
                s.push(a[i]);
            }else{
                cout << s.top() << ' ';
                s.push(a[i]);
            }
        }
    }
    return 0;
}