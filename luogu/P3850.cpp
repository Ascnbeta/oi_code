#include <bits/stdc++.h>
using namespace std;
const int maxn = 203;
const int maxm = 1e5+30;
const double alpha = 0.29;
int n,m,q;
double val[(maxn+maxm)<<1];
string nm[(maxn+maxm)<<1];
int ls[(maxn+maxm)<<1],rs[(maxn+maxm)<<1],siz[(maxn+maxm)<<1],tot,rt,cnt;
inline int create(string str) {
    nm[++tot] = str;
    siz[tot] = 1;
    return tot;
}
inline void pushup(int p) {
    siz[p] = siz[ls[p]] + siz[rs[p]];
}
#define ch(x,d) ((d)?(rs[x]):(ls[x]))
inline void rotate(int p,int d) {
    swap(ls[p],rs[p]);
    swap(ls[ch(p,d^1)],rs[ch(p,d^1)]);
    swap(ch(ch(p,d^1),d^1),ch(p,d));
    pushup(ch(p,d^1));
    pushup(p);
}
inline void maintain(int p) {
    int d;
    if (siz[p] == 1) return;
    if (siz[ls[p]] < alpha*siz[p]) d = 1;
    else if (siz[rs[p]] < alpha*siz[p]) d = 0;
    else return;
    if (siz[ch(ch(p,d),d^1)] * (1 - alpha) >= siz[ch(p,d)] * (1 - 2 * alpha)) {
        rotate(ch(p,d),d^1);
    }
    rotate(p,d);
}
inline void insert(int p,string str,int pos) {
    if (siz[p] == 1) {
        if (pos != 1) {
            int x = create(str),y = create(nm[p]);
            ls[p] = y,rs[p] = x;
        }else{
            int x = create(str),y = create(nm[p]);
            ls[p] = x,rs[p] = y;
        }
        pushup(p);
        return;
    }
    if (pos <= siz[ls[p]]) insert(ls[p],str,pos);
    else insert(rs[p],str,pos-siz[ls[p]]);
    pushup(p);
    maintain(p);
}
inline string getname(int rnk) {
    int p = rt;
    while (1) {
        if (siz[p] == 1) {
            assert(rnk == 1);
            return nm[p];
        }
        if (siz[ls[p]] >= rnk) p = ls[p];
        else rnk -= siz[ls[p]],p = rs[p];
    }
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    rt = create("QAQ");
    // cerr << rt << '\n';
    insert(rt,"awa",1);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insert(rt,s,i+1);
        // for (int i = 1; i <= tot; i++) {
        //     cerr << i << ' ' << ls[i] << ' ' << rs[i] << ' ' << nm[i] << ' ' << siz[i] << '\n';
        // }
        ++cnt;
        // cerr << s << "\n";
    }
    cin >> m;
    while (m--) {
        string s;int opt;
        cin >> s >> opt;
        insert(rt,s,opt+2);
        // for (int i = 1; i <= tot; i++) {
        //     cerr << i << ' ' << ls[i] << ' ' << rs[i] << ' ' << nm[i] << ' ' << siz[i] << '\n';
        // }
        ++cnt;
        // cerr << s << opt+1 << "\n";
    }
    cin >> q;
    while (q--) {
        int opt;
        cin >> opt;
        // cerr << opt << "\n";
        cout << getname(opt+2) << '\n';
    }
    return 0;
}