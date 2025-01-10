#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 10;
int T, n, m, v, a, b, arr[N], tp, edd = 0, ans;
int main()
{
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		ans = 1;
		cin >> n >> m >> v;
		for (int i = 1; i <= m; i++)
		{
			cin >> tp;
			if (arr[tp])
			{
				cout << 0 << endl;
				edd = 1;
			}
			else
				cin >> arr[tp];
		}
		if (edd)
			continue;
		for (int a = 1; i <= v; i++)
		{
			for (int b = 1; b <= v; b++)
			{
				for (int i = 1; i <= n; i++)
				{
					if (!arr[i])
					{
						if (arr[i] == a)
							arr[i + 1] = b;
					}
					else
					{
						ans *= v ;
					}
				}
			}
		}
		cout << ans << endl;
	}
}
