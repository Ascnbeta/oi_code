#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
const long long MX=1000010,INF=0x3f3f3f3f,MO=1e9+7;
long long n,m,v;
long long ni(long long b){
    if(b==0)  return 1;
    long long sum=ni(b>>1ll);
    sum=(sum*sum)%MO;
    if(b&1ll)  sum=(sum*v)%MO;
    return (sum%MO+MO)%MO;
}
long long ans;
vector<long long>vec;
__gnu_pbds::gp_hash_table<long long,long long>flag;//the end loser
void solve(){
    scanf("%lld%lld%lld",&n,&m,&v);
    ans=1;
    flag.clear();vec.clear();
    for(long long i=1;i<=m;i++){
        long long c,d;scanf("%lld%lld",&c,&d);
        vec.push_back(c);
        if(flag[c]){
            if(flag[c]!=d)  ans=0;
        }
        else  flag[c]=d;
    }
    if(ans==0){
        printf("%lld\n",ans);
        return ;
    }
    sort(vec.begin(),vec.end());
    unique(vec.begin(),vec.end());
    long long las=0,x;
    if(flag[1])  las=1;
    for(auto i:vec){
        if(i==1)  continue;
        if(las!=0){
            x=ni(i-las);
            ans*=((x*x)%MO-((ni(i-las-1)*(v-1))%MO)+MO)%MO,ans%=MO;
        }
        else{
            x=ni(i-1);
            ans*=(x*x)%MO;ans%=MO;
        }
        las=i;
    }
    if(!flag[n]){
        x=ni(n-las);
        ans*=(x*x)%MO;ans%=MO;
    }
    printf("%lld\n",((ans%MO)+MO)%MO);
}
signed main(){
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    long long T;scanf("%lld",&T);
    while(T--){
        solve();
    }
    return 0;
}

