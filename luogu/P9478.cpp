#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
int c,n,m,q;
struct node{
    int ls,rs;ll val,tag;
};
struct SegmentTree{
    node t[7000000];int tot,root;
    inline void pushdown(int p,int l,int r) {
        int mid = (l + r) >> 1;
        if (!t[p].ls) t[p].ls = ++tot;
        if (!t[p].rs) t[p].rs = ++tot; 
        t[t[p].ls].val += (mid-l+1)*t[p].tag;
        t[t[p].rs].val += (r-mid)*t[p].tag;
        t[t[p].ls].tag += t[p].tag;
        t[t[p].rs].tag += t[p].tag;
        t[p].tag = 0;
    }
    inline void modify(int &p,int s,int e,int l,int r) {
        if (!p) p = ++tot;
        if (s <= l && r <= e) {
            t[p].tag += 1;
            t[p].val += (r-l+1);
            return;
        }
        int mid = (l + r) >> 1;
        if (l != r && t[p].tag) pushdown(p,l,r);
        if (s <= mid) modify(t[p].ls,s,e,l,mid);
        if (e > mid) modify(t[p].rs,s,e,mid+1,r);
    }
    inline ll query(int p,int pos,int l,int r) {
        if (!p) return 0;
        if (l == r) return t[p].val;
        int mid = (l + r) >> 1;
        if (l != r && t[p].tag) pushdown(p,l,r);
        if (pos <= mid) return query(t[p].ls,pos,l,mid);
        else return query(t[p].rs,pos,mid+1,r);
    }
}Tree;
struct operation{
    int tp,x1,y1,x2,y2;
}op1[maxn<<1],op2[maxn<<1],op3[40],opt[maxn<<2];
int tot1,tot2,tot3,tot;
bool cmp1 (const operation &x,const operation &y) {
    if (x.x1 == y.x1) return x.y1 < y.y1;
    return x.x1 < y.x1;
}
bool cmp2 (const operation &x,const operation &y) {
    if (x.y1 == y.y1) return x.x1 < y.x1;
    return x.y1 < y.y1;
}
bool cmp3 (const operation &x,const operation &y) {
    if (x.x1-x.y1==y.x1-y.y1) return x.x1 < y.x1;
    else return x.x1-x.y1<y.x1-y.y1;
}
bool cmp (const operation &x,const operation &y) {
    if (x.x1 == y.x1) return x.tp < y.tp;
    return x.x1 < y.x1;
}
inline void merge() {
    sort(op1+1,op1+tot1+1,cmp1);
    int cnt = tot1;
    for (int i = 1; i <= tot1; i++) {
        int l = i;
        while (i < tot1 && op1[i].x1 == op1[i+1].x1) ++i; 
        int r = i;
        int lst = l,ed = op1[l].y2;
        for (int j = l+1; j <= r; j++) {
            if (op1[j].y1 <= ed) ed = max(ed,op1[j].y2);
            else{
                op1[++cnt] = {1,op1[j].x1,op1[lst].y1,op1[j].x2,ed};
                lst = j,ed = op1[j].y2;
            }
        }
        op1[++cnt] = {1,op1[lst].x1,op1[lst].y1,op1[lst].x1,ed};
    }
    for (int i = 1; i <= cnt-tot1; i++) op1[i] = op1[tot1+i];
    tot1 = cnt-tot1;
    // for (int i = 1; i <= tot1; i++) {
    //     cout << op1[i].x1 << ' ' << op1[i].y1 << ' ' << op1[i].y2 << '\n';
    // }
    sort(op2+1,op2+tot2+1,cmp2);
    cnt = tot2;
    for (int i = 1; i <= tot2; i++) {
        int l = i;
        while (i < tot2 && op2[i].y1 == op2[i+1].y1) ++i; 
        int r = i;
        int lst = l,ed = op2[l].x2;
        for (int j = l+1; j <= r; j++) {
            if (op2[j].x1 <= ed) ed = max(ed,op2[j].x2);
            else{
                op2[++cnt] = {2,op2[lst].x1,op2[j].y1,ed,op2[j].y1};
                lst = j,ed = op2[j].x2;
            }
        }
        op2[++cnt] = {2,op2[lst].x1,op2[lst].y1,ed,op2[lst].y1};
    }
    for (int i = 1; i <= cnt-tot2; i++) op2[i] = op2[tot2+i];
    tot2 = cnt-tot2;
    // for (int i = 1; i <= tot2; i++) {
    //     cout << op2[i].y1 << ' ' << op2[i].x1 << ' ' << op2[i].x2 << '\n';
    // }
    sort(op3+1,op3+tot3+1,cmp3);
    cnt = tot3;
    for (int i = 1; i <= tot3; i++) {
        int l = i;
        while (i < tot3 && op3[i].x1-op3[i].y1 == op3[i+1].x1-op3[i+1].y1) ++i; 
        int r = i;
        int lst = l,ed = op3[l].x2;
        for (int j = l+1; j <= r; j++) {
            if (op3[j].x1 <= ed) ed = max(ed,op3[j].x2);
            else{
                op3[++cnt] = {3,op3[lst].x1,op3[lst].y1,ed,op3[lst].y1+ed-op3[lst].x1};
                lst = j,ed = op3[j].x2;
            }
        }
        op3[++cnt] = {3,op3[lst].x1,op3[lst].y1,ed,op3[lst].y1+ed-op3[lst].x1};
    }
    for (int i = 1; i <= cnt-tot3; i++) op3[i] = op3[tot3+i];
    tot3 = cnt-tot3;
    // for (int i = 1; i <= tot3; i++) {
    //     cout << op3[i].x1 << ' ' << op3[i].y1 << ' ' << op3[i].x2 << ' ' << op3[i].y2 << '\n';
    // }
}
ll ans[maxn],sum;
#define inf 1000000000
inline void calc12() {
    for (int i = 1; i <= tot1; i++) opt[i] = op1[i];
    tot = tot1;
    for (int i = 1; i <= tot2; i++) {
        opt[++tot] = {2,op2[i].x1-1,op2[i].y1,i,op2[i].y2};
        opt[++tot] = {3,op2[i].x2,op2[i].y1,i,op2[i].y2};
    }
    sort(opt+1,opt+tot+1,cmp);
    for (int i = 1; i <= tot; i++) {
        if (opt[i].tp == 1) {
            Tree.modify(Tree.root,opt[i].y1,opt[i].y2,0,inf);
        }else if(opt[i].tp == 2) {
            ans[opt[i].x2] -= Tree.query(Tree.root,opt[i].y1,0,inf);
        }else{
            ans[opt[i].x2] += Tree.query(Tree.root,opt[i].y1,0,inf);
        }
    }
    for (int i = 1; i <= tot; i++) sum += 1ll*(opt[i].tp==1)*(opt[i].y2-opt[i].y1+1);
    for (int i = 1; i <= tot2; i++) {
        sum += 1ll*(op2[i].x2-op2[i].x1+1-ans[i]);
    }
    // cout << sum << '\n';
}
set<pair<int,int>> s;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> c >> m >> n >> q;
    for (int i = 1; i <= q; i++) {
        int tp,x1,y1,x2,y2;
        cin >> tp >> y1 >> x1 >> y2 >> x2;
        if (tp == 1) {
            op1[++tot1] = {tp,x1,y1,x2,y2};
        }else if(tp == 2) {
            op2[++tot2] = {tp,x1,y1,x2,y2};
        }else if(tp == 3) {
            op3[++tot3] = {tp,x1,y1,x2,y2};
        }
    }
    merge();
    calc12();
    for (int i = 1; i <= tot3; i++) {
        sum += op3[i].x2 - op3[i].x1 + 1;
        s.clear();
        for (int j = 1; j <= tot1; j++) {
            if (op1[j].x1 < op3[i].x1 || op1[j].x1 > op3[i].x2) continue;
            int p = op3[i].y1+op1[j].x1-op3[i].x1;
            if (p >= op1[j].y1 && p <= op1[j].y2) --sum,s.insert({op1[j].x1,p});
        }
        for (int j = 1; j <= tot2; j++) {
            if (op2[j].y1 < op3[i].y1 || op2[j].y1 > op3[i].y2) continue;
            int p = op3[i].x1+op2[j].y1-op3[i].y1;
            if (p >= op2[j].x1 && p <= op2[j].x2 && s.count({p,op2[j].y1}) == 0) --sum;
        }
    }
    cout << sum << '\n';
    return 0;
}