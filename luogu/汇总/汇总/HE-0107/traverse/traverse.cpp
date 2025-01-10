#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int c,T;
int n,k,u,v,tr[200000],ans;
vector<int> e[200000];
vector<pair<int,int> >ee[200000];
map<int,pair<int,int> >mp;
bool vis[200000];
int now = 0;
void dfs(int a){
    for(auto i:e[a]){
        vis[a]=true;
        if(!vis[i]) dfs(i);
        vis[a]=false;
    }
    if(a==now){
        ans=(ans+1)%MOD;
        return;
    }
}
int main(){
    freopen("traverse.in","r",stdin);
    freopen("traverse.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            mp[i]={u,v};
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++)
            {
                if(i==j) continue;
                if(mp[i].first==mp[j].second || mp[i].second==mp[j].first){
                    e[i].push_back(j);
                }
            }
        }
        for(int i=1;i<=k;i++){
                cin>>tr[i];
                now=tr[i];
                dfs(tr[i]);
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
