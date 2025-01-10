#include <bits/stdc++.h>
using namespace std;
const int N=105;
vector<int>x(N);
vector<int>a(N);
vector<int>b(N);
int n,m,v;
vector<vector<int> >res1;
vector<vector<int> >res2;
vector<vector<int> >res3;
int num1,num2,num3;
void dfs1(int step){
    if(step==n){
        res1.push_back(x);
        num1++;
        return;
    }
    if(x[step]!=0)
    {
        dfs1(step+1);
    }
    else
    {
        for(int i=1;i<=v;++i){
            x[step]=i;
            dfs1(step+1);
        }
    }
}
void dfs2(int step){
    if(step==n){
        res2.push_back(a);
        num2++;
        return;
    }
    for(int i=1;i<=v;++i){
        a[step]=i;
        dfs2(step+1);
    }
}
void dfs3(int step){
    if(step==n){
        res3.push_back(b);
        num3++;
        return;
    }
    for(int i=1;i<=v;++i){
        b[step]=i;
        dfs3(step+1);
    }
}
void solve(){
    cin>>n>>m>>v;
    for(int i=0;i<=n;++i)
        x[i]=0,a[i]=0,b[i]=0;
    res1.clear();
    res2.clear();
    res3.clear();
    for(int i=1;i<=m;++i){
        int t;
        cin>>t;
        cin>>x[t];
    }
    dfs1(0);
    dfs2(0);
    dfs3(0);
    int ans=0;
    for(int i=0;i<num1;++i){
        for(int j=0;j<num2;++j){
            for(int k=0;k<num3;++k){
                int ch_eck=0;
                for(int p=0;p<n-1;++p){
                    if(res1[i][p]==res2[j][p]&&res1[i][p+1]!=res3[k][p])
                        ch_eck=1;
                }
                if(ch_eck==0)
                    ans++,ans%=1000000007;
            }     
        }
    }
    cout<<ans%1000000007<<endl;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
} 
