#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+10;
int v1[maxN][2];
int v2[maxN][2];
int f1[maxN],f2[maxN];
void work()
{
	int n; string s1,s2,t1,t2;
	memset(v1,0,sizeof(v1));
	memset(v2,0,sizeof(v1));
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	
	int ans = 0;
	int ta=1,tb=1;
	
	cin >> n;
	cin >> s1 >> s2 >> t1 >> t2;
	
	
	for(int i=0;i<n;i++)
	{
		if(i != 0 and t1[i] != t1[i-1] or t1[i] == '0') ta ++;
		if(i != 0 and t2[i] != t2[i-1] or t2[i] == '0') tb ++;
		v1[ta][s1[i] == '1'] ++;
		v2[tb][s2[i] == '1'] ++;
		f1[i] = ta;f2[i] = tb;
	}
	
	for(int i=0;i<n;i++)
	{
		if(v1[f1[i]][0]>0 and v2[f2[i]][0]>0)
		{
			v1[f1[i]][0]--,v2[f2[i]][0]--;
			ans ++;continue;
		}
		if(v1[f1[i]][1]>0 and v2[f2[i]][1]>0)
		{
			v1[f1[i]][1]--,v2[f2[i]][1]--;
			ans ++;continue;
		}
		if(v1[f1[i]][0]>0 and v2[f2[i]][1]>0)
		{
			v1[f1[i]][0]--,v2[f2[i]][1]--;
			continue;
		}
		if(v1[f1[i]][1]>0 and v2[f2[i]][0]>0)
		{
			v1[f1[i]][1]--,v2[f2[i]][0]--;
			continue;
		}
		
		
	}
	cout << ans << endl;
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int tt;
	cin >> tt;
	while(tt --)
	{
		work();
	}
	return 0;
}
