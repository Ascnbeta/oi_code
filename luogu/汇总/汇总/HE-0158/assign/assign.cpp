#include<bits/stdc++.h>
const int mod=1e9+7;
const int maxn=1e5+10;
using namespace std;
int t,n,m,v,a[maxn],b[maxn],d[maxn],tem[maxn],ans;

void lsx(int fi)
{
    if(fi==n)
    {
        for(int i=1;i<=n;i++) d[i]=tem[i];
        for(int i=1;i<n;i++)
        {
            // cout<<d[i]<<" "<<a[i]<<" "<<b[i]<<endl;
            if(d[i]&&d[i]==a[i]) 
            {
                if(d[i+1]&&d[i+1]!=b[i])return;
                d[i+1]=b[i];
            }
        }
        ans++;
        return ;
    }
    for(int i=1;i<=v;i++)
    {
        a[fi]=i;
        for(int j=1;j<=v;j++)
        {
            b[fi]=j;
            lsx(fi+1);
        }
    }
}

int qpow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1) ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        y>>=1;
    }
    return ans;
}

int main()
{
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>v;
        if(n<=100)fill(tem,tem+1+n,0);
        ans=0;int flag=0,flag2=1;
        for(int i=1,x,y;i<=m;i++)
        {
            cin>>x>>y;
            if(x!=i) flag2=0;
            if(x<=100)
            {
                if(tem[x]&&tem[x]!=y)
                {
                    flag=1;
                }
                tem[x]=y;
            }
            
        }
        if(flag)
        {
            cout<<0<<'\n';
            continue;
        }
        if(flag2&&n==m)
        {
            cout<<qpow((1ll*v*(v-1)+1)%mod,n-1)<<'\n';
        }
        else if(m<=1)
        {
            cout<<qpow(1ll*v*v%mod,n-1)<<'\n';
        }
        else
        {
            lsx(1);
            cout<<ans<<'\n';
        }
        
    }


    return 0;
}
/*


*/
