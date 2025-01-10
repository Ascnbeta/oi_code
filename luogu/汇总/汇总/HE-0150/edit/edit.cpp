#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int t,n;
	cin>>t;
	for (int i=0; i<t; i++)
		{
			int num=0,fl=1,x;
			cin>>n;
			cin>>s1>>s2>>s3>>s4;
			for (int j=0; j<n-1; j++)
				if (s1[j]!=s1[j+1]) fl=0;
			if (fl==1)
				{
					x=s1[1];
					for (int j=0; j<n; j++)
						if (s2[j]==x) num++;
				}
			cout<<num<<"\n";
		}
	return 0;
}
