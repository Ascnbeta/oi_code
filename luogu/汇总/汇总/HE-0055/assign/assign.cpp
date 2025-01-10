#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

#define int long long int

const int MOD = 1e9 + 7;

int T;

int n, m, v;

int c[MAXN], d[MAXN];

int list_x[MAXN];

bool const_x[MAXN];

int quick_pow(int x, int b)
{
	if (b == 0)
	{
		return 1;
	}
	if (b == 1)
	{
		return x;
	}
	int temp = quick_pow(x, b / 2) % MOD;
	if (b % 2 == 0)
	{
		return (temp * temp) % MOD;
	}
	else
	{
		return x * (temp * temp % MOD) % MOD;
	}
}

int a[MAXN], b[MAXN], temp[MAXN];
int ans = 0;
void dfs(int pos)
{
	if (pos == (n - 1) * 2 + 1)
	{
		for (int i = 1 ; i <= (n - 1) ; i ++)
		{
			a[i] = temp[i];
			b[i] = temp[i + (n - 1)];	
		}
		
//		for (int i = 1 ; i < n ; i ++)
//		{
//			cerr << a[i] << ' ';
//		}
//		cerr << '\n';
//		for (int i = 1 ; i < n ; i ++)
//		{
//			cerr << b[i] << ' ';
//		}
//		cerr << "\n\n";
		
		for (int i = 1 ; i <= n ; i ++)
		{
			if (const_x[i] == true and const_x[i + 1] == true)
			{
				if (a[i] == list_x[i] and b[i] != list_x[i + 1])
				{
					return;
				}
			}
		}
		
		// NOOOOO!
		
		
		ans ++;
		return;
	}
	for (int i = 1 ; i <= v ; i ++)
	{
		temp[pos] = i;
		dfs(pos + 1);
	}
}

signed main()
{
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	ios :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> T;
	while (T --)
	{
		
		bool flagA = false, flagB = false, flagC = true;
		cin >> n >> m >> v;
		if (n <= 12 and v <= 2)
		{
			flagA = true;
		}
		if (m == 1)
		{
			flagB = true;
		}
		if (m != n)
		{
			flagC = false;
		}
		for (int i = 1 ; i <= m ; i ++)
		{
			cin >> c[i] >> d[i];
			if (c[i] != i)
			{
				flagC = false;
			}
		}
		if (flagA)
		{
			memset(const_x, 0, sizeof(const_x));
			memset(list_x, 0, sizeof(list_x));
			bool is_error = false;
			for (int i = 1 ; i <= m ; i ++)
			{
				if (const_x[c[i]] and list_x[c[i]] != d[i])
				{
					is_error = true;
					cout << 0 << '\n';
					break;
				}
				const_x[c[i]] = true;
				list_x[c[i]] = d[i];
			}
			if (!is_error)
			{
				ans = 0;
				dfs(1);
				cout << ans << '\n';
			}
		}
		else if (flagB)
		{
			if (v < 1)
			{
				cout << 0 << '\n';
				continue;
			}
			else if (v == 1)
			{
				cout << 1 << '\n';
				continue;
			}
			else
			{
				cout << quick_pow(v, (n - 1) * 2) << '\n';
			}
		}
		else if (flagC)
		{
			cout << quick_pow(v * (v - 1) + 1, n - 1) << '\n';
		}
		else
		{
			int ans = 0;
			vector < pair < int, int > > ton;
			for (int i = 1 ; i <= m ; i ++)
			{
				ton.push_back(make_pair(c[i], d[i]));
			}
	//		cerr << '\n';
			sort(ton.begin(), ton.end());
			ans = quick_pow(v * v, n - 1) % MOD;
			for (int i = 1 ; i < ton.size() ; i ++)
			{
				if (ton[i] == ton[i - 1]) continue;
				ans = (ans - quick_pow(v, 2 * (ton[i].first - ton[i - 1].first) - 1) * quick_pow(v * v, n - 1 - ton[i].first) % MOD + MOD) % MOD;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}

/*

1
2 2 2
1 1
2 2



1
10 11 2
10 2
7 2
7 2
2 2
3 2
4 2
10 2
7 2
10 2
3 2
3 2

zhe me xuan xue de bao li 5555555


what should i do?

GG

0pts
*/
