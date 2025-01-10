#include<bits/stdc++.h>
using namespace std;
#define int long long
char S[3][100005];
char ops[3][100005];
int n,T;
int ans;
int cnt[10][10];
void chck(int No,int h)
{
	int t0 = min(cnt[1][0],cnt[2][0]);
	int t1 = min(cnt[1][1],cnt[2][1]);
	ans += t0;
	ans += t1;
	cnt[1][0] -= t0;
	cnt[2][0] -= t0;
	cnt[1][1] -= t1;
	cnt[2][1] -= t1;
	if (No == 1)
	{
		cnt[2][0] -= cnt[1][1];
		cnt[2][1] -= cnt[1][0];
		cnt[1][1] = 0;
		cnt[1][0] = 0;
	}
	else
	{
		cnt[1][0] -= cnt[2][1];
		cnt[1][1] -= cnt[2][0];
		cnt[2][1] = 0;
		cnt[2][0] = 0;
	}
	for (int i = h;ops[No][i] == '1';)
	{
		cnt[No][(S[No][i] - '0')] ++;
		ops[No][i] = '2';
		i ++;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(S,0,sizeof(S));
		memset(ops,0,sizeof(ops));
		memset(cnt,0,sizeof(cnt));
		ans = 0;
		cin>>(S[1] + 1)>>(S[2] + 1);
		cin>>(ops[1] + 1)>>(ops[2] + 1);
		for (int i = 1;i<=n;i++)
		{
			if (ops[1][i] == '1') chck(1,i);
			if (ops[2][i] == '1') chck(2,i);
			if (ops[1][i] == '0' && ops[2][i] == '0')
			{
				if (S[1][i] == S[2][i])
				{
					ans++;
				}
				continue;
			}
			if (ops[1][i] == '2' && ops[2][i] == '2')
			{
				continue;
			}
			if (ops[1][i] == '0')
			{
				if (cnt[2][S[1][i] - '0'])
				{
					ans ++;
					cnt[2][S[1][i] - '0'] --;
				}
				else
				{
					cnt[2][(S[1][i] - '0') ^ 1] --;
				}
			}
			else
			{
				if (cnt[1][S[2][i] - '0'])
				{
					ans ++;
					cnt[1][S[2][i] - '0'] --;
				}
				else
				{
					cnt[1][(S[2][i] - '0') ^ 1] --;
				}
			}
		}
		ans += max(0ll,min(cnt[1][0],cnt[2][0]));
		ans += max(0ll,min(cnt[1][1],cnt[2][1]));
		cout<<ans<<"\n";
	}
	return 0;
}
