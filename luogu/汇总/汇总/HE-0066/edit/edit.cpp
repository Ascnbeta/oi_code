#include<bits/stdc++.h>
//#include<bits/extc++.h>
namespace {
using namespace std;
//using namespace __gnu_pbds;
#define fiin(x) freopen(x".in", "r", stdin)
#define fiout(x) freopen(x".out", "w", stdout)
#define file(x) fiin(x), fiout(x)
#define ll long long
#define db double
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
#define fir first
#define sec second
#define hap cc_hash_table
// #define 
const int man = 1e5+10, mam = 1e5+10, mop = 1e9+7;
}

int T, n, lna, lnb;
int a[man], b[man], fa[man], fb[man],
    sa[man], sb[man], nxt[man], 
    ua[man], ub[man], ua0[man], ub0[man], 
    nxa[man], nxb[man];
int main () {
    file("edit");
    scanf("%d", &T);
    while (T --) {
        int res = 0, len = 0;
int fA = 1, fB = 1, fC = 1;
        scanf("%d", &n);
lna = lnb = 0;
        memset(sa, 0, sizeof(sa));
        memset(sb, 0, sizeof(sb));
        memset(ua, 0, sizeof(ua));
        memset(ub, 0, sizeof(ub));
        memset(ua0, 0, sizeof(ua0));
        memset(ub0, 0, sizeof(ub0));
        for (int i = 1; i <= n; ++ i) {
            scanf("%1d", a+i), sa[i] = sa[i-1]+a[i];
            if (a[i]!=a[i-1]) fA = 0;
            }
        for (int i = 1; i <= n; ++ i) scanf("%1d", b+i), sb[i] = sb[i-1]+b[i];
        for (int i = 1; i <= n; ++ i) {
            scanf("%1d", fa+i);
            if (!fa[i]) {
if (lna) fC = 0;
                nxa[lna] = i, lna = i;
                }
        } for (int i = 1; i <= n; ++ i) {
            scanf("%1d", fb+i);
            if (!fb[i]) {
if (lnb) fC = 0;
                nxb[lnb] = i, lnb = i;
                }
if (fb[i]!=fa[i]) fB = 0;
        } for (int l = 1, i = 1; i <= n; ++ i) 
            if (!fa[i] || !fb[i]) nxt[len] = i, len = i;
        nxt[len] = nxb[lnb] = nxa[lna] = n+1;
        if (fA) res = a[1]?sb[n]:n-sb[n];
        else if (fB) res = min(sa[n], sb[n])+min(n-sa[n], n-sb[n]);
        else if (!len || !lna || !lnb) res = min(sa[n], sb[n])+min(n-sa[n], n-sb[n]);
else {
	int xa = 0, xb = 0;
			for (int ls = 0, i = 1; i <= n; ls = i, i = nxt[i]) {
            if (!fa[i] && !fb[i]) {
                int lt = i-ls-1, la = sa[i-1]-ua[i]-sa[ls], lb = sb[i-1]-ub[i]-sb[ls];
                int u1 = min(la, lb);
                la = i-1-sa[i-1]-ua0[i]-ls+sa[ls], 
                lb = i-1-sb[i-1]-ub0[i]-ls+sb[ls];
                int u0 = min(la, lb);
                res += u1+u0+(a[i]==b[i]), xa = xb = i;
            } else if (!fa[i]) {
                int lt = i-ls, la = sa[i]-ua[i]-sa[ls], lb = sb[nxb[xb]-1]-ub[nxb[xb]]-sb[xb];
                int u1 = min(la, lb);
                la = i-sa[i]-ua0[i]-ls+sa[ls], 
                lb = nxb[xb]-1-sb[nxb[xb]-1]-ub0[nxb[xb]]-xb+sb[xb];
                int u0 = min(la, lb);
                ub[nxb[xb]] = u1;
                res += u1+u0;
                xa = i;
            } else {
                int lt = i-ls, la = sa[nxa[xa]-1]-ua[nxa[xa]]-sa[xa], lb = sb[i]-ub[i]-sb[ls];
                int u1 = min(la, lb);
                la = nxa[xa]-1-sa[nxa[xa]-1]-ua0[nxa[xa]]-xa+sa[xa], 
                lb = i-sb[i]-ub0[i]-ls+sb[ls];
                int u0 = min(la, lb);
                ua[nxa[xa]] = u1;
                res += u1+u0;
                xb = i;
            }}
}
        printf("%d\n", res);
    } return 0;
}


/*
code: UTF-8
code: UTF-8
code: UTF-8

1
6
000000
101101
101101
111101

真无敌，现在是 10:21，刚刚调完 T1，要没救了。

考场这个 VScode 还不太好使，打回车总吃我缩进。

先对拍去了。

哈哈，对个屁，大样例都没过。

卧槽 11 点了要不重构吧


我草拟玛

Luogu：347089 STA_Morlin
qwq

I Love WOT

0x66ccff

            if (!fa[i] && !fb[i]) {
                int lt = i-ls-1, la = sa[i-1]-ua[i]-sa[ls], lb = sb[i-1]-ub[i]-sb[ls];
                int u1 = min(la, lb);
                la = i-1-sa[i-1]-ua0[i]-ls+sa[ls], 
                lb = i-1-sb[i-1]-ub0[i]-ls+sb[ls];
                int u0 = min(la, lb);
                res += u1+u0+(a[i]==b[i]), xa = xb = i;
                printf("U:   ");
            } else if (!fa[i]) {
                int lt = i-ls, la = sa[i]-ua[i]-sa[ls], lb = sb[nxb[xb]-1]-ub[nxb[xb]]-sb[xb];
                int u1 = min(la, lb);
                la = i-sa[i]-ua0[i]-ls+sa[ls], 
                lb = nxb[xb]-1-sb[nxb[xb]-1]-ub0[nxb[xb]]-xb+sb[xb];
                int u0 = min(la, lb);
                ub[nxb[xb]] = u1;
                res += u1+u0;
                xa = i;
                printf("A:%d  ", u0);
            } else {
                int lt = i-ls, la = sa[nxa[xa]-1]-ua[nxa[xa]]-sa[xa], lb = sb[i]-ub[i]-sb[ls];
                int u1 = min(la, lb);
                la = nxa[xa]-1-sa[nxa[xa]-1]-ua0[nxa[xa]]-xa+sa[xa], 
                lb = i-sb[i]-ub0[i]-ls+sb[ls];
                int u0 = min(la, lb);
                ua[nxa[xa]] = u1;
                res += u1+u0;
                xb = i;
                printf("B:%d  ", ub[i]);
            }
            printf("%d %d %d %d\n", i, nxa[xa], nxb[xb], res);




            if (!fa[i] && !fb[i]) {
                return 0;
            } else if (!fa[i]) {
                int A = nxa[xa], B = nxb[xb];
                int an0 = i-sa[i]-ls+sa[ls]-ua0[i], an1 = sa[i]-sa[ls]-ua[i];
                int bg0 = B-sb[B]-ls+sb[xa]-ub0[B], bg1 = sb[B]-sb[xb]-ub[B];
                b[B]?--bg1:--bg0;
                if (bg0 >= an0) {
                    ub0[B] += an0, res += an0;
                } else ub0[B] += bg0, res += bg0;
                ub[B] += min(an1, bg1), res += min(an1, bg1);
                xa = i;
                printf("A:%d %d  ", sb[xb], ub[B]);
            } else {
                int A = nxa[xa], B = nxb[xb];
                int bn0 = i-sb[i]-ls+sb[ls]-ub0[i], bn1 = sb[i]-sb[ls]-ub[i];
                int ag0 = A-sa[A]-ls+sa[xa]-ua0[A], ag1 = sa[A]-sa[xa]-ua[A];
                a[A]?--ag1:--ag0;
                ua0[A] += min(bn0, ag0), res += min(bn0, ag0); 
                ua[A] += min(bn1, ag1), res += min(bn1, ag1);
                xb = i;
                printf("B:%d %d  ", min(bn0, ag0), min(bn1, ag1));
            } printf("%d %d %d %d\n", i, nxa[xa], nxb[xb], res);
*/
