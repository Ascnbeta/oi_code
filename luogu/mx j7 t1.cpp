#include <bits/stdc++.h>
using namespace std;
int n,m;
bool ac[104];
struct subtask{
    int cnt,c[104];
}s[104];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].cnt;
        for (int j = 1; j <= s[i].cnt; j++) {
            cin >> s[i].c[j];
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            ac[j] = false;
        }
        for (int j = 1; j <= n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                ac[j] = true;
            }else{
                ac[j] = false;
            }
        }
        int score = 0;
        for (int j = 1; j <= n; j++) {
            bool f = ac[j];
            if (!f) continue;
            for (int k = 1; k <= s[j].cnt; k++) {
                if (!ac[s[j].c[k]]) {
                    f = false;
                    ac[j] = false;
                    break;
                }
            }
            if (!f) continue;
            ++score;
        }
        cout << score << endl;
    }
    return 0;
}