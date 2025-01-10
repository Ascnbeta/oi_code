#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int T=0,ans=0,n,sum1=0,suma=0,sumb=0,sum2=0,sum_he=0,new1,new2,k=0,sum3=0,gca=0,gcb=0,A0=0,B0=0,gca1=0,gcb1=0,gca2=0,gcb2=0,sum_1=0,gca3=0,gcb3=0,deta=0;
int swaap(string a1,string b1,string a2,string b2){
	if(n==1 && a1!=b1){//特殊性A 
		sum1=0;
		return sum1;
	}
	if(a1==b1){
		return n;
	}
	for(int i=0;i<n;i++){
		sum1+=(b1[i]-'0');
		sum_1+=(a1[i]-'0');
		gca+=(a2[i]-'0');
		gcb+=(b2[i]-'0');
		if(a2[i]=='0'){
			A0=i;
		}
		if(b2[i]=='0'){
			B0=i;
		}
	}//特殊性A
	for(int i=1;i<n;i++){//特殊性质A 
		if(a1[i]!=a1[i-1]){
			break;
		}
		if(i==n-1){
			if(a1[i]=='0'){
				return (n-sum1);
			}
			if(a1[i]=='1'){
				return sum1;
			}
		}
	}//特殊性质A 
	if(a2==b2){//特殊性质B 
		for(int i=0;i<n;i++){
			if(a2[i]=='1'){
				suma+=(a1[i]-'0');
				sumb+=(b1[i]-'0');
				continue;
			}
			sum2+=min(suma,sumb);
			sum2=sum2+i-k-max(suma,sumb);
			if(a1[i]==b1[i]){
				sum2++;
			}
			suma=0;
			sumb=0;
			k=i+1;
		}
		return sum2;
	}//特殊性质B
	if(gca==n-1 && gcb==n-1){//特殊性质C 
		if(A0>B0){
			for(int i=0;i<A0;i++){
				gca1+=(a1[i]-'0');
			}
			for(int i=0;i<=B0;i++){
				gcb1+=(b1[i]-'0');
			}
			sum3+=min(gca1,gcb1);
			sum3+=min(A0-gca1,B0+1-gcb1);
			gca2=sum_1-gca1;
			gcb2=sum1-gcb1;
			sum3+=min(gca2,gcb2);
			sum3+=min(n-A0-gca2,n-B0-1-gcb2);
			gca3=sum_1-min(gca1,gcb1)-min(gca2,gcb2);
			gcb3=sum1-min(gca1,gcb1)-min(gca2,gcb2);
			deta=A0-B0-1;
			if(deta==0){
				return sum3;
			}
			sum3+=min(gca3,gcb3);
			sum3+=min(deta-gca3,deta-gcb3);
			return (sum3+1);
		}
		if(A0<B0){
			for(int i=0;i<=A0;i++){
				gca1+=(a1[i]-'0');
			}
			for(int i=0;i<B0;i++){
				gcb1+=(b1[i]-'0');
			}
			sum3+=min(gca1,gcb1);
			sum3+=min(A0+1-gca1,B0-gcb1);
			gca2=sum_1-gca1;
			gcb2=sum1-gcb1;
			sum3+=min(gca2,gcb2);
			sum3+=min(n-A0-1-gca2,n-B0-gcb2);
			gca3=sum_1-min(gca1,gcb1)-min(gca2,gcb2);
			gcb3=sum1-min(gca1,gcb1)-min(gca2,gcb2);
			deta=B0-A0-1;
			if(deta==0){
				return sum3;
			}
			sum3+=min(gca3,gcb3);
			sum3+=min(deta-gca3,deta-gcb3);
			return (sum3+1);
		}
	}//特殊性质C
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin >> T;
	while(T--){
		ans=0;
		sum1=0;
		suma=0;
		sumb=0;
		sum2=0;
		sum3=0;
		gca=0;
		gcb=0;
		sum_he=0;
		gca1=0;
		gcb1=0;
		A0=0;
		B0=0;
		sum_1=0;
		k=0;
		gca2=0;
		gcb2=0;
		gca3=0;
		deta=0;
		gcb3=0;
		cin >> n;
		cin >> s1 >> s2;
		cin >> s3 >> s4;
		ans=swaap(s1,s2,s3,s4);
		cout << ans << endl;
	}
	return 0;
}
