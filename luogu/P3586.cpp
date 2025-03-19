#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6+20;
const int INF = 0x3f3f3f3f;
const double alpha = 0.29;
int n,m;
// WBLT
int rt,val[maxn],siz[maxn],ls[maxn],rs[maxn],tot;
int arr[maxn>>2];
long long sum[maxn];
inline int create(int v) {
    val[++tot] = v;
    siz[tot] = 1;
    if (v != INF && v != -INF) sum[tot] = v;
    return tot;
}
inline void pushup(int p) {
    val[p] = val[rs[p]];
    siz[p] = siz[ls[p]] + siz[rs[p]];
    sum[p] = sum[ls[p]] + sum[rs[p]];
}
inline long long getsum(int v,int k) {
    int p = rt;
    long long ret = 0;
    while(1) {
        if (siz[p] == 1) return ret + sum[p];
        if (val[ls[p]] >= v) ret += sum[rs[p]]-(long long)siz[rs[p]]*k,p = ls[p];
        else p = rs[p];
    }
}
#define ch(x,d) ((d)?(rs[x]):(ls[x]))
inline void rotate(int p,int d) {
    swap(ls[p],rs[p]);
    swap(ls[ch(p,d^1)],rs[ch(p,d^1)]);
    swap(ch(ch(p,d^1),d^1),ch(p,d));
    pushup(ch(p,d^1));pushup(p);
}
inline void maintain(int p) {
    int d;
    if (siz[p] == 1) return;
    if (siz[ls[p]] <= alpha*siz[p]) d = 1;
    else if (siz[rs[p]] <= alpha*siz[p]) d = 0;
    else return;
    if (siz[ch(ch(p,d),d^1)] * (1-alpha) >= siz[ch(p,d)] * (1-2*alpha)) rotate(ch(p,d),d^1);
    rotate(p,d);
}
inline void insert(int p,int v) {
    if (siz[p] == 1) {
        int x = create(v),y = create(val[p]);
        if (val[x] > val[y]) swap(x,y);
        ls[p] = x,rs[p] = y;
        pushup(p);
        return;
    }
    insert(v <= val[ls[p]] ? ls[p] : rs[p],v);
    pushup(p);
    maintain(p);
}
inline void remove(int &p,int v) {
    if (val[ls[p]] >= v) {
        if (siz[ls[p]] == 1) {
            p = rs[p];
        }else{
            remove(ls[p],v);
            pushup(p);
            maintain(p);
        }
    }else{
        if (siz[rs[p]] == 1) {
            p = ls[p];
        }else{
            remove(rs[p],v);
            pushup(p);
            maintain(p);
        }
    }
}
inline void print() {
    for (int i = 1; i <= tot; i++) {
        cout << i << ' ' << ls[i] << ' ' << rs[i] << ' ' << val[i] << ' ' << sum[i] << '\n';
    }
    cout << "Finished" << '\n';
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    rt = create(INF);
    insert(rt,-INF);
    for (int i = 1; i <= n; i++) insert(rt,0);
    while (m--) {
        // if (m <= 980) return 0;
        char opt;int x,y;
        cin >> opt >> x >> y;
        if (opt == 'U') {
            remove(rt,arr[x]);
            
            arr[x] = y;
            insert(rt,y);
            // print();
        }else{
            
            long long tmp = getsum(-1,0) - getsum(y+1,y);
            // cerr << getsum(-1,0) << ' ' << getsum(y+1,y) <<  ' ' << tmp << '\n';
            if (tmp >= (long long)x*y) {
                cout << "TAK" << '\n';
            }else{
                cout << "NIE" << '\n';
            }
        }
    }
    return 0;
}