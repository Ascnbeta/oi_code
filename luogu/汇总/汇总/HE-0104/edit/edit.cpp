// g++ edit.cpp -o edit -O2 -std=c++14 -static
#include <bits/stdc++.h>

typedef long long ll;

const int N = 1e5 + 10;

ll T, n;
char s1[N], s2[N], t1[N], t2[N];
bool vis[2];
bool ss1[N][2], ss2[N][2];
ll cnt[2];
ll ans;

namespace sub1
{
	void solve()
	{
		ans = n;
		cnt[0] = cnt[1] = 0;
        for (int i = 1; i <= n; ++i)
        {
			ss1[i][0] = ss1[i][1] = false;
			ss1[i][s1[i] - '0'] = true;
			if (t1[i] == '1')	
				if (i > 1 && t1[i - 1] == '1')
					ss1[i][0] |= ss1[i - 1][0], ss1[i][1] |= ss1[i - 1][1];
			++cnt[s1[i] - '0'];
        }
		for (int i = n; i >= 1; --i)
			if (t1[i] == '1')
				if (i < n && t1[i + 1] == '1')
					ss1[i][0] |= ss1[i + 1][0], ss1[i][1] |= ss1[i + 1][1];
		for (int i = 1; i <= n; ++i)
        {
			ss2[i][0] = ss2[i][1] = false;
			ss2[i][s2[i] - '0'] = true;
			if (t2[i] == '1')
				if (i > 1 && t2[i - 1] == '1')
					ss2[i][0] |= ss2[i - 1][0], ss2[i][1] |= ss2[i - 1][1];
			++cnt[s2[i] - '0'];
        }
		for (int i = n; i >= 1; --i)
			if (t2[i] == '1')
				if (i < n && t2[i + 1] == '1')
					ss2[i][0] |= ss2[i + 1][0], ss2[i][1] |= ss2[i + 1][1];
		for (int i = 1; i <= n; ++i)
		{
			if (ss1[i][0] && ss1[i][1] && ss2[i][0] && ss2[i][1])
				continue;
			if (ss1[i][0] && ss2[i][0])
				cnt[0] -= 2;
			else if (ss1[i][1] && ss2[i][1])
				cnt[1] -= 2;
			else
				--cnt[0], --cnt[1], --ans;
		}
		for (int i = 1; i <= n; ++i)
			if (ss1[i][0] && ss1[i][1] && ss2[i][0] && ss2[i][1])
			{
				if (cnt[0] > 0)
					cnt[0] -= 2;
				else
					cnt[1] -= 2;
			}
		ans -= abs(cnt[0] - cnt[1]) / 2;
		printf("%lld\n", ans);
	}
}

namespace sub2
{
	void dfs(int pos)
	{
		if (pos == n)
		{
			ll res = 0;
			for (int i = 1; i <= n; ++i)
				if (s1[i] == s2[i])
					++res;
			ans = std::max(ans, res);
			return;
		}
		if (t1[pos] == '1' && t1[pos + 1] == '1')
			std::swap(s1[pos], s1[pos + 1]);
		dfs(pos + 1);
		if (t2[pos] == '1' && t2[pos + 1] == '1')
			std::swap(s2[pos], s2[pos + 1]);
		dfs(pos + 1);
		if (t1[pos] == '1' && t1[pos + 1] == '1')
			std::swap(s1[pos], s1[pos + 1]);
		dfs(pos + 1);
		if (t2[pos] == '1' && t2[pos + 1] == '1')
			std::swap(s2[pos], s2[pos + 1]);
		dfs(pos + 1);
	}

	void solve()
	{
		ans = 0;
		dfs(1);
		printf("%lld\n", ans);
		return;
	}
}

int main()
{
    freopen("edit.in", "r", stdin);
    freopen("edit.out", "w", stdout);
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld", &n);
        scanf("%s%s%s%s", s1 + 1, s2 + 1, t1 + 1, t2 + 1);
		int tepcnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!vis[s1[i] - '0'])
				vis[s1[i] - '0'] = true, ++tepcnt;
			++cnt[s2[i] - '0'];
		}
		if (tepcnt == 1)
			printf("%lld\n", std::max(cnt[0], cnt[1]));
		else if (n > 10)
			sub1::solve();
		else
			sub2::solve();
    }
	return 0;
}