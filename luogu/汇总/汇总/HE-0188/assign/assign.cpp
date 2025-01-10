#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
long long t;
long long num[100000];
long long jl[100000],dy[100000];
long long sl;
int num1[100000];
long long pd(){
	for(int i=1;i<=a;i++){
		num1[i]=num[i];
	}
	for(long long i=1;i<a;i++){
		if(num1[i]==0){
			continue;
		}
		if(num1[i]!=jl[i]){
			continue;
		}
		if(num1[i]==jl[i]){
			if(dy[i]!=num1[i+1]&&num1[i+1]!=0)return 0;
			else {
				num1[i+1]=dy[i];
			}
		}
	}
	return 1;
}
void xz(long long x){
	if(x>=a){
		if(pd())sl++;
		sl%=1000000007;
		return;
	}
	for(long long i=1;i<=c;i++){
		for(long long j=1;j<=c;j++){
			jl[x]=i;
			dy[x]=j;
			xz(x+1);
		}
	}
	return;
}
void find1(){
	cin>>a>>b>>c;
	sl=0;
	for(long long i=1;i<=a;i++){
		num[i]=0;
		jl[i]=0;
		dy[i]=0;
	}
	long long p=0;
	for(long long i=1;i<=b;i++){
		long long x,y;
		cin>>x>>y;
		if(num[x]!=0&&num[x]!=y){
			p++;
		}
		num[x]=y;
	}
	if(p>0){
		cout<<0<<endl;
		return;
	}
	xz(1);
	cout<<sl<<endl;
	return;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++){
		find1();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
