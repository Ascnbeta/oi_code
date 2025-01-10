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

int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	int c = read(),T = read();
	while (T--)
	{
		int n = read(),k = read();
		for (int i = 1,u,v;i < n;i++)
			u = read(),v = read();
	}
	return 0;
}
