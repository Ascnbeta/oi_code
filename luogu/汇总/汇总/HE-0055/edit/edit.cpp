#include <bits/stdc++.h>

using namespace std;

int T;

const int MAXN = 1e5 + 20;

void init(string &x)
{
	if (x[1] == '0') x[0] = '0';
	if (x[x.size() - 2] == '0') x[x.size() - 1] = '0';
	for (int i = 1 ; i < x.size() - 1 ; i ++)
	{
		if (x[i - 1] == '0' and x[i + 1] == '0')
		{
			x[i] = '0';
		}
	}
}

string s1, s2, t1, t2;

int n;

struct node
{
	int cnt1 = 0, cnt0 = 0;
} shf1[MAXN], shf2[MAXN];

int nums1[MAXN], nums2[MAXN];

signed main()
{
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	ios :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> T;
	while (T --)
	{
		cin >> n;
		cin >> s1 >> s2 >> t1 >> t2;
		for (int i = 0 ; i <= n + 1 ; i ++)
		{
			shf1[i].cnt0 = shf1[i].cnt1 = shf2[i].cnt0 = shf2[i].cnt1 = nums1[i] = nums2[i] = 0;
		}
		init(t1);
		init(t2);
		int cnt1 = 0, cnt0 = 0, top = 0;
		for (int i = 0 ; i <= n ; i ++)
		{
			if (i == n or t1[i] == '0')
			{
				shf1[++ top].cnt0 = cnt0;
				shf1[top].cnt1 = cnt1;
				nums1[i] = top;
				cnt1 = cnt0 = 0;
			}
			else
			{
				if (s1[i] == '0') cnt0 ++;
				else cnt1 ++;
			}
		}
		int top2 = 0;
		for (int i = 0 ; i <= n ; i ++)
		{
			if (i == n or t2[i] == '0')
			{
				shf2[++ top2].cnt0 = cnt0;
				shf2[top2].cnt1 = cnt1;
				nums2[i] = top2;
				cnt1 = cnt0 = 0;
			}
			else
			{
				if (s2[i] == '0') cnt0 ++;
				else cnt1 ++;
			}
		}
		int now_num = top;
		for (int i = n ; i >= 0 ; i --)
		{
			if (i == n or t1[i] == '0')
			{
				now_num = nums1[i];
				nums1[i] = 0;
			}
			else
			{
				nums1[i] = now_num;
			}
		}
		
		now_num = top2;
		for (int i = n ; i >= 0 ; i --)
		{
			if (i == n or t2[i] == '0')
			{
				now_num = nums2[i];
				nums2[i] = 0;
			}
			else
			{
				nums2[i] = now_num;
			}
		}
		
//		for (int i = 0 ; i < n ; i ++)
//		{
//			cerr << nums1[i] << ' ';
//		}
//		cerr << '\n';
//		cerr << '\n';
//		for (int i = 0 ; i < n ; i ++)
//		{
//			cerr << shf1[nums1[i]].cnt0 << ' ';
//		}
//		cerr << '\n';
//		for (int i = 0 ; i < n ; i ++)
//		{
//			cerr << shf1[nums1[i]].cnt1 << ' ';
//		}
//		cerr << '\n';
		
		int ans = 0;
		for (int i = 0 ; i < n ; i ++)
		{
			if (t1[i] == '0' and t2[i] == '0')
			{
				if (s1[i] == s2[i]) ans ++;
			}
			else if (t1[i] == '0' and t2[i] == '1')
			{
				if (s1[i] == '0')
				{
					if (shf2[nums2[i]].cnt0)
					{
						shf2[nums2[i]].cnt0 --;
						ans ++;
					}
				}
				else
				{
					if (shf2[nums2[i]].cnt1)
					{
						shf2[nums2[i]].cnt1 --;
						ans ++;
					}
				}
			}
			else if (t1[i] == '1' and t2[i] == '0')
			{
				if (s2[i] == '0')
				{
					if (shf1[nums1[i]].cnt0 > 0)
					{
						shf1[nums1[i]].cnt0 --;
						ans ++;
					}
				}
				else
				{
					if (shf1[nums1[i]].cnt1 > 0)
					{
//						cerr << shf1[nums1[i]].cnt1 << "WHY?\n";
						shf1[nums1[i]].cnt1 --;
//						cerr << shf1[nums1[i]].cnt1 << "WHY?\n";
						ans ++;
					}
				}
			}
//			cerr << "i = " << i << ", " << ans << '\n';
		}
		for (int i = 0 ; i < n ; i ++)
		{
			if (t1[i] == '1' and t2[i] == '1')
			{
				if (shf1[nums1[i]].cnt0 > 0 and shf2[nums2[i]].cnt0 > 0)
				{
//					cerr << i << "  " << "0\n";
					shf1[nums1[i]].cnt0 --;
					shf2[nums2[i]].cnt0 --;
					ans ++;
				}
				else if (shf1[nums1[i]].cnt1 > 0 and shf2[nums2[i]].cnt1 > 0)
				{
//					cerr << i << "  " << "1\n";
					shf1[nums1[i]].cnt1 --;
					shf2[nums2[i]].cnt1 --;
					ans ++;
				}
			}
		}
		cout << ans << '\n';
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

4

1
10
0110111100
1111111100
1110000100
0110111011

*/
