#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
bool flg = true,xza,xzb,xzc;
int t,n,ans,t10,t20;

signed main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans = 0;
		cin>>n;
		cin>>a>>b>>c>>d;
		for(int i = 0;i < n;i++)
			if(a[i] != a[0])
			{
				flg = false;
				break;
			}	
		if(flg)
		{
			for(int i = 0;i < n;i++)
				if(c[i] == a[0]) ans++;	
			cout<<ans<<'\n';
		}
		if(b == d)
		{
			for(int i = 0;i < n;i++)
			{
				int l = i,r = i,c1t = 0,c2t = 0,dc;
				for(;b[r] - '0';r++)
				{
					if(a[r] - '0') c1t++;
					if(c[r] - '0') c2t++;
				}
				if(a[r] == c[r--]) ans++;
				dc = r - l + 1;
				ans += min(c1t,c2t) + min(dc-c1t,dc-c2t);
				i = r + 1;
			}
			cout<<ans<<'\n';
		}
	}
}
