#include <bits/stdc++.h>
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int maxn = 5.5e4+10;
const int maxwblt = 3.7e6+10;
const double alpha = 0.29;
int n,m;
//WBLT
int val[maxwblt],siz[maxwblt],ls[maxwblt],rs[maxwblt],tot;
//Segtree
int num[maxn<<2],rt[maxn<<2];
inline int create(int v) {
    val[++tot] = v;
    siz[tot] = 1;
    return tot;
}
inline void pushupwblt(int p) {
    siz[p] = siz[ls[p]] + siz[rs[p]];
    val[p] = val[rs[p]];
}
#define ch(x,d) ((d)?(rs[x]):(ls[x]))
inline void rotate(int p,int d) {
    swap(ls[p],rs[p]);
    swap(ls[ch(p,d^1)],rs[ch(p,d^1)]);
    swap(ch(ch(p,d^1),d^1),ch(p,d));
    pushupwblt(ch(p,d^1));
    pushupwblt(p);
}
inline void maintain(int p) {
    int d;
    if (siz[p] == 1) return;
    if (siz[ls[p]] < alpha*siz[p]) d = 1;
    else if(siz[rs[p]] < alpha*siz[p]) d = 0;
    else return;
    if (siz[ch(ch(p,d),d^1)] * (1-alpha) >= siz[ch(p,d)] * (1-2*alpha)) rotate(ch(p,d),d^1);
    rotate(p,d);
}
inline void insert(int p,int v) {
    if (siz[p] == 1) {
        int x = create(v),y = create(val[p]);
        if (val[x] > val[y]) swap(x,y);
        ls[p] = x,rs[p] = y;
        pushupwblt(p);
        return;
    }
    insert(v <= val[ls[p]] ? ls[p] : rs[p],v);
    pushupwblt(p);
    maintain(p);
}
inline void remove(int &p,int v) {
    if (val[ls[p]] >= v) {
        if (siz[ls[p]] == 1) p = rs[p];
        else remove(ls[p],v),pushupwblt(p),maintain(p);
    }else{
        if (siz[rs[p]] == 1) p = ls[p];
        else remove(rs[p],v),pushupwblt(p),maintain(p);
    }
}
inline int getval(int root,int rnk) {
    int p = root;
    while (1) {
        if (siz[p] == 1) {
            assert(rnk==1);
            return val[p];
        }
        if (siz[ls[p]] >= rnk) p = ls[p];
        else rnk -= siz[ls[p]],p = rs[p];
    }
}
inline int getrank(int root,int v) {
    int p = root,cnt = 0;
    while (1) {
        if (siz[p] == 1) return cnt+1;
        if (val[ls[p]] >= v) p = ls[p];
        else cnt += siz[ls[p]],p = rs[p];
    }
}
inline int getpre(int root,int v) {
    return getval(root,getrank(root,v)-1);
}
inline int getnext(int root,int v) {
    return getval(root,getrank(root,v+1));
}
inline void build(int p,int l,int r) {
    if (l == r) {
        rt[p] = create(INT_MAX);
        insert(rt[p],INT_MIN+1);
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    rt[p] = create(INT_MAX);
    insert(rt[p],INT_MIN+1);
}
inline void initinsert(int p,int pos,int v,int l,int r) {
    if (l == r) {
        num[p] = v;
        insert(rt[p],v);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) initinsert(lc,pos,v,l,mid);
    else initinsert(rc,pos,v,mid+1,r);
    insert(rt[p],v);
}
inline int queryrank(int p,int v,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return getrank(rt[p],v)-2;
    }
    int mid = (l + r) >> 1;
    int sum = 0;
    if (s <= mid) sum += queryrank(lc,v,s,e,l,mid);
    if (e > mid) sum += queryrank(rc,v,s,e,mid+1,r);
    return sum;
}
inline int modify(int p,int pos,int v,int l,int r) {
    if (l == r) {
        int ret = getval(rt[p],2);
        remove(rt[p],ret);
        insert(rt[p],v);
        return ret;
    }
    int mid = (l + r) >> 1;
    int x;
    if (pos <= mid) x = modify(lc,pos,v,l,mid);
    else x = modify(rc,pos,v,mid+1,r);
    remove(rt[p],x);
    insert(rt[p],v);
    return x;
}
inline int querypre(int p,int v,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return getpre(rt[p],v);
    }
    int mid = (l + r) >> 1;
    int ret = INT_MIN+1;
    if (s <= mid) ret = max(ret,querypre(lc,v,s,e,l,mid));
    if (e > mid) ret = max(ret,querypre(rc,v,s,e,mid+1,r));
    return ret;
}
inline int querynext(int p,int v,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return getnext(rt[p],v);
    }
    int mid = (l + r) >> 1;
    int ret = INT_MAX;
    if (s <= mid) ret = min(ret,querynext(lc,v,s,e,l,mid));
    if (e > mid) ret = min(ret,querynext(rc,v,s,e,mid+1,r));
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    build(1,1,n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        initinsert(1,i,x,1,n);
    }
    // for (int i = 1; i <= tot; i++) {
    //     cout << i << ' ' << val[i] << ' ' << siz[i] << ' ' << ls[i] << ' ' << rs[i] << '\n';
    // }
    while (m--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l,r,k;
            cin >> l >> r >> k;
            cout << queryrank(1,k,l,r,1,n)+1 << '\n';
        }else if(opt == 3) {
            int pos,k;
            cin >> pos >> k;
            modify(1,pos,k,1,n);
        }else if(opt == 4) {
            int l,r,k;
            cin >> l >> r >> k;
            cout << querypre(1,k,l,r,1,n) << '\n';
        }else if(opt == 5) {
            int l,r,k;
            cin >> l >> r >> k;
            cout << querynext(1,k,l,r,1,n) << '\n';
        }else if(opt == 2) {
            int L,R,k;
            cin >> L >> R >> k;
            int l = 0,r = 1e8,ans = 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int tmp = queryrank(1,mid,L,R,1,n);
                if (tmp+1 <= k)  {
                    l = mid + 1,ans = mid;
                }
                else r = mid - 1;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}