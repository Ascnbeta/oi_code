#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
bool ta[100001],tb[100001];
int tas[100001],tbs[100001];
int main()
{
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ta,0,sizeof(ta));
        memset(tb,0,sizeof(tb));
        memset(tas,0,sizeof(tas));
        memset(tbs,0,sizeof(tbs));
        int n;
        cin>>n;
        string sx,sy,tx,ty;
        cin>>sx>>sy>>tx>>ty;
        for(int j=0;j<n;j++)
        {
            if(j==0||j==n-1)
            {
                if(j==0&&tx[1]=='0')
                {
                    tx[j]='0';
                }
                if(j==0&&ty[1]=='0')
                {
                    ty[j]='0';
                }
                if(j==n-1&&tx[n-2]=='0')
                {
                    tx[j]='0';
                }
                if(j==n-1&&ty[n-2]=='0')
                {
                    ty[j]='0';
                }
                continue;
            }
            if(tx[j-1]=='0'&&tx[j+1]=='0')
            {
                tx[j]='0';
            }
            if(ty[j-1]=='0'&&ty[j+1]=='0')
            {
                ty[j]='0';
            }
        }
        int as=0,bs=0;
        for(int j=1;j<=n;j++)
        {
            ta[j]=tx[j-1]-'0';
            tb[j]=ty[j-1]-'0';
            a[j]=sx[j-1]-'0';
            b[j]=sy[j-1]-'0';
            if(ta[j]==0)
            {
                as++;
                tas[as]=j;
            }
            if(tb[j]==0)
            {
                bs++;
                tbs[bs]=j;
            }
            a[j]+=a[j-1];
            b[j]+=b[j-1];
        }
        int ans=0;
        if(as==0||bs==0)
        {
            cout<<n-abs(a[n]-b[n])<<endl;
            continue;
        }
        int la=0,lb=0,qb=0,qa=0;
        for(int j=1;j<=n;j++)
        {
            if(ta[j]==0)
            {
                if(lb==0)
                {
                    la=j;
                    continue;
                }
                int x1=a[j-1]-b[lb];
                if(x1==0)
                {
                    ans+=lb-qb;
                }
                if(x1>0)
                {
                    ans+=b[lb]+j-1-qa-a[j-1];
                }
                if(x1<0)
                {
                    ans+=a[j-1]+lb-qb-b[lb];
                }
                a[lb]=b[lb];
                qa=lb;
                qb=lb;
                lb=0;
                la=j;
            }
            if(tb[j]==0)
            {
                if(la==0)
                {
                    lb=j;
                    continue;
                }
                int x1=b[j-1]-a[la];
                if(x1==0)
                {
                    ans+=la-qa;
                }
                if(x1>0)
                {
                    ans+=a[la]+j-1-qb-b[j-1];
                }
                if(x1<0)
                {
                    ans+=b[j-1]+la-qa-a[la];
                }
                b[la]=a[la];
                qa=la;
                qb=la;
                la=0;
                lb=j;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
