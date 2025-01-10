#include<bits/stdc++.h>
using namespace std;
namespace code{
    #define F(i,x,y) for(int i=(x);i<=(y);i++)
    #define debug(x) cerr<<#x<<'='<<x<<endl
    constexpr int N=100005,mod=1000000007;
    long long dp[N];
    struct limit{
        int c,d;
        constexpr limit(const int& x=0,const int& y=0):c(x),d(y){}
    }a[N];
    long long qpow(long long a,int b){
        long long ans=1;
        while(b){
            if(b&1)ans=ans*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return ans;
    }
    map<int,int>check;
    int main(){
		freopen("assign.in","r",stdin);
		freopen("assign.out","w",stdout);
        cin.tie(0)->sync_with_stdio(0);
		int T;
		cin>>T;
		while(T--){
            check.clear();
            int n,m,v;
            cin>>n>>m>>v;
            long long ans=1;
            bool _=0;
            F(i,1,m){
                cin>>a[i].c>>a[i].d;
                if(check[a[i].c]==0)check[a[i].c]=a[i].d;
                else if(check[a[i].c]!=a[i].d){
                    _=1;
                    break;
                }
            }
            sort(a+1,a+1+m,[](const limit& x,const limit& y)->bool{return x.c<y.c;});
            if(_){
                cout<<0<<'\n';
                continue;
            }
            ans=qpow(v,2*(a[1].c-1))%mod;
            F(i,2,m){
                if(a[i].c==a[i-1].c)continue;
                long long k=(qpow(v,2*(a[i].c-a[i-1].c))-qpow(v,a[i].c-a[i-1].c-1)*(v-1)%mod+mod)%mod;
                ans=(ans*k)%mod;
            }
            ans=(ans*qpow(v,2*(n-a[m].c))%mod);
            cout<<ans<<'\n';
		}
        return 0;
    }
}
int main(){code::main();return 0;}
