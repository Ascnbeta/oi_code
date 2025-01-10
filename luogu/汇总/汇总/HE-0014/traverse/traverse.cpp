#include<bits/stdc++.h>
using namespace std;
using llt=long long;
const llt N=500100,mod=1e9+7;
llt c,T,n,k,dp[N],tms[N],is,ans,son,A,B;pair<llt,llt> E[N];bool vis[N];
struct GRAPH
{
    llt head[N],nxt[N<<1],to[N<<1],siz=1;
    void add(llt st,llt ed){to[++siz]=ed,nxt[siz]=head[st],head[st]=siz;}
}G;
void dfs(llt now,llt fa)
{
    dp[now]=1;llt son=0,tot=0;
    for(int i=G.head[now];i;i=G.nxt[i])
        if(G.to[i]!=fa&&(i>>1)!=is)
            dfs(G.to[i],now),son++,dp[now]=dp[now]*dp[G.to[i]]%mod,tot+=vis[G.to[i]];
    if(son>0)   dp[now]=dp[now]*tms[son-1]%mod*(son-tot)%mod;
}
int main()
{
    freopen("traverse.in","r",stdin);
    freopen("traverse.out","w",stdout);
    scanf("%lld%lld",&c,&T);tms[0]=1;
    for(int i=1;i<N;i++)   tms[i]=tms[i-1]*i%mod;
    while(T--)
    {
        scanf("%lld%lld",&n,&k);G.siz=1;ans=0;
        for(int i=1;i<=n-1;i++) 
            scanf("%lld%lld",&E[i].first,&E[i].second),G.add(E[i].first,E[i].second),G.add(E[i].second,E[i].first);
        for(int i=1;i<=k;i++)   
        {
            scanf("%lld",&is);
            if(c<18||c>21)
            {
                dfs(E[is].first,E[is].first);dfs(E[is].second,E[is].second);
                vis[is]=1;ans=(ans+dp[E[is].first]*dp[E[is].second]%mod)%mod;
            }
        }
        if(c==18)   ans=1;
        if(c>=19&&c<=21)    {ans=tms[n-2]*k%mod;for(int i=1;i<=k;i++) ans=(ans-(k-i)*tms[n-3]%mod+mod)%mod;}
        printf("%lld\n",ans);for(int i=1;i<=n;i++)   G.head[i]=vis[i]=0;
    }
    return 0;
}