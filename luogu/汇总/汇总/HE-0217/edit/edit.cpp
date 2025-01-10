#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n,ans,pop;
int dp[N][3];	
string s1,s2,t1,t2;

int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T --)
	{
		int pop = 0;
		bool flag = false;
		scanf("%d",&n);
		cin >> s1;
		cin >> s2;
		cin >> t1;
		cin >> t2;
		for(int i = 1;i < n;i ++)
			if(s1[i] != s1[i - 1]) flag = true;
		if(!flag)
		{
			for(int i = 0;i < n;i ++)
				if(s2[i] == s1[i]) pop ++;
			printf("%d\n",pop);
			continue;
		}
		for(int i = 0;i < n;i ++)
		{
			if(s1[i] == s2[i]) continue;
			if(t1[i] == '0') continue;
			if(t1[i + 1] == '0') continue;
			for(int j = i + 1;j < n;j ++)
			{
				if(s1[j] == s2[i])
				{
					t2[i] = '0';
					for(int k = i + 1;k <= j;k ++)
						s1[k] = s1[k - 1];
					s1[i] = s2[i];
					break;
				}
			}
		}
		for(int i = 0;i < n;i ++)
		{
			if(s1[i] == s2[i]) continue;
			if(t2[i] == '0') continue;
			if(t2[i + 1] == '0') continue;
			for(int j = i + 1;j < n;j ++)
			{
				if(s2[j] == s1[i])
				{
					t1[i] = '0';
					for(int k = i + 1;k <= j;k ++)
						s2[k] = s2[k - 1];
					s1[i] = s2[i];
					break;
				}
			}
		}	
		for(int i = 0;i < n;i ++)
			if(s1[i] == s2[i]) pop ++;
		printf("%d\n",pop);
	}
	return 0;
}
/*
1
6
011101
111010
111010
101101
*/

