#include<bits/stdc++.h>
using namespace std;

int T;
int n;
string A,B,C,D;
int apos,bpos;

bool oka(int x){
	return C[x]!='0'&&x<n;
}
bool okb(int x){
	return D[x]!='0'&&x<n;
}

int Calc(int a0,int b0,int a1,int b1){
	int cur=0;
	while(oka(apos)){
		if(A[apos]=='0')a0++;
		if(A[apos]=='1')a1++;
		apos++;
	}
	while(okb(bpos)){
		if(B[bpos]=='0')b0++;
		if(B[bpos]=='1')b1++;
		bpos++;
	}
//	cout<<apos<<' '<<bpos<<' '<<a0<<' '<<a1<<' '<<b0<<' '<<b1<<'\n';
	if(apos==bpos && apos!=n){
		cur+=(A[apos]==B[bpos]);
		apos++,bpos++;
		cur+=min(a0,b0)+min(a1,b1);
		return cur+Calc(0,0,0,0);
	}
	if(apos==bpos && apos==n){
		return min(a0,b0)+min(a1,b1);
	}
	if(apos<bpos){
		if(A[apos]=='0')a0++;
		if(A[apos]=='1')a1++;
		apos++;
		cur+=min(a0,b0)+min(a1,b1);
		int t=min(a0,b0),s=min(a1,b1);
		b0-=t,b1-=s;a0-=t,a1-=s;
		if(a0)b1-=a0;if(a1)b0-=a1;
		return cur+Calc(0,b0,0,b1);
	}
	if(bpos<apos){
		if(B[bpos]=='0')b0++;
		if(B[bpos]=='1')b1++;
		bpos++;
		cur+=min(a0,b0)+min(a1,b1);
		int t=min(a0,b0),s=min(a1,b1);
		b0-=t,b1-=s;a0-=t,a1-=s;
		if(b0)a1-=b0;if(b1)a0-=b1;
		return cur+Calc(a0,0,a1,0);
	}
}

void solve(){
	cin>>n;
	cin>>A>>B>>C>>D;
	apos=bpos=0;
	cout<<Calc(0,0,0,0)<<'\n';
}

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);	
	cin>>T;
	while(T--)solve();
}
