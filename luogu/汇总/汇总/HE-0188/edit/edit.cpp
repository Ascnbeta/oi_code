#include<bits/stdc++.h>
using namespace std;
long long num[10][1000000];
long long jl[1000000][5];
long long jl1[1000000][5];
string m;
long long a,b;
long long t;
long long zh[1000000],zh1[1000000];
void find1(){
	long long sl=0;
	cin>>a;
	cin>>m;
	for(long long i=0;i<a;i++){
		num[1][i+1]=m[i]-'0';
	}
	cin>>m;
	for(long long i=0;i<a;i++){
		num[2][i+1]=m[i]-'0';
	}
	cin>>m;
	for(long long i=0;i<a;i++){
		num[3][i+1]=m[i]-'0';
	}
	cin>>m;
	for(long long i=0;i<a;i++){
		num[4][i+1]=m[i]-'0';
	}
	for(long long i=1;i<=a;i++){
		if(num[3][i]==0){
			jl[i][num[1][i]]=1;
			zh[i]=i;
			continue;
		}
		long long j=i;
		long long m[10];
		m[1]=0;
		m[0]=0;
		m[num[1][i]]++;
		while(j+1<=a&&num[3][j+1]==1){
			j++;
			m[num[1][j]]++;
		}
		for(long long k=i;k<=j;k++){
			zh[k]=j;
			jl[k][1]=m[1];
			jl[k][0]=m[0];
		}
		i=j;
	}
	for(long long i=1;i<=a;i++){
		if(num[4][i]==0){
			jl1[i][num[2][i]]=1;
			zh1[i]=i;
			continue;
		}
		long long j=i;
		long long m[10];
		m[1]=0;
		m[0]=0;
		m[num[2][i]]++;
		while(j+1<=a&&num[4][j+1]==1){
			j++;
			m[num[2][j]]++;
		}
		for(long long k=i;k<=j;k++){
			zh1[k]=j;
			jl1[k][1]=m[1];
			jl1[k][0]=m[0];
		}
		i=j;
	}
	for(long long i=1;i<=a;i++){
		if((jl[i][1]!=0&&jl1[i][1]!=0)||(jl[i][0]!=0&&jl1[i][0]!=0)){
			if(jl[i][1]>0){
				for(long long k=i;k<=zh[i];k++){
					jl[k][1]--;
				}
				for(long long k=i;k<=zh1[i];k++){
					jl1[k][1]--;
				}
			}
			else{
				for(long long k=i;k<=zh[i];k++){
					jl[k][0]--;
				}
				for(long long k=i;k<=zh1[i];k++){
					jl1[k][0]--;
				}
			}
			sl++;
		}
		else {
			if(jl[i][1]>0){
				for(long long k=i;k<=zh[i];k++){
					jl[k][1]--;
				}
				for(long long k=i;k<=zh1[i];k++){
					jl1[k][0]--;
				}
			}
			else{
				for(long long k=i;k<=zh[i];k++){
					jl[k][0]--;
				}
				for(long long k=i;k<=zh1[i];k++){
					jl1[k][1]--;
				}
			}
		}
	}
	cout<<sl<<endl;
	for(long long i=1;i<=a;i++){
		num[1][i]=0;
		num[2][i]=0;
		num[3][i]=0;
		num[4][i]=0;
		jl[i][1]=0;
		jl[i][0]=0;
		jl1[i][1]=0;
		jl1[i][0]=0;
		zh[i]=0;
		zh1[i]=0;
	}
	return;
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++){
		find1();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
