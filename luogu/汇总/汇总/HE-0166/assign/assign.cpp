#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
const int mod = 1e9+7;
int ksm(int a,int b)
{
	int res = 1;
	while(b)
	{
		if(b&1) res = res*a%mod;
		a=a*a%mod;
		b >>= 1;
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	
	cin >> t;
	while(t--)
	{
		int n,m,v;
		cin >> n >> m >> v;
		if(v==1)
		{
			int last = 0 , pos = 0;
			for(int i=1;i<=m;i++)
			{
				int c,d;
				cin >> c >> d;
				if(c = pos + 1)
				{
					if(last == 1 && d!=1) 
					{
						cout << 0 << '\n';
						break;
					}
				}
			}
			cout << 1 << endl;
		}	
		else if(v==2)
		{
			int arr[30];
			memset(arr,0,sizeof(arr));
			int flag = 1;
			for(int i=1;i<=m;i++)
			{
				int c,d;
				cin >> c >> d;
				if(arr[c] && arr[c]!=d) 
				{
					cout << 0 << '\n';
					flag = 0;
					break;
				}
				else
				arr[c] = d;
			}
			if(flag)
			{
				int ans = 1;
				for(int i=1;i<=n-1;i++)
				{
					int res = 4;//满足的二元限制个数 
					if(arr[i] == 1 && arr[i+1]!=1 && arr[i+1]!=0 ) res--;
					if(arr[i] == 1 && arr[i+1]!=2 && arr[i+1]!=0 ) res--;
					if(arr[i] == 2 && arr[i+1]!=2 && arr[i+1]!=0 ) res--;
					if(arr[i] == 2 && arr[i+1]!=1 && arr[i+1]!=0 ) res--;
				//	cout << res << endl;
					
					ans = ans*res%mod ;
				}
				cout << ans << '\n';
				
				
			}
			
		}
		else if(m==1)
		{
			int c,d;
			cin >> c >> d;
			int b = v*v % mod;
			cout << ksm(b,n-1) << '\n';
			
			
		}
		else 
		{
			cout << 0 << '\n';
		
		}
		
		
		
	}
	
	
	
	
	return 0;
}
/*
3
2 1 2
1 1
2 2 2
1 1
2 2
2 2 2
1 1
1 2
*/
