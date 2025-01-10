#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int t[N];
int m[N]={0,1,1,2,6};
int u[N],v[N];
int main(){
    freopen("traverse.in","r",stdin);
    freopen("traverse.out","w",stdout); 
    int c,T;
    cin>>c>>T;
    for(int i=4;i<=1000;++i)
        m[i]=(i-1)*m[i-1]%1000000007;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;++i)
        {
            cin>>u[i]>>v[i];
            t[u[i]]++;
            t[v[i]]++;
        }
        int k=0;
        cin>>k;
        cout<<m[t[u[k]]]*m[t[v[k]]%1000000007<<endl;
    }
}
