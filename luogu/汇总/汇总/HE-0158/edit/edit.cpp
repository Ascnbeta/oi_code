#include<bits/stdc++.h>
const int maxn=1e5+10;
using namespace std;
int t,n,num[2][2][maxn],blo[2][maxn];
string s1,s2,t1,t2;

int main()
{
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        int ans=0;
        s1.clear(),s2.clear(),t1.clear(),t2.clear();
        cin>>n;
        memset(num,0,sizeof num);
        fill(blo[0],blo[0]+2*n,0);
        cin>>s1>>s2>>t1>>t2;
        s1=" "+s1;s2=" "+s2;t1=" "+t1;t2=" "+t2;
        if(t1[2]=='0') t1[1]='0';
        if(t1[n-1]=='0') t1[n]='0';
        if(t2[2]=='0') t2[1]='0';
        if(t2[n-1]=='0') t2[n]='0';
        for(int i=2;i<=n-1;i++)
        {
            if(t1[i-1]=='0'&&t1[i+1]=='0') t1[i]='0';
            if(t2[i-1]=='0'&&t2[i+1]=='0') t2[i]='0';
        }
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            if(t1[i]=='1')num[0][s1[i]-'0'][cnt]++;
            if(t1[i]=='1')blo[0][i]=cnt;
            if(t1[i+1]=='0'&&t1[i]=='1') cnt++;
        }
        cnt=1;
        for(int i=1;i<=n;i++)
        {
            if(t2[i]=='1')num[1][s2[i]-'0'][cnt]++;
            if(t2[i]=='1')blo[1][i]=cnt;
            if(t2[i+1]=='0'&&t2[i]=='1') cnt++;
        }
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<i<<" "<<blo[0][i]<<" "<<blo[1][i]<<" "<<num[0][0][blo[0][i]]<<" "<<num[0][1][blo[0][i]]<<" "<<num[1][0][blo[1][i]]<<" "<<num[1][1][blo[1][i]]<<endl;
        // }
        for(int i=1;i<=n;i++)
        {
            if(t1[i]=='0')
            {
                if(t2[i]=='0') ans+=s1[i]==s2[i];
                else
                {
                    if(num[1][s1[i]-'0'][blo[1][i]])
                    {
                        // cout<<1<<" "<<i<<endl;
                        ans++;
                        num[1][s1[i]-'0'][blo[1][i]]--;
                    }
                }
            }
            if(t2[i]=='0')
            {
                if(t1[i]!='0')
                {
                    if(num[0][s2[i]-'0'][blo[0][i]])
                    {
                        // cout<<0<<" "<<i<<endl;
                        ans++;
                        num[0][s2[i]-'0'][blo[0][i]]--;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(t1[i]=='1'&&num[0][s1[i]-'0'][blo[0][i]])
            {
                if(t2[i]!='0')
                {
                    if(num[1][s1[i]-'0'][blo[1][i]])
                    {
                        // cout<<0<<" "<<i<<endl;
                        ans++;
                        num[1][s1[i]-'0'][blo[1][i]]--;
                        num[0][s1[i]-'0'][blo[0][i]]--;
                    }
                }
            }
            if(t2[i]=='1'&&num[1][s2[i]-'0'][blo[1][i]])
            {
                if(t1[i]!='0')
                {
                    if(num[0][s2[i]-'0'][blo[0][i]])
                    {
                        // cout<<1<<" "<<i<<endl;
                        ans++;
                        num[0][s2[i]-'0'][blo[0][i]]--;
                        num[1][s2[i]-'0'][blo[1][i]]--;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
/*
1
7
0111011
0101010
1101111
1101111
*/
