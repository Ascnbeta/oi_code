#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+5;
int n,m,a[maxn];
int trie[18000003][2],tot,siz[18000003],rt[maxn<<1],tree_cnt;
inline void insert(int v) {
    int p = rt[tree_cnt];//上一棵trie树根
    rt[++tree_cnt] = ++tot;
    for (int i = 27; i >= 0; i--) {
        int tmp = (v>>i)&1;
        siz[tot] = siz[p]+1;
        trie[tot][tmp^1] = trie[p][tmp^1];//新点另一侧要连回上一棵树点，类似主席树
        trie[tot][tmp] = tot+1;//路过的点开新点
        ++tot;//不要在一起写，是UB
        p = trie[p][tmp];//原树也要走，不存在不用管，走就行。
    }
    siz[tot] = siz[p]+1;
}
inline int query(int p1,int p2,int x) {
    int ret = 0;
    for (int i = 27; i >= 0; i--) {
        int tmp = (x>>i)&1;
        if (siz[trie[p2][tmp^1]]-siz[trie[p1][tmp^1]]>0) {//反路可以走（类似主席树判断区间内该点有没有）
            p1 = trie[p1][tmp^1],p2 = trie[p2][tmp^1],ret |= 1<<i;
        }else{
            p1 = trie[p1][tmp],p2 = trie[p2][tmp];
        }
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    //从1开始省的0出问题
    insert(0);//开始要插入1，原因是保证有一棵空树
    int s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s ^= a[i];
        insert(s);
    }
    while (m--) {
        char op;cin >> op;
        if (op == 'A') {
            int x;
            cin >> x;
            s ^= x;
            insert(s);//无脑插就行
        }else{
            int l,r,x;
            cin >> l >> r >> x;
            x ^= s;
            cout << query(rt[l-1],rt[r],x) << '\n';
        }
    }
    return 0;
}