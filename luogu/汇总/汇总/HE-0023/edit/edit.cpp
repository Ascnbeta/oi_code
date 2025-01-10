#include <bits/stdc++.h>
#define LL long long
#define Un unsigned
#define __ __int128
#define DB double
#define LD long double
#define pii pair<int,int>
#define pLi pair<LL,int>
#define pLL pair<LL,LL>
#define Ve vector<int>
#define VE vector<LL>
#define pb push_back

using namespace std;

inline LL read()
{
	LL x = 0,f = 1;char ch = getchar();
	while (!isdigit(ch)) (ch == '-') && (f = -1),ch = getchar();
	while (isdigit(ch)) x = x*10+ch-48,ch = getchar();
	return x*f;
}

inline int R()
{
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	return ch-'0';
}

const int N = 1e5+5;
int s1[N],s2[N],t1[N],t2[N];

int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T = read();
	while (T--)
	{
		int n = read();
		for (int i = 1;i <= n;i++) s1[i] = R();
		for (int i = 1;i <= n;i++) s2[i] = R();
		for (int i = 1;i <= n;i++) t1[i] = R();
		for (int i = 1;i <= n;i++) t2[i] = R();
		int a = 0,b = 0,c = 0,d = 0,ans = 0;
		for (int i = 1;i <= n && t1[i];i++) s1[i] ? a++ : b++;
		for (int i = 1;i <= n && t2[i];i++) s2[i] ? c++ : d++;
		for (int i = 1;i <= n;i++)
		{
			if (!t1[i]) s1[i] ? a++ : b++;
			if (!t2[i]) s2[i] ? c++ : d++;
			if (a && c) a--,c--,ans++;
			else if (b && d) b--,d--,ans++;
			else if(a && d) a--,d--;
			else if (b && c) b--,c--;
			if (!t1[i])
			{
				int j = i+1;
				while (j <= n && t1[j]) s1[j] ? a++ : b++,j++;
			}
			if (!t2[i])
			{
				int j = i+1;
				while (j <= n && t2[j]) s2[j] ? c++ : d++,j++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
