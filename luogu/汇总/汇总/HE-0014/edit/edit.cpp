#include<bits/stdc++.h>
using namespace std;
using llt=long long;
const llt N=100100;
llt T,n,ans,bin1[2],bin2[2];char s1[N],s2[N],t1[N],t2[N];
void find(llt now,char* C,char* U,llt *A)
{
    A[0]=A[1]=0;A[U[now]-'0']++;
    for(int i=now+1;C[i]==C[i-1]&&C[i]!='0'&&i<=n;i++)
        A[U[i]-'0']++;
}  
int main()
{
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);ans=0;
        scanf("%s%s%s%s",s1+1,s2+1,t1+1,t2+1);
        for(int i=1;i<=n;i++)
        {
            if(t1[i]!=t1[i-1]||t1[i]=='0')  find(i,t1,s1,bin1);    
            if(t2[i]!=t2[i-1]||t2[i]=='0')  find(i,t2,s2,bin2);
            if(bin1[1]&&bin2[1])    bin1[1]--,bin2[1]--,ans++;
            else if(bin1[0]&&bin2[0])    bin1[0]--,bin2[0]--,ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}