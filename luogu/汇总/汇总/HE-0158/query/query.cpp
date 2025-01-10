#include<bits/stdc++.h>
#define lid id<<1
#define rid id<<1|1
#define mid (l+r>>1)
const int maxn=5e5+10;
using namespace std;
int n,q,head[maxn],to[maxn<<1],nxt[maxn<<1],tot,s[5010][5010],f[maxn<<1];
void add(int x,int y)
{
    to[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
void addm(int x,int  y)
{
    add(x,y),add(y,x);
}
struct lsx
{
    int tot,st[20][maxn],dep[maxn],dfn[maxn];
    int get(int x,int y){return dep[x]<dep[y]?x:y;}
    void dfs(int x,int fa)
    {
        dfn[x]=++tot,st[0][tot]=fa,dep[x]=dep[fa]+1;
        for(int i=head[x];i;i=nxt[i]) if(to[i]!=fa) dfs(to[i],x);
    }
    void init()
    {
        dfs(1,0);
        for(int i=1;(1<<i)<=n;i++)
        {
            for(int j=1;j<=n-(1<<i)+1;j++)
                st[i][j]=get(st[i-1][j],st[i-1][j+(1<<i-1)]);
        }
    }
    int lca(int x,int y)
    {
        if(x==y) return dep[x];
        if((x=dfn[x])>(y=dfn[y])) swap(x,y);
        int l=__lg(y-x);
        return dep[get(st[l][x+1],st[l][y-(1<<l)+1])];
    }
}e;

void build(int id,int l,int r)
{
    if(l==r) return f[id]=e.lca(l,l),void(0);
    build(lid,l,mid),build(rid,mid+1,r);
    f[id]=min(f[lid],f[rid]);
}

int query(int id,int l,int r,int s,int t)
{
    if(l>=s&&r<=t) return f[id];
    int ans=1e9;
    if(mid>=s) ans=min(ans,query(lid,l,mid,s,t));
    if(mid<t) ans=min(ans,query(rid,mid+1,r,s,t));
    return ans;
}

int main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        addm(x,y);
    }
    e.init();
    if(n<=5000)
    {
        for(int l=1;l<=n;l++)
        {
            for(int r=l+1;r<=n;r++)
            {
                s[l][r]=max(s[l][r-1],e.lca(l,r));
            }
            s[l][l]=e.lca(l,l);
        }
        cin>>q;
        while(q--)
        {
            int l,r,k,ans=0;
            cin>>l>>r>>k;
            for(int i=l;i+k-1<=r;i++)
            {
                ans=max(ans,s[i][i+k-1]);
            }
            cout<<ans<<'\n'; 
        }    
    }
    else
    {
        build(1,1,n);
        cin>>q;
        while(q--)
        {
            int l,r,k;
            cin>>l>>r>>k;
            cout<<query(1,1,n,l,r)<<'\n'; 
        }
    }

    return 0;
}
/*
6
5 6
6 1
6 2
2 3
2 4
3
2 5 2
1 4 1
1 6 3
*/
