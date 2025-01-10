#include <cstdio>
#include <algorithm>
using namespace std;
int T, n;
char s1[1000050], s2[1000050], t1[1000050], t2[1000050]; 
int main()
{
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s%s%s%s", &n, s1 + 1, s2 + 1, t1 + 1, t2 + 1);
		int f1 = 0, g1 = 0, f2 = 0, g2 = 0, z = 0;
		for(int i = 1;i <= n && t1[i] == '1';++i)
			if(s1[i] == '0')
				++f1;
			else
				++g1;
		for(int i = 1;i <= n && t2[i] == '1';++i)
			if(s2[i] == '0')
				++f2;
			else
				++g2;
		for(int i = 1;i <= n;++i)
		{
			if(t1[i] == '1' && t2[i] == '0')
			{
				if(s2[i] == '0')
				{
					if(f1 > 0)
						--f1, ++z;
					else
						--g1;
				}
				else
				{
					if(g1 > 0)
						--g1, ++z;
					else
						--f1;
				}
				z += min(f1, f2) + min(g1, g2);
				if(f1 < f2)
					g1 -= f2 + g2 - f1, f1 = 0;
				else if(g1 < g2)
					f1 -= f2 + g2 - g1, g1 = 0;
				else
					f1 -= f2, g1 -= g2;
				f2 = g2 = 0;
				for(int j = i + 1;j <= n && t2[j] == '1';++j)
					if(s2[j] == '0')
						++f2;
					else
						++g2;
			}
			if(t1[i] == '0' && t2[i] == '1')
			{
				if(s1[i] == '0')
				{
					if(f2 > 0)
						--f2, ++z;
					else
						--g2;
				}
				else
				{
					if(g2 > 0)
						--g2, ++z;
					else
						--f2;
				}
				z += min(f1, f2) + min(g1, g2);
				if(f2 < f1)
					g2 -= f1 + g1 - f2, f2 = 0;
				else if(g2 < g1)
					f2 -= f1 + g1 - g2, g2 = 0;
				else
					f2 -= f1, g2 -= g1;
				f1 = g1 = 0;
				for(int j = i + 1;j <= n && t1[j] == '1';++j)
					if(s1[j] == '0')
						++f1;
					else
						++g1;
			}
			if(t1[i] == '0' && t2[i] == '0')
			{
				if(s1[i] == s2[i])
					++z;
				z += min(f1, f2) + min(g1, g2);
				f1 = g1 = f2 = g2 = 0;
				for(int j = i + 1;j <= n && t1[j] == '1';++j)
					if(s1[j] == '0')
						++f1;
					else
						++g1;
				for(int j = i + 1;j <= n && t2[j] == '1';++j)
					if(s2[j] == '0')
						++f2;
					else
						++g2;
			}
		}
		z += min(f1, f2) + min(g1, g2);
		printf("%d\n", z);
	}
	return 0;
}
