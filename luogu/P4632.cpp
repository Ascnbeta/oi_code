#include <bits/stdc++.h>
#define inf 200000003
typedef long long ll;
using namespace std;
template <typename T>
inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
template <typename T>
inline void write(T x){
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const int maxn = 9e5+5;
int n,k,q;
struct operation{
    int time,tp,pos,x;
    bool operator < (const operation &y) const{
        if (time == y.time) return tp < y.tp;
        return time < y.time;//注意时间
    }
}a[maxn];int totq;
int ans[maxn],num;//开业的商店种类个数
multiset<int> pre[10000005],shop[300005];//pre用于线段树查最小，shop用来确定线段树上修改的位置
struct node{
    int val,ls,rs;
}t[10000005];int tot,root;
inline void pushup(int p) {
    t[p].val = min(t[t[p].ls].val,t[t[p].rs].val);
}
inline void modify(int &p,int pos,int v,int tp,int l,int r) {//1开店0闭店
    if (!p) p = ++tot;
    if (l == r) {
        if (tp == 1) pre[p].insert(v);
        else pre[p].erase(pre[p].find(v));
        if (!pre[p].empty()) t[p].val = (*(pre[p].begin()));//非空直接取最小
        else t[p].val = inf;//空了直接就是最大值
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(t[p].ls,pos,v,tp,l,mid);
    else modify(t[p].rs,pos,v,tp,mid+1,r);
    pushup(p);
}
inline int query(ll pos) {
    if (num < k) return -1;//开业商店类型不足 k，无解
    ll l = 1,r = inf,p = root;ll minmid,rmin = inf;//计算右儿子的最小pre
    while (l<r) {
        ll mid = (l+r)>>1;
        minmid = min(rmin,(long long)t[t[p].rs].val);//防止炸掉
        if (pos>mid||minmid<2*pos-mid) p=t[p].rs,l=mid+1;
        else rmin=minmid,p=t[p].ls,r=mid;
    }
    return l-pos;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(k),read(q);
    t[0].val = inf;//0号代表该点不存在，进入这个位置了返回最大值，表示非法
    for (int i = 1; i <= k; i++) {
        shop[i].insert(-inf),shop[i].insert(inf);
        modify(root,inf,-inf,1,1,inf);
    }//给每种商店插哨兵节点
    for (int i = 1; i <= n; i++) {
        int pos,t,x,y;
        read(pos),read(t),read(x),read(y);
        a[++totq] = {x,1,pos,t};//1开店
        a[++totq] = {y,3,pos,t};//3关店
    }
    for (int i = 1; i <= q; i++) {
        int l,y;
        read(l),read(y);
        a[++totq] = {y,2,l,i};//2询问
    }
    sort(a+1,a+totq+1);
    for (int i = 1; i <= totq; i++) {
        if (a[i].tp == 1) {
            auto x=shop[a[i].x].lower_bound(a[i].pos);
            auto y=x;--x;//确认插入位置，进行删改
            modify(root,*y,a[i].pos,1,1,inf);//后面加上新开商店
            modify(root,*y,*x,0,1,inf);//后面删去原来商店
            modify(root,a[i].pos,*x,1,1,inf);//新开商店加上原来
            shop[a[i].x].insert(a[i].pos);
            if (shop[a[i].x].size() == 3) ++num;//变为3说明这种类型商店存在了

        }else if(a[i].tp == 3) {
            auto x=shop[a[i].x].lower_bound(a[i].pos);
            auto y=x;--x,++y;//确认删除位置，进行删改
            modify(root,*y,*x,1,1,inf);//后面加上原来商店
            modify(root,*y,a[i].pos,0,1,inf);//后面删去现在商店
            modify(root,a[i].pos,*x,0,1,inf);//现在商店删去原来
            shop[a[i].x].erase(shop[a[i].x].find(a[i].pos));
            if (shop[a[i].x].size() == 2) --num;//变为2说明这种类型商店关门了

        }else if(a[i].tp == 2) {
            ans[a[i].x] = query(a[i].pos);//回答询问
        }
    }
    for (int i = 1; i <= q; i++) {
        write(ans[i]),putchar('\n');
    }
    return 0;
}