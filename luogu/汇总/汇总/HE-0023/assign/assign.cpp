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

inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	while (!isdigit(ch)) (ch == '-') && (f = -1),ch = getchar();
	while (isdigit(ch)) x = x*10+ch-48,ch = getchar();
	return x*f;
}

const int N = 1e5+5,P = 1e9+7;
struct node{int c,d;}a[N];

LL qp(LL x,int y)
{
	LL res = 1;
	while (y)
	{
		if (y&1) res = res*x%P;
		x = x*x%P,y >>= 1;
	}
	return res;
}

int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T = read();
	while (T--)
	{
		LL n = read(),m = read(),v = read();
		for (int i = 1;i <= m;i++) a[i] = {read(),read()};
		sort(a+1,a+m+1,[](node x,node y){return x.c < y.c;});
		bool flg = 1;
		LL f = qp(v*v%P,a[1].c-1),g = 0;
		for (int i = 2;i <= m;i++)
		{
			if (a[i].c == a[i-1].c)
			{
				if (a[i].d != a[i-1].d) {flg = 0;break;}
				else continue;
			}
			g = (g*qp(v*v%P,a[i].c-a[i-1].c)+f*qp(v,a[i].c-a[i-1].c-1)%P*(v-1))%P,
			f = (qp(v*v%P,a[i].c-1)-g)%P;
		}
		if (!flg) puts("0");
		else printf("%lld\n",(f+P)*qp(v*v%P,n-a[m].c)%P);
	}
	return 0;
}
