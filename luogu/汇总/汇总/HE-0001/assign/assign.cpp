#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int T;
int n,m;
ll v;
vector<pair<int,int>> op,lop;
bool ch(){
    lop.clear();
    lop.push_back(op[0]);
    for(int i=1;i<op.size();++i){
        if(op[i].first==op[i-1].first){
            if(op[i].second!=op[i-1].second)return 0;
            continue;
        }
        lop.push_back(op[i]);
    }
    op=lop;
    return 1;
}
struct M{
    ll a[2][2];
    ll* operator[](int id){return a[id];}
    M operator*(M y){
        M ans;
        for(int i=0;i<2;++i){
            for(int j=0;j<2;++j){
                ll s=0;
                for(int k=0;k<2;++k){
                    s=(s+a[i][k]*y[k][j])%mod;
                }
                ans[i][j]=s;
            }
        }
        return ans;
    }
}ba1,ba0,as;
inline M ksm(M x,int y){
    M an;
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            an[i][j]=(i==j);
        }
    }
    while(y){
        if(y&1)an=an*x;
        x=x*x;
        y>>=1;
    }
    return an;
}
int nx;
int main(){
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%lld",&n,&m,&v);
        for(int i=0;i<2;++i){
            for(int j=0;j<2;++j){
                as[i][j]=(i==j);
            }
        }
        ba1[0][0]=0;
        ba1[0][1]=v*v%mod;
        ba1[1][0]=0;
        ba1[1][1]=(v*(v-1)+1)%mod;
        ba0[0][0]=v*v%mod;
        ba0[0][1]=0;
        ba0[1][0]=v*(v-1)%mod;
        ba0[1][1]=v;
        op.clear();
        for(int i=1;i<=m;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            op.emplace_back(x,y);
        }
        sort(op.begin(),op.end());
        if(!ch()){
            printf("0\n");
            continue;
        }
        nx=1;
        for(auto it:op){
            if(it.first==1)continue;
            as=as*ksm(ba0,it.first-nx-1);
            as=as*ba1;
            nx=it.first;
        }
        as=as*ksm(ba0,n-nx);
        if(op.size()&&op[0].first==1)printf("%lld\n",(as[1][0]+as[1][1])%mod);
        else printf("%lld\n",(as[0][0]+as[0][1])%mod);
    }
    return 0;
}
