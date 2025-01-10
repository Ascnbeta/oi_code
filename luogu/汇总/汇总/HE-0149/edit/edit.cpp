#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,maxx;
char s1[N],s2[N],t1[N],t2[N];
bool pd1[N],pd2[N];

int dfs(char a[],char b[],bool c[],bool d[],int mat)
{   int res=0;
    for(int i=1;i<=n;i++)
    {
	if(a[i]==b[i]) res++;
	}
	if(mat==n) return res;
	if(a[mat]==b[mat+1]&&mat+1<=n&&c[mat]==1&&c[mat+1]==1)
	{   a[mat]=a[mat+1],a[mat+1]=b[mat+1];
		res=max(dfs(a,b,c,d,mat+1),res);
		a[mat+1]=a[mat],a[mat]=b[mat+1];
	}
 if(a[mat]==b[mat+1]&&mat+1<=n&&d[mat]==1&&d[mat+1]==1)
	{
		b[mat+1]=b[mat],b[mat]=a[mat];
		res=max(res,dfs(a,b,c,d,mat+1));
		b[mat]=b[mat+1],b[mat+1]=a[mat]; 
	}
	res=max(res,dfs(a,b,c,d,mat+1));
}
int main()
{   
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    cin>>t;
    while(t--)
    {
    	cin>>n;
    	cin>>s1+1>>s2+1>>t1+1>>t2+1;
    	for(int i=1;i<=n;i++) {
    		if(t1[i]=='1') pd1[i]=1;
    		if(t2[i]=='1') pd2[i]=1;
		} 
	    int ans1=dfs(s1,s2,pd1,pd2,1);
	    int ans2=dfs(s2,s1,pd2,pd1,1);
    	cout<<max(ans1,ans2);
	}
	return 0;
 } 
