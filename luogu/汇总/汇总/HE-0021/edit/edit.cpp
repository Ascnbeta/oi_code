#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define file(x, y) freopen(#x".in", "r", stdin); freopen(#y".out", "w", stdout);
using namespace std;
const int N = 2e5 + 10;

int n;
string s, t, cs, ct;

int bels[N], belt[N], idx;
int cnt[N][2];
vector <int> e[N];

int main() {
    file(edit, edit);

    int T; cin >> T; while (T--) {
        memset(bels, 0, sizeof bels);
        memset(belt, 0, sizeof belt);
        rep(i, 1, idx)
            cnt[i][0] = cnt[i][1] = 0, e[i].clear();
        idx = 0;
        cin >> n >> s >> t >> cs >> ct;
        s = " " + s; t = " " + t;
        cs = " " + cs; ct = " " + ct;
        int ans = 0;
        rep(i, 1, n) {
            if (cs[i] == '1') {
                if (cs[i - 1] == '1') bels[i] = bels[i - 1];
                else bels[i] = ++idx;
            }
            if (bels[i]) ++cnt[bels[i]][s[i] - '0'];
            if (ct[i] == '1') {
                if (ct[i - 1] == '1') belt[i] = belt[i - 1];
                else belt[i] = ++idx;
            }
            if (belt[i]) ++cnt[belt[i]][t[i] - '0'];
            if (cs[i] == '0' && ct[i] == '0') ans += s[i] == t[i];
            if (cs[i] == '1' && ct[i] == '1') e[bels[i]].push_back(belt[i]);
        }
        rep(i, 1, n) {
            if (cs[i] == '1' && ct[i] == '0') {
                if (cnt[bels[i]][t[i] - '0']) {
                    --cnt[bels[i]][t[i] - '0'];
                    ++ans;
                }
            }
            if (cs[i] == '0' && ct[i] == '1') {
                if (cnt[belt[i]][s[i] - '0']) {
                    --cnt[belt[i]][s[i] - '0'];
                    ++ans;
                }
            }
        }
        rep(i, 1, idx) for (int y : e[i]) {
            if (cnt[i][0] && cnt[y][0]) {
                --cnt[i][0]; --cnt[y][0];
                ++ans;
            } else if (cnt[i][1] && cnt[y][1]) {
                --cnt[i][1]; --cnt[y][1];
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}