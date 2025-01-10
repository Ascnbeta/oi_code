#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int fa[N];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int getfa(int x)
{
	if(x==fa[x])
		return x;
	return getfa(fa[x]);
}
void lca(int x)
{
	if(x==fa[x])
		return;
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	return 0;
}
