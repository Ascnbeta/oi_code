#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int MN=1e5;
int ntot=0;
struct node{
    int dep,fa,pos;
}nd[MN+10];
struct segtree{
    int l,r;
    int lcadep=1e9;
}t[4*MN+10];
void build(int p,int l,int r){
    t[p].l=l;
    t[p].r=r;
    if(l==r){
        t[p].lcadep=nd[nd[l].fa].dep;
        return;
    }
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].lcadep=min(t[p*2].lcadep,t[p*2+1].lcadep);
}
int ask(int p,int k,int fl,int fr){
    int maxx=-1e9;
    if(t[p].l>=fl&&t[p].r<=fr&&(t[p].r-t[p].l+1)>=k){
        maxx=max(maxx,t[p].lcadep);
    }
    int mid=(t[p].l+t[p].r)>>1;
    if(mid>=fl&&(mid-t[p].l+1)>=k) maxx=max(ask(p*2,k,fl,fr),maxx);
    if(mid<fr&&(t[p].r-mid+1)>=k) maxx=max(ask(p*2+1,k,fl,fr),maxx);
    return maxx;
}
vector<int> adj[MN+10];
bool vis[MN+10]{};
int n,q;
bool cmp(node x,node y){
    return x.dep<y.dep;
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n>>q;
    nd[1].dep=0;
    nd[1].fa=1;
    nd[1].pos=1;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        nd[v].fa=u;
        nd[v].dep=nd[u].dep+1;
        nd[v].pos=v;
    }
    //build(1,1,n);
    sort(nd+1,nd+1+n,cmp);
    for(int i=1;i<=q;i++){
        int l,r,k;
        cin>>l>>r>>k;
        for(int i=1;i<=n;i++){
            if(nd[i].pos>=l&&nd[i].pos<=r){
                cout<<nd[nd[i].fa].pos<<endl;
                break;
            }
        }

    }
    return 0;
}
