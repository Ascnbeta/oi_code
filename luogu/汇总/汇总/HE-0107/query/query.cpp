#include<bits/stdc++.h>
using namespace std;
int n,u,v,l,r,k,q;
int dep[500000];
vector<int> e[600000];
void dfs(int a,int dept,int fa){
    //if(a==fa) return;
    dep[a]=dept;
    for(int i:e[a]){
        if(i!=fa) dfs(i,dept+1,a);
    }
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,1,0);
    cin>>q;
    while(q--){
        cin>>l>>r>>k;
        cout<<dep[r-k+1]<<endl;
    }
    return 0;
}
