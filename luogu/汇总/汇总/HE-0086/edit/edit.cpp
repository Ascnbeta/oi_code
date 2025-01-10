#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 10;

int T, n, ans;
int s1[maxn], s2[maxn];
int t1[maxn], t2[maxn]; 

inline void read(int &n)
{
	int x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();	
	}
	n = x * f;
}

int main()
{
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
    cin >> T;
    while(T--)
    {
    	read(n);
    	for(int i = 1; i <= n; i++)
    		scanf("%1d", &s1[i]);
   		for(int i = 1; i <= n; i++)
    		scanf("%1d", &s2[i]);
    	for(int i = 1; i <= n; i++)
    		scanf("%1d", &t1[i]);
    	for(int i = 1; i <= n; i++)
    		scanf("%1d", &t2[i]);
    	bool flaga, flagb, flagc;
    	flaga = flagb = flagc = true;
    	for(int i = 1; i <= n; i++)
    	{
    		if(i > 1 && s1[i] != s1[i - 1])
    			flaga = false;
    		if(t1[i] != t2[i])
    			flagb = false;
		}
		if(flaga)
		{	
			int ans = 0;
			for(int i = 1; i <= n; i++)
				if(s1[i] == s2[i])
					ans++;
			cout<< ans << endl;
		}
		else if (flagb)
		{
			int cnt1[2],cnt2[2];
			cnt1[0] = cnt1[1] = cnt2[0] = cnt2[1] = 0;
			int ans = 0;
			for(int i = 1; i <= n; i++)	
			{
				if(t1[i] && t2[i])
					cnt1[s1[i]]++, cnt2[s2[i]]++;
				else
				{
					ans += min(cnt1[0], cnt2[0]) + min(cnt1[1], cnt2[1]);
					if(s1[i] == s2[i])
						ans++;
					cnt1[0] = cnt1[1] = cnt2[0] = cnt2[1] = 0;
				}
			}
			ans += min(cnt1[0], cnt2[0]) + min(cnt1[1], cnt2[1]);
			cout << ans << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
This is my solution in Chinese.
But I don't know how to use GB3212 in Dev-C++.
So I think you will see a lot of "kunjinkao"s following. 

我们充分发扬人类智慧以及运用数学直觉，猜测通过交换字符串的相邻两项可以得到任何一个排列。
那么在可以交换的情况下只要统计字符数目是否相等。
考虑如何处理不能交换的情况。
显然对于一个不能交换的字符它两边只能分别处理，而不能越过这个字符。于是在这个位置统计。
完了。
不会。
打特殊性质去了。 
40pts. 
*/
