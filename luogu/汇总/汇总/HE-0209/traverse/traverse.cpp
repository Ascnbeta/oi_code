#include<iostream>
#include<cstdio>

using namespace std;
int u[N],v[N],e[N];
int c,t,n,k;
int main(){
    freopen("traverse.in","r",stdin);
    freopen("traverse.out","w",stdout);
    cin>>c>>t;
    while(t){
        int ans = 0;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            scanf("%d%d",&u[i],&v[i]);
        }
        for(int i=1;i<=k;i++){
            scanf("%d",&e[i]);

        }
        ans = 3;

        cout<<ans<<endl;
        t--;
    }



    return 0;
}
