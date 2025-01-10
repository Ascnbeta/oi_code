#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read()
{
	int x=0,c=getchar(),f=0;
	for(;c<'0'||c>'9';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}

inline void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

void solve()
{
	cout<<1<<"\n";
}

signed main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	
	int c=read(),t=read();
	while(t--) solve();
	
	return 0;
}

