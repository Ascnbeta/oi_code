#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 40;
const double alpha = 0.29;
int n,m,ans,lst;
struct node {
    int l, r;
    int val, cnt;
    int size;
} tr[maxn << 1];
int tot, rt = 1;
inline int create(int val) {
    tr[++tot].val = val;
    tr[tot].size = 1;
    return tot;
}
inline int getval(int rnk) {
    int now = rt;

    while (1) {
        if (tr[now].size == 1)
            return rnk == 1 ? tr[now].val : -1;
        else if (tr[tr[now].l].size >= rnk)
            now = tr[now].l;
        else
            rnk -= tr[tr[now].l].size, now = tr[now].r;
    }
}
inline int getrank(int val) {
    int now = rt, cnt = 0;

    while (1) {
        if (tr[now].size == 1)
            return cnt + 1;
        else if (tr[tr[now].l].val >= val)
            now = tr[now].l;
        else
            cnt += tr[tr[now].l].size, now = tr[now].r;
    }
}
inline int getpre(int val) {
    return getval(getrank(val) - 1);
}
inline int getnext(int val) {
    return getval(getrank(val + 1));
}
inline void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size;
    tr[p].val = tr[tr[p].r].val;
}
#define ch(x,d) ((d)?(tr[x].r):(tr[x].l))
inline void rotate(int p, bool d) {//d=1表示将右儿子旋转到自己，d=0则是左儿子，设左儿子左右子树为a,b，右儿子左右子树为c,d，则此时顺序为a,b,c,d
    swap(tr[p].l, tr[p].r); //先交换左右子树，此时变为c,d,a,b
    swap(tr[ch(p, d^1)].l, tr[ch(p,d^1)].r); //对于d=1，把左儿子的两棵子树交换，此时变为d,c,a,b，对于d=0，则把右儿子的两棵子树交换，此时变为c,d,b,a
    swap(ch(ch(p, d^1), d^1), ch(p,d)); //对于d=1，把左儿子的左子树和自己的右子树直接交换，此时变为a,b,c,d，对于d=0，把右儿子的右子树和自己的左子树直接交换，此时变为a,b,c,d
    pushup(ch(p, d^1)); //注意此时只有相反的节点权值有变，要旋转的那个点没有变（因为存储的是最大值）
    pushup(p);//更新自己
}
inline void maintain(int p) {
    int d;

    if (tr[p].size == 1)
        return;

    if (tr[tr[p].l].size < alpha * tr[p].size)
        d = 1;
    else if (tr[tr[p].r].size < alpha * tr[p].size)
        d = 0;
    else
        return;

    if (tr[ch(ch(p, d), d ^ 1)].size * (1 - alpha) >= tr[ch(p, d)].size * (1 - 2 * alpha))
        rotate(ch(p, d), d ^ 1);

    rotate(p, d);
}
inline void insert(int p, int val) {
    if (tr[p].size == 1) {
        int x = create(tr[p].val), y = create(val);

        if (tr[x].val > tr[y].val)
            swap(x, y);

        tr[p].l = x, tr[p].r = y;
        pushup(p);
        return;
    }

    insert(val <= tr[tr[p].l].val ? tr[p].l : tr[p].r, val);
    pushup(p);
    maintain(p);
}
inline void remove(int &p, int val) {
    if (tr[tr[p].l].val >= val) {
        if (tr[tr[p].l].size == 1) {
            p = tr[p].r;
        } else {
            remove(tr[p].l, val);
            pushup(p);
            maintain(p);
        }
    } else {
        if (tr[tr[p].r].size == 1) {
            p = tr[p].l;
        } else {
            remove(tr[p].r, val);
            pushup(p);
            maintain(p);
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in", "r", stdin);
    freopen("E:/codes/exe/a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    rt = create(INT_MAX);
    insert(rt, INT_MIN + 1);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        insert(rt, x);
    }
    while (m--) {
        int opt, x;
        cin >> opt >> x;
        x ^= lst;   
        if (opt == 1) {
            insert(rt, x);
        } else if (opt == 2) {
            remove(rt, x);
        } else if (opt == 3) {
            lst = getrank(x) - 1;
            ans ^= lst; 
        } else if (opt == 4) {
            lst = getval(x + 1);
            ans ^= lst;
        } else if (opt == 5) {
            lst = getpre(x);
            ans ^= lst;
        } else if (opt == 6) {
            lst = getnext(x);
            ans ^= lst;
        }
    }
    cout << ans << '\n';
    return 0;
}