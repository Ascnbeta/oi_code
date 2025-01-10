#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
vector<int> e[N];
int dfn[N],d[N];
int cn;
void dfs(int no,int fa){
    d[no]=d[fa]+1;
    dfn[no]=++cn;
    for(int to:e[no]){
        if(to==fa)continue;
        dfs(to,no);
    }
}
int lg[N];
int st_d[N][19],st_mi[N][19],st_ma[N][19];
int stt[N][19];
int q;
inline int qu_d(int l,int r){
    int k=lg[r-l+1];
    return min(st_d[l][k],st_d[r-(1<<k)+1][k])-1;
}
inline int qu_mi(int l,int r){
    int k=lg[r-l+1];
    return min(st_mi[l][k],st_mi[r-(1<<k)+1][k]);
}
inline int qu_ma(int l,int r){
    int k=lg[r-l+1];
    return max(st_ma[l][k],st_ma[r-(1<<k)+1][k]);
}
inline int qu_stt(int l,int r){
    int k=lg[r-l+1];
    return max(stt[l][k],stt[r-(1<<k)+1][k]);
}
inline void sol_bl(int l,int r,int k){
    if(k==1){
        printf("%d\n",qu_stt(l,r));
        return;
    }
    int ans=1;
    for(int be=l;be+k-1<=r;++be){
        ans=max(ans,qu_d(qu_mi(be,be+k-1)+1,qu_ma(be,be+k-1)));
    }
    printf("%d\n",ans);
}
const double dp=0.9,eps=1;
double rd(){
    return 1.0*rand()/RAND_MAX;
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    srand(time(0));
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    for(int i=2;i<=n;++i){
        lg[i]=lg[i>>1]+1;
    }
    for(int i=1;i<=n;++i){
        stt[i][0]=d[i];
        st_d[dfn[i]][0]=d[i];
        st_mi[i][0]=dfn[i];
        st_ma[i][0]=dfn[i];
    }
    for(int k=1;k<19;++k){
        for(int l=1;l+(1<<k)-1<=n;++l){
            st_d[l][k]=min(st_d[l][k-1],st_d[l+(1<<k-1)][k-1]);
            st_mi[l][k]=min(st_mi[l][k-1],st_mi[l+(1<<k-1)][k-1]);
            st_ma[l][k]=max(st_ma[l][k-1],st_ma[l+(1<<k-1)][k-1]);
            stt[l][k]=max(stt[l][k-1],stt[l+(1<<k-1)][k-1]);
        }
    }
    scanf("%d",&q);
    while(q--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        if(n<=5000&&q<=5000){
            sol_bl(l,r,k);
            continue;
        }
        if(r-l+1<=100){
            sol_bl(l,r,k);
            continue;
        }
        if(k==1){
            sol_bl(l,r,k);
            continue;
        }
        int ans=1;
        int no=l;
        int nans=qu_d(qu_mi(l,l+k-1)+1,qu_ma(l,l+k-1));
        ans=nans;
        double T=r-l+1;
        while(T>eps){
            int to=no+(2*rd()-1)*T;
            to=max(to,l);to=min(to,r-k+1);
            int del=qu_d(qu_mi(to,to+k-1)+1,qu_ma(to,to+k))-nans;
            if(del>0||exp(del/T)>rd()){
                nans+=del;
                ans=max(ans,nans);
                no=to;
            }
            T*=dp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
