#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int t;
int calc[N];
char s1[N],s2[N],t1[N],t2[N];
signed main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> s1[i];
		for(int i=1;i<=n;i++) cin >> s2[i];
		for(int i=1;i<=n;i++) cin >> t1[i];
		for(int i=1;i<=n;i++) cin >> t2[i];
		
		for(int i=1;i<=n;i++)
		{
			if(i==1) 
			{
				if(t1[2]=='0') t1[1] = '0';
			}
			else if(i==n) 
			{
				if(t1[n-1]=='0') t1[n] = '0';
			}
			else 
			{
				if(t1[i-1] == '0' && t1[i+1] == '0') t1[i] = '0';
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(i==1) 
			{
				if(t2[2]=='0') t2[1] = '0';
			}
			else if(i==n) 
			{
				if(t2[n-1]=='0') t2[n] = '0';
			}
			else 
			{
				if(t2[i-1] == '0' && t2[i+1] =='0') t2[i] = '0';
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(t1[i] == '1' || t2[i] == '1') calc[i] = 1;
			else calc[i] = 0;
		}//计算出可以换的位置 
		
		int cnt1_1=0,cnt1_0=0;
		int cnt2_1=0,cnt2_0=0; 
		
		for(int i=1;i<=n;i++)
		{
			if(calc[i] == 0) continue;
			
			if(s1[i] == '1') cnt1_1++;
			else if(s1[i] == '0') cnt1_0++;
			
			if(s2[i] == '1') cnt2_1++;
			else if(s2[i] == '0') cnt2_0++; 
		}
		
		int ans = min(cnt1_1,cnt2_1) + min(cnt1_0,cnt2_0);
		
		for(int i=1;i<=n;i++)
		{
			if(calc[i] == 1) continue;
			if(s1[i] == s2[i]) ans++;
		}
		cout << ans << '\n' ;

	}
	
	
	return 0;
}
