#include<bits/stdc++.h>
using namespace std;
using llt=long long;
const llt N=1000100,mod=1e9+7;
llt T,n,m,v,sum,P[N],ans;pair<llt,llt> op[N];
llt qpow(llt x,llt y)
{
    x%=mod;llt ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;y>>=1;
    }
    return ret;
}
int main()
{
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&m,&v);ans=1;
        for(int i=1;i<=m;i++)   scanf("%lld%lld",&op[i].first,&op[i].second);
        sum=qpow(v*v%mod,n-1);sort(op+1,op+1+m);m=unique(op+1,op+1+m)-op-1;
        for(int i=1;i<m;i++)
        {
            if(op[i].first==op[i+1].first)  P[i]=1;
            else P[i]=qpow(v,op[i+1].first-op[i].first-1)*(v-1)%mod*qpow(qpow(v*v%mod,op[i+1].first-op[i].first),mod-2)%mod;
        }
        for(int i=1;i<m;i++)   ans=ans*(1-P[i])%mod;ans=(ans+mod)%mod;
        printf("%lld\n",sum*ans%mod);
    }
    return 0;
}