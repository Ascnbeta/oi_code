#include<bits/stdc++.h>
using namespace std;
using llt=long long;
const llt N=500100,mod=1e9+7;
llt n,q,A,B,h[N],dfn[N],is,a[N],b[N];
struct GRAPH
{
    llt head[N],nxt[N<<1],to[N<<1],siz=1;
    void add(llt st,llt ed){to[++siz]=ed,nxt[siz]=head[st],head[st]=siz;}
}G;
void dfs(llt now,llt fa)
{
    h[now]=h[fa]+1;dfn[now]=++is;
    for(int i=G.head[now];i;i=G.nxt[i])
        if(G.to[i]!=fa)
            dfs(G.to[i],now);
}
struct MIN
{
    llt S[32][N];
    void build(llt* C)
    {
        for(int i=1;i<=n;i++)   S[0][i]=C[i];
        for(int i=1;i<=n;i++)
            for(int j=1;(1<<j)<=i;j++)
                S[j][i]=min(S[j-1][i],S[j-1][i-(1<<j-1)]);
    }
    llt check(llt L,llt R)
    {
        if(L>R) swap(L,R);
        llt dis=__lg(R-L+1);
        return min(S[dis][L+(1<<dis)-1],S[dis][R]);
    }
}dep,Ans;
int main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<n;i++)   scanf("%lld%lld",&A,&B),G.add(A,B),G.add(B,A);
    dfs(1,1);for(int i=1;i<=n;i++)  a[dfn[i]]=h[i];
    dep.build(a);for(int i=1;i<n;i++)  a[i]=dep.check(min(dfn[i],dfn[i+1])+1,max(dfn[i],dfn[i+1]))-1;
    Ans.build(a);
    scanf("%lld",&q);llt l,r,Len,ans;
    while(q--)
    {
        ans=0;
        scanf("%lld%lld%lld",&l,&r,&Len);
        if(Len==1)  for(int i=l;i<=r;i++)   ans=max(h[i],ans);
        else
        {
            for(int i=l;i+Len-1<=r;i++)
                ans=max(ans,Ans.check(i,i+Len-2));
        }
        printf("%lld\n",ans);
    }
    return 0;
}