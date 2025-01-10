#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
const int mod=1e9+7;
const int ny2=(mod+1)/2;
int c,T;
int n,k;
int a[N];
pair<int,int> ed[N];
int d[N];
int s[N];
int nc[N];
vector<int> e[N];
ll jc[N];
ll ny[N];
ll ksm(ll x,int y=mod-2){
    ll an=1;
    while(y){
        if(y&1)an=an*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return an;
}
void init(){
    const int lim=100000;
    jc[0]=1;
    for(int i=1;i<=lim;++i)jc[i]=jc[i-1]*i%mod;
    ny[lim]=ksm(jc[lim]);
    for(int i=lim;i;--i){
        ny[i-1]=ny[i]*i%mod;
    }
}
inline ll C(int x,int y){
    if(y>x)return 0;
    if(y<0)return 0;
    return jc[x]*ny[y]%mod*ny[x-y]%mod;
}
inline ll K(int x,int y){
    if(x==1)return 1;
    return (jc[x]*ny2-jc[x-2]*C(x-y,2)%mod+mod)%mod;
}
class sol_k1{
public:
    ll ans;
    void dfs(int no,int fa){
        ans=ans*jc[e[no].size()-1]%mod;
        for(int to:e[no]){
            if(to==fa)continue;
            dfs(to,no);
        }
    }
    void sol(){
        ans=1;
        dfs(ed[a[1]].first,ed[a[1]].second);
        dfs(ed[a[1]].second,ed[a[1]].first);
        printf("%lld\n",ans);
    }
}bl;
void dfs(int no,int fa){
    d[no]=d[fa]+1;
    nc[no]=0;
    for(int to:e[no]){
        if(to==fa)continue;
        dfs(to,no);
    }
}
void dfs2(int no,int fa){
    s[no]=0;
    for(int to:e[no]){
        if(to==fa)continue;
        dfs2(to,no);
        s[no]+=s[to]+nc[to];
    }
}
ll ans;
void dfs3(int no,int fa){
    int cn=(s[1]!=s[no]);
    for(int to:e[no]){
        if(to==fa)continue;
        dfs3(to,no);
        if(s[to]+nc[to])++cn;
    }
    ans=ans*K(e[no].size(),cn)%mod;
}
int main(){
    freopen("traverse.in","r",stdin);
    freopen("traverse.out","w",stdout);
    init();
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)e[i].clear();
        for(int i=1;i<n;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
            ed[i]={u,v};
        }
        for(int i=1;i<=k;++i){
            scanf("%d",&a[i]);
        }
        if(k==1){
            bl.sol();
            continue;
        }
        dfs(1,0);
        for(int i=1;i<=k;++i){
            if(d[ed[a[i]].first]>d[ed[a[i]].second]){
                nc[ed[a[i]].first]++;
            }
            else{
                nc[ed[a[i]].second]++;
            }
        }
        dfs2(1,0);
        ans=1;
        dfs3(1,0);
        printf("%lld\n",ans);
    }
    return 0;
}
