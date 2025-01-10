#include<bits/stdc++.h>
using namespace std;
namespace code{
    #define F(i,x,y) for(int i=(x);i<=(y);i++)
    #define debug(x) cerr<<#x<<'='<<x<<endl
    constexpr int N=500005;
    int st1[N*2][22],r[N*2][22],st2[N*2][22],eula[N*2],f[N],dept[N],top=0;
    bool vis[N];
    vector<int>ways[N];
    void dfs(const int& now=1,const int& dep=1){
        st1[++top][0]=dep;
        r[top][0]=now;
        f[now]=top;
        dept[now]=dep;
        for(auto i:ways[now]){
            if(!vis[i]){
                vis[i]=1;
                dfs(i,dep+1);
            }
            st1[++top][0]=dep;
            r[top][0]=now;
        }
    }
    void init1(){
        for(int i=1;(1<<i)<=top;i++){
            for(int j=1;j+(1<<i)-1<=top;j++){
                if(st1[j][i-1]<st1[j+(1<<(i-1))][i-1]){
                    st1[j][i]=st1[j][i-1];
                    r[j][i]=r[j][i-1];
                }
                else {
                    st1[j][i]=st1[j+(1<<(i-1))][i-1];
                    r[j][i]=r[j+(1<<(i-1))][i-1];
                }
            }
        }
    }
    int lca(const int& x,const int& y){
        if(f[x]<f[y]){
            const int tmp=__lg(f[y]-f[x]+1);
            return (st1[f[x]][tmp]<st1[f[y]-(1<<tmp)+1][tmp])?r[f[x]][tmp]:r[f[y]-(1<<tmp)+1][tmp];
        }
        const int tmp=__lg(f[x]-f[y]+1);
        return (st1[f[y]][tmp]<st1[f[x]-(1<<tmp)+1][tmp])?r[f[y]][tmp]:r[f[x]-(1<<tmp)+1][tmp];
    }
    void init2(const int& n){
        F(i,1,n)st2[i][0]=i;
        for(int i=1;(1<<i)<=n;i++){
            for(int j=1;j+(1<<i)-1<=n;j++){
                st2[j][i]=lca(st2[j][i-1],st2[j+(1<<(i-1))][i-1]);
            }
        }
    }
    int main(){
		freopen("query.in","r",stdin);
		freopen("query.out","w",stdout);
        cin.tie(0)->sync_with_stdio(0);
		int n,u,v;
		cin>>n;
		F(i,1,n-1){
            cin>>u>>v;
            ways[u].push_back(v);
            ways[v].push_back(u);
		}
		vis[1]=1;
		dfs();
		init1();
		init2(n);
		int q,l,r,k;
		cin>>q;
		while(q--){
            cin>>l>>r>>k;
            int ans=1;
            const int tmp=__lg(k);
            while(l+k-1<=r){
                ans=max(ans,dept[lca(st2[l][tmp],st2[l+k-(1<<tmp)][tmp])]);
                l++;
            }
            cout<<ans<<'\n';
		}
        return 0;
    }
}
int main(){code::main();return 0;}
