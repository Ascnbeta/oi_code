//É¾×¢ÊÍ
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
string s1, s2, bok1, bok2;
struct node
{
	int n0, n1;
} s1n[N], s2n[N];
int T, lenn, ans, A, B, C, cnt0a, cnt1a, cnt0b, cnt1b, bo1, bo2;
int n0aq, n0ah, n1aq, n1ah, n0bq, n0bh, n1bq, n1bh, rst0, rst1;
int main()
{
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
//É¾×¢ÊÍ
	cin >> T;
	while (T--)
	{
		cin >> lenn >> s1 >> s2 >> bok1 >> bok2;
		ans = cnt0a = cnt1a = cnt0b = cnt1b = n0aq= n0ah= n1aq= n1ah= n0bq= n0bh= n1bq= n1bh= rst0= rst1= 0, A = 1;
		for (int i = 1; i < lenn; i++)
			if (s1[i] != s1[i - 1])
				A = 0;
		if (bok1 == bok2)
			B = 1;
		if (A)
		{
			for (int i = 0; i < lenn; i++)
				if (s2[i] == s1[1])
					ans++;
		}
		else if (B)
		{
			for (int i = 0; i < lenn; i++)
			{
				if (bok1[i] == '0')
				{
					ans = min(cnt0a, cnt0b) + min(cnt1a, cnt1b) + ans;
					if (s1[i] == s2[i])
						ans++;
					cnt0a = cnt1a = cnt0b = cnt1b = 0;
					continue;
				}
				if (s1[i] == '0')
					cnt0a++;
				else
					cnt1a++;
				if (s2[i] == '0')
					cnt0b++;
				else
					cnt1b++;
			}
			ans = min(cnt0a, cnt0b) + min(cnt1a, cnt1b) + ans;
		}
		else
		{
			for (int i = 0; i < lenn; i++)
			{
				if (!bok1[i])
					bo1 = i;
				if (!bok2[i])
					bo2 = i;
			}
			for (int i = 0; i < bo1; i++)
			{
				if (s1[i] == '0')
					n0aq++;
				else
					n1aq++;
			}
			for (int i = 0; i < bo2; i++)
			{
				if (s2[i] == '0')
					n0bq++;
				else
					n1bq++;
			}

			if (bo2 > bo1)
			{
				if (s1[bo1] == '0')
					n0aq++;
				else
					n1aq++;
				if (n0bq >= n0aq)
				{
					ans += n0aq;
					rst0 =  n0bq - n0aq;
				}
				else
					ans += n0bq;
				if (n1bq >= n1aq)
				{
					ans += n1aq;
					rst1 =  n1bq - n1aq;
				}
				else
					ans += n1bq;
				for (int i = bo1 + 1; i < lenn; i++)
				{
					if (s1[i] == '0')
						n0ah++;
					else
						n1ah++;
				}
				for (int i = bo2; i < lenn; i++)
				{
					if (s2[i] == '0')
						n0bh++;
					else
						n1bh++;
				}
				n0bh += rst0, n1bh += rst1;
				ans += min(n0ah, n0bh) + min(n1ah, n1bh);
			}
		}
		cout << ans <<'\n';
	}
} 
//É¾×¢ÊÍ
/*
3
9
011010000
001000101
111101111
111101111
5
00000
10101
01010
11010
9
011010000
001000101
111111011
111111011
*/
