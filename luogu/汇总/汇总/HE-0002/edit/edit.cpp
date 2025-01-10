#include <bits/stdc++.h>
#define filein(x) freopen(x".in", "r", stdin);
#define file(x) {freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);}
using namespace std; // my guiding star.
const int N = 1e5 + 233;
int n, bels[N], belt[N];
string s, t, ps, pt;
unordered_set<int> sp[2][N], tp[2][N];
bool vis[N];
int main()
{
	file("edit");
	int T; cin >> T;
	while (T--)
	{
		cin >> n >> s >> t >> ps >> pt; s = "$" + s; t = "$" + t; ps = "$" + ps; pt = "$" + pt;
		int cs = 0, ct = 0;
		for (int i=1; i<=n; i++)
			if (ps[i] == '1') sp[s[i] - '0'][bels[i] = cs += ps[i - 1] != '1'].insert(i);
		for (int i=1; i<=n; i++)
			if (pt[i] == '1') tp[t[i] - '0'][belt[i] = ct += pt[i - 1] != '1'].insert(i);
		auto aerase = [&](int x){sp[0][bels[x]].erase(x); sp[1][bels[x]].erase(x); tp[0][belt[x]].erase(x); tp[1][belt[x]].erase(x);};
		for (int i=1; i<=n; i++)
		{
			if (ps[i] == '0' || pt[i] == '0') vis[i] = true;
			if (ps[i] == '0' && pt[i] == '0') continue;
			if (ps[i] == '0' && tp[s[i] - '0'][belt[i]].size())
			{
				int j = *tp[s[i] - '0'][belt[i]].begin(); aerase(i); aerase(j);
				swap(t[i], t[j]); tp[t[j] - '0'][belt[j]].insert(j);
			}
			if (pt[i] == '0' && sp[t[i] - '0'][bels[i]].size())
			{
				int j = *sp[t[i] - '0'][bels[i]].begin(); aerase(i); aerase(j);
				swap(s[i], s[j]); sp[s[j] - '0'][bels[j]].insert(j);
			}
		}
		auto Method1 = [&](string s, string t)
		{
			for (int i=1; i<=n; i++) sp[0][i].clear(), sp[1][i].clear(), tp[0][i].clear(), tp[1][i].clear();
			for (int i=1; i<=n; i++)
				if (s[i] != t[i] || !vis[i]){sp[s[i] - '0'][bels[i]].insert(i); tp[t[i] - '0'][belt[i]].insert(i);}
			for (int i=1; i<=n; i++)
			{
				if (!tp[s[i] - '0'][belt[i]].empty() && pt[i] == '1')
				{
					if (*tp[s[i] - '0'][belt[i]].begin() == i)
					{
						if (tp[s[i] - '0'][belt[i]].size() == 1) goto out;
						tp[s[i] - '0'][belt[i]].erase(i);
					}
					int j = *tp[s[i] - '0'][belt[i]].begin(); aerase(i); aerase(j);
					swap(t[i], t[j]); tp[t[j] - '0'][belt[j]].insert(j);
				}
				out:
				if (!sp[t[i] - '0'][bels[i]].empty() && ps[i] == '1')
				{
					if (*sp[t[i] - '0'][bels[i]].begin() == i)
					{
						if (sp[t[i] - '0'][bels[i]].size() == 1) continue;
						sp[t[i] - '0'][bels[i]].erase(i);
					}
					int j = *sp[t[i] - '0'][bels[i]].begin(); aerase(i); aerase(j);
					swap(s[i], s[j]); sp[s[j] - '0'][bels[j]].insert(j);
				}
			}
			int ans = 0;
			for (int i=1; i<=n; i++) ans += s[i] == t[i];
			return ans;
		};
		auto Method2 = [&](string s, string t)
		{
			for (int i=1; i<=n; i++) sp[0][i].clear(), sp[1][i].clear(), tp[0][i].clear(), tp[1][i].clear();
			for (int i=1; i<=n; i++)
				if (s[i] != t[i]){sp[s[i] - '0'][bels[i]].insert(i); tp[t[i] - '0'][belt[i]].insert(i);}
			for (int i=1; i<=n; i++)
			{
				if (!tp[s[i] - '0'][belt[i]].empty() && pt[i] == '1')
				{
					if (*tp[s[i] - '0'][belt[i]].begin() == i)
					{
						if (tp[s[i] - '0'][belt[i]].size() == 1) goto out;
						tp[s[i] - '0'][belt[i]].erase(i);
					}
					int j = *tp[s[i] - '0'][belt[i]].begin(); aerase(i); aerase(j);
					swap(t[i], t[j]); tp[t[j] - '0'][belt[j]].insert(j);
				}
				out:
				if (!sp[t[i] - '0'][bels[i]].empty() && ps[i] == '1')
				{
					if (*sp[t[i] - '0'][bels[i]].begin() == i)
					{
						if (sp[t[i] - '0'][bels[i]].size() == 1) continue;
						sp[t[i] - '0'][bels[i]].erase(i);
					}
					int j = *sp[t[i] - '0'][bels[i]].begin(); aerase(i); aerase(j);
					swap(s[i], s[j]); sp[s[j] - '0'][bels[j]].insert(j);
				}
			}
			int ans = 0;
			for (int i=1; i<=n; i++) ans += s[i] == t[i];
			return ans;
		};
		printf("%d\n", max({Method1(s, t), Method2(s, t)}));
		for (int i=0; i<=n; i++) sp[0][i].clear(), sp[1][i].clear(), tp[0][i].clear(), tp[1][i].clear();
		for (int i=0; i<=n; i++) vis[i] = belt[i] = bels[i] = 0;
	}
	return 0;
}
// Qi zhong ke neng she ji mou xie shen ke de mao dun.
// Wo bu hui yao bao ling le ba /kel