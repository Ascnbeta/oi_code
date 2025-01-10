#include<bits/stdc++.h>
using namespace std;

int T;
int n;

bool s1[100005], s2[100005];
int s11[100005], s10[100005];
int s21[100005], s20[100005];

bool t1[100005], t2[100005];

int sum11(int l, int r) {
    return s11[r] - s11[l - 1];
}

int sum10(int l, int r) {
    return s10[r] - s10[l - 1];
}

int sum21(int l, int r) {
    return s21[r] - s21[l - 1];
}

int sum20(int l, int r) {
    return s20[r] - s20[l - 1];
}

int main() {

    freopen("edit.in", "r", stdin);
    freopen("edit.out", "w", stdout);

    cin >> T;

    while(T--) {
        cin >> n;
        int ans = n;

        for(int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            s1[i] = c - '0';

            if(s1[i]) {
                s11[i] = s11[i - 1] + 1;
                s10[i] = s10[i -  1];
            } else {
                s11[i] = s11[i - 1];
                s10[i] = s10[i - 1] + 1;
            }
        }

        for(int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            s2[i] = c - '0';

            if(s2[i]) {
                s21[i] = s21[i - 1] + 1;
                s20[i] = s20[i -  1];
            } else {
                s21[i] = s21[i - 1];
                s20[i] = s20[i - 1] + 1;
            }
        }

        for(int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            t1[i] = c - '0';
        }

        for(int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            t2[i] = c - '0';
        }

        bool flag = true;

        for(int i = 2; i <= n; i++) {
            if(s1[i] != s1[i-1]) {
                flag = false;
            }
        }
        if(flag) {
            if(s1[1]==1) {
                cout << sum21(1, n) << endl;
            } else {
                cout << sum20(1, n) << endl;
            }

            continue;
        }

        flag = true;

        for(int i = 1; i <= n; i++) {
            if(t1[i] != t2[i]) {
                flag = false;
            }
        }
        if(flag) {
            bool f = false;
            int l;

            for(int i = 1; i <= n; i++) {
                if(t1[i]) {
                    if(!f) {
                        f = true;
                        l = i;
                    }
                } else {
                    if(f) {
                        f = false;
                        ans -= abs(sum11(l, i - 1) - sum21(l, i - 1));
                    }
                    ans -= (s1[i] != s2[i]);
                }
            }

            if(f) {
                ans -= abs(sum11(l, n) - sum21(l, n));
            }

            cout << ans << endl;

            continue;
        }

        for(int i = 1; i <= n; i++) {
            if(s1[i]!=s2[i]) {
                ans--;
            }
        }
        cout << ans << endl;
    }


    return 0;
}

/*
* Don't Look Back in Anger
*
* 2024 AFO
*
* Good by OI
*/
