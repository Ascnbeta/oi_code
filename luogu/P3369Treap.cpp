#include <bits/stdc++.h>
using namespace std;
mt19937 r(time(0));
const int maxn = 1e5+40;
int n,cnt;
struct node{
    int l,r;
    int val,dat;
    int size,cnt;
}t[maxn];
int tot,rt;
namespace treap{
    inline int create(int val) {
        t[++tot].val = val;
        t[tot].dat = r()%(1<<20);
        t[tot].cnt = t[tot].size = 1;
        return tot;
    }
    inline void update(int p) {
        t[p].size = t[t[p].l].size + t[t[p].r].size + t[p].cnt;
    }
    inline void build() {
        create(0xcfcfcfcf),create(0x3f3f3f3f);
        rt = 1;t[1].r = 2;
        update(rt);
    }
    
    inline int getrank(int p,int val) {
        if (p == 0) return 1;
        if (val == t[p].val) return t[t[p].l].size + 1;
        if (val < t[p].val) return getrank(t[p].l,val);
        return getrank(t[p].r,val) + t[t[p].l].size + t[p].cnt;
    }
    inline int getval(int p,int rnk) {
        if (p == 0) return 0x3f3f3f3f;
        if (t[t[p].l].size >= rnk) return getval(t[p].l,rnk);
        if (t[t[p].l].size + t[p].cnt >= rnk) return t[p].val;
        return getval(t[p].r,rnk-t[t[p].l].size-t[p].cnt);
    }
    inline void zig(int &p) {
        int q = t[p].l;
        t[p].l = t[q].r,t[q].r = p;
        p = q;
        update(t[p].r);
        update(p);
    }
    inline void zag(int &p) {
        int q = t[p].r;
        t[p].r = t[q].l,t[q].l = p;
        p = q;
        update(t[p].l);
        update(p);
    }

    inline void insert(int &p,int val) {
        if (p == 0) {
            p = create(val);
            return;
        }
        if (val == t[p].val) {
            ++t[p].cnt;
            update(p);
            return;
        }
        if (val < t[p].val) {
            insert(t[p].l,val);
            if (t[p].dat < t[t[p].l].dat) zig(p);
        }
        else{
            insert(t[p].r,val);
            if (t[p].dat < t[t[p].r].dat) zag(p);
        }
        update(p);
    }
    inline int getpre(int val) {
        int ans = 1;
        int p = rt;
        while (p) {
            if (val == t[p].val) {
                if (t[p].l > 0) {
                    p = t[p].l;
                    while (t[p].r > 0) p = t[p].r;
                    ans = p;
                }
                break;
            }
            if (val > t[p].val && t[ans].val < t[p].val) ans = p;
            p = val < t[p].val ? t[p].l : t[p].r;
        }
        return t[ans].val;
    }
    inline int getnext(int val) {
        int ans = 2;
        int p = rt;
        while (p) {
            if (val == t[p].val) {
                if (t[p].r > 0) {
                    p = t[p].r;
                    while (t[p].l > 0) p = t[p].l;
                    ans = p;
                }
                break;
            }
            if (val < t[p].val && t[ans].val > t[p].val) ans = p;
            p = val < t[p].val ? t[p].l : t[p].r;
        }
        return t[ans].val;
    }
    inline void remove(int &p,int val) {
        if (p == 0) return;
        if (val == t[p].val) {
            if (t[p].cnt > 1) {
                t[p].cnt--;
                update(p);
                return;
            }
            if (t[p].l || t[p].r) {
                if (t[p].r == 0 || t[t[p].l].dat > t[t[p].r].dat) 
                    zig(p),remove(t[p].r,val);
                else
                    zag(p),remove(t[p].l,val);
                update(p);
            }else p = 0;
            return;
        }
        val < t[p].val ? remove(t[p].l, val) : remove(t[p].r, val);
        update(p);
    }
    
    
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    treap::build();
    
    while (n--) {
        int opt,x;
        cin >> opt >> x;
        if (opt == 1) {
            treap::insert(rt,x);
            ++cnt;
        }else if (opt == 2) {
            treap::remove(rt,x);
            --cnt;
        }else if (opt == 3) {
            cout << treap::getrank(rt,x)-1<< '\n';
        }else if (opt == 4) {
            assert(x<=cnt);
            cout << treap::getval(rt,x+1) << '\n';
        }else if (opt == 5) {
            cout << treap::getpre(x) << '\n';
        }else{
            cout << treap::getnext(x) << '\n';
        }
    }
    // cout << t[3].val << ' ' << t[3].l << ' ' << t[3].r << '\n';
    return 0;
}