#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t,p) for(int i = s;i <= t;i += p)
#define drep(i,s,t,p) for(int i = s;i >= t;i -= p)
#ifdef LOCAL
    FILE *I = freopen("in.in","r",stdin),*O = freopen("out.out","w",stdout);
#else
    FILE *I = freopen("assign.in","r",stdin),*O = freopen("assign.out","w",stdout);
#endif
using ll = long long;using ull = unsigned long long;
using db = double;using ldb = long double;
#define int long long
const int N = 1e5 + 10,mod = 1e9 + 7;
int n,m,v,to[N];
pair<int,int> lim[N];
inline int power(int a,int b,int mod){
    int res = 1;
    for(;b;b >>= 1,a = 1ll*a*a%mod)
        if(b&1) res = 1ll*res*a%mod;
    return res;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
int T;cin>>T;
while(T--){
    cin>>n>>m>>v;
    // if(n > 1e5) exit(0);
    rep(i,1,n,1) to[i] = 0;bool flag = true;
    set<int> st;
    rep(i,1,m,1){
        cin>>lim[i].first>>lim[i].second;
        st.insert(lim[i].first);
        // int x = lim[i].first,y = lim[i].second;
    }
    sort(lim+1,lim+1+n);
    if(!flag){cout<<"0\n";continue;}
    int ans = 1;
    rep(i,1,m,1){
        int now = lim[i].first;
        if(st.count(now) && st.count(now+1)){
            int ct = 0;
            while(st.count(now)) ct++,now++;
            ans = (ans*((power((v-1)*v+1%mod,ct,mod))))%mod;
            i = lower_bound(lim+1,lim+1+m,make_pair(now,0ll)) - lim - 1;
        }
        else if(to[i]) ans = (ans*((v-1)*v%mod+v))%mod;
        else ans = (ans*v%mod*v%mod)%mod;
    }
    cout<<ans<<'\n';
}    
}