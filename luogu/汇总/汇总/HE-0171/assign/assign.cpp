#include <bits/stdc++.h>
using namespace std;
int n, m, t, v, k, num[15];
int c, d;
int x[1000005];
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	cin >> t;
	for (int w = 1;w <= t;w++)
	{
		k = 0;
		cin >> n >> m >> v;
		for (int j = 1;j <= n;j++)
		{
			x[j] = 0;
		}
		for (int j = 1;j <= m;j++)
		{
			cin >> c >> d;
			if (x[c] != 0 && x[c] != d) 
			{
				k = 1;
			}
			else
			{
				x[c] = d;
			}
		}
		if (k == 1)
		{
			cout << 0 << endl;
		}
		else
		{
			num[w] = 1;
			for (int i = 1;i < n;i++)
			{
				if (x[i] != 0)
				{
					if (x[i + 1] != 0)
					{
						num[w] *= (v-1) * v + 1;
					}
					else
					{
						num[w] *= (v-1) * v * v;
					}
				}
				else
				{
					num[w] *= (v-1) * v * v;
				}
			}
			cout << num[w] << endl;
		}
	}
	return 0;
}
