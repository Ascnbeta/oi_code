#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<int>e[500001];
int deep[500001],fa[500001],top[500001];
int size[500001],maxson[500001];
void dfs1(int now,int last){
    fa[now]=last;
    deep[now]=deep[last]+1;
    size[now]=1;
    int maxsonsize=0;
    for(int i:e[now]){
        if(i!=last){
            assert(now!=i);
            dfs1(i,now);
            size[now]+=size[i];
            if(size[i]>maxsonsize){
                maxsonsize=size[i];
                maxson[now]=i;
            }
        }
    }
}
void dfs2(int now,int nowtop){
    // cout<<"dfs2 "<<now<<" "<<nowtop<<' '<<maxson[now]<<endl;
    top[now]=nowtop;
    if(!maxson[now]) return;
    dfs2(maxson[now],nowtop);
    for(int i:e[now]){
        if(i!=fa[now] and i!=maxson[now]){
            dfs2(i,i);
        }
    }
}
inline int lca(int x,int y){
    // cout<<"lca "<<x<<" "<<y<<" = "<<endl;
    // assert(x!=0 and y!=0);
    while(top[x]!=top[y]){
        // cout<<x<<' '<<y<<' '<<top[x]<<' '<<top[y]<<endl;
        if(deep[top[x]]<deep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    // cout<<(deep[x]<deep[y]?x:y)<<endl;
    return deep[x]<deep[y]?x:y;
}
int st[19][500001];
int _lg2[500001];
inline int get_lca(int l,int r){
    int tmp=_lg2[r-l+1];
    // cout<<"["<<l<<" "<<l+(1<<tmp)-1<<"]+["<<r-(1<<tmp)+1<<" "<<r<<"]"<<endl;
    return lca(st[tmp][l],st[tmp][r-(1<<tmp)+1]);
}
int main(){
    // freopen("down/day0/query/query2.in","r",stdin);
    // freopen("out.out","w",stdout);
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    _lg2[1]=0;
    for(int i=2;i<=n;++i){
        _lg2[i]=_lg2[i/2]+1;
    }
    for(int i=1;i<=n-1;++i){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(1,0);
    dfs2(1,1);
    for(int i=1;i<=n;++i){
        st[0][i]=i;
    }
    for(int i=1;i<=_lg2[n];++i){
        for(int j=1;j+(1<<i)-1<=n;++j){
            st[i][j]=lca(st[i-1][j],st[i-1][j+(1<<(i-1))]);
            // cout<<"st "<<i<<" "<<j<<" "<<st[i][j]<<endl;
        }
    }
    // cerr<<"st:end"<<endl;
    cin>>q;
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        int maxdeep=0;
        for(int i=l;i+k-1<=r;++i){
            // cout<<"["<<l<<" "<<l+k-1<<"] = "<<get_lca(l,l+k-1)<<endl;
            maxdeep=max(maxdeep,deep[get_lca(i,i+k-1)]);
        }
        cout<<maxdeep<<'\n';
    }
}