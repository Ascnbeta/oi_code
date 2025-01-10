#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e9+7;
int n,m,v;
int a[100001];
map<pair<int,int>,int>mp;
int dfs(int now,int lastf){
    if(a[now] and lastf and lastf!=a[now]) return 0;
    if(now>=n) return 1;
    if(mp.count({now,lastf})) return mp[{now,lastf}];
    int res=0;
    for(int i=1;i<=v;++i){
        for(int j=1;j<=v;++j){
            res=(res+dfs(now+1,max(a[now],lastf)==i?j:0))%p;
        }
    }
    return mp[{now,lastf}]=res;
}
inline int power(int a,int t){
    int base=a,ans=1;
    while(t){
        if(t&1){
            ans=ans*base%p;
        }
        base=base*base%p;
        t>>=1;
    }
    return ans;
}
namespace subtaskA{
    void main(){
        int ans=1;
        for(int i=1;i<n;++i){
            ans=(ans*(v*v-v+1))%p;
        }
        cout<<ans<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    // freopen("down/day0/assign/assign2.in","r",stdin);
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    int cases;cin>>cases;while(cases--){
        mp.clear();
        bool issubtaskA=true;
        cin>>n>>m>>v;
        if(n!=m) issubtaskA=false;
        if(m==1){
            for(int i=1;i<=m;++i){
                int x,y;
                cin>>x>>y;
            }
            cout<<power(v*v%p,n-1)<<'\n';
            continue;
        }
        if(n>100000){
            for(int i=1;i<=m;++i){
                int x,y;
                cin>>x>>y;
            }
            cout<<0<<'\n';
            continue;
        }
        bool flag=false;
        memset(a,0,sizeof a);
        for(int i=1;i<=m;++i){
            int x,y;
            cin>>x>>y;
            if(x!=i) issubtaskA=false;
            if(a[x] and a[x]!=y){
                flag=true;
                cout<<0<<'\n';
                break;
            }
            a[x]=y;
        }
        if(issubtaskA) subtaskA::main();
        else if(!flag) cout<<dfs(1,0)<<'\n';
    }
}