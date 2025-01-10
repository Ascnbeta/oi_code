#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int T,n,m,v,a[50000];
using ll = long long;
ll ans;
ll poww(int a,int b){
    ll sum=1;
    while(b--){
        sum=(sum*a)%MOD;
    }
    return sum;
}
int main(){
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>v;
        bool yiyuanf=true;
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            if(a[x]!=0){
                    cout<<0<<endl;
                    yiyuanf=false;
                    break;
            }
            a[x]=y;
        }
        if(!yiyuanf) continue;
        for(int i=0;i<=n;i++){
            ans+=poww(n-i+1,i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
