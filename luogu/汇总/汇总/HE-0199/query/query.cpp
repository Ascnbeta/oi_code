#include<bits/stdc++.h>
using namespace std;

int T,n,sum;
string s1,s2,t1,t2;
int sum1,sum2,a1[100005],a2[100005];
int a3[100005],a4[100005];
int b1[100005],b2[100005];
bool c;
int main(){
	freopen("query.in","r",stdin);
	freopen("qyery.out","w",stdout);
	cin>>n;
	int j,l;
	for(int i=0;i<n-1;i++){
		cin>>j>>l;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int a,b,c;
		cin>>a>>b>>c;
		cout<<a*b*c*b/c;
		
		cout<<endl;
	}
	
	
	return 0;
//	fclose(stdin);
//	fclose(stdout);
}
