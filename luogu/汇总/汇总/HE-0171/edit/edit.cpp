#include <bits/stdc++.h>
using namespace std;
int n, t;
char sa[100005], sb[100005], ta[100005], tb[100005];

void jh(int x, int y, int z)
{
	
	if (z == 1)
	{
		char k = sa[x];
		sa[x] = sa[y];
		sa[y] = k;
	} 
	else if (z == 2)
	{
		char k = sb[x];
		sb[x] = sb[y];
		sb[y] = k;
	}
	return;
}

void pd(int x, int y)
{
	bool a = 1, b = 1;
	if (ta[x] == '0' || ta[y] == '0')
	{
		a = 0;
	}
	if (tb[x] == '0' || tb[y] == '0')
	{
		b = 0;
	}
	if (a == 0 && b == 0)
	{
		return;
	}
	else if (a == 0)
	{
		if (sb[x] != sb[y])
		{
			if (sb[x] == sa[y] || sb[y] == sa[x])
			{
				jh(x,y,2);
			}
		} 
		return;
	}
	else if (b == 0)
	{
		if (sa[x] != sa[y])
		{
			if (sb[x] == sa[y] || sb[y] == sa[x])
			{
				jh(x,y,1);
			}
		} 
		return;
	}
	else
	{
		if (sb[x] != sb[y])
		{
			if (sb[x] == sa[y] || sb[y] == sa[x])
			{
				jh(x,y,2);
			}
		}
		else if (sa[x] != sa[y])
		{
			if (sb[x] == sa[y] || sb[y] == sa[x])
			{
				jh(x,y,1);
			}
		} 
		return;
	}
}

int main ()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	cin >> t;
	for (int j = 1;j <= t;j++)
	{
		cin >> n;
		cin >> sa >> sb >> ta >> tb;
		for (int i = 0; i < n - 1; i++)
		{
			if (sa[i] != sb[i]) 
			{
				pd(i,i+1);
			}
		}
		int num = 0;
		for (int i = 0;i < n;i++)
		{
			if (sa[i] == sb[i])
			{
				num++;
			}
		}
		cout << num << endl;
	}
	return 0;
}
