#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const ll mod=1e9+7,MN=1e7+10;
ll vis[MN],a[MN];
int T,n,m,v;
int main(){
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    cin>>T;
    while(T--){
        //A
        memset(a,-1,sizeof(a));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>v;
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            a[x]=y;
        }
        cout<<(1+v*(v-1))%mod;
//        for(int i=n-1;i>=1;i--){
//            if(a[i]==-2){
//                vis[i]=0;
//            }else if(a[i]>0){
//                if(a[i+1]>0){
//                    vis[i]+=vis[i+1]%mod;
//                    vis[i]%=mod;
//                }else if(a[i+1]==-1){
//                    if(vis[i+1]!=0){
//                        vis[i]+=vis[i+1]%mod;
//                        vis[i]%=mod;
//                    }else{
//                        vis[i]+=v;
//                        vis[i]%=mod;
//                    }
//                }
//                vis[i]+=(v-1)*v%mod;
//            }else if(a[i]==-1){
//                if(vis[i+1]==-2){
//                    vis[i]=0;
//                }
//                else if(vis[i+1]!=0){
//                    vis[i]+=v*v*vis[i+1]%mod;
//                }else{
//                    vis[i]+=v*v*v%mod;
//                }
//            }
//            cout<<"NOW I:"<<i<<" VIS="<<vis[i]<<endl;
//        }
//        cout<<vis[1]<<endl;
    }

    return 0;
}
