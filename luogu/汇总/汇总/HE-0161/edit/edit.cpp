#include<bits/stdc++.h>
#define I return 
#define love 0
#define DLY ;
using namespace std;
const int maxn=100000+10;
int q,n,ans;
string s1,s2,c1,c2;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>q;
	for (int i=1;i<=q;++i)
	{
		cin>>n;
		cin>>s1>>s2>>c1>>c2;
		int l2=s2.length();
		for (int i=1;i<=l2;++i)
		{
			if (s1[i]==s2[i])
			{
				ans++;
			}	
		}
	}
	cout<<ans;
	
	I love DLY
}
/*
1
6
011101
111010
111010
101101
*/

