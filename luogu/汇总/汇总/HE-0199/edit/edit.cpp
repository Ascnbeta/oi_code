#include<bits/stdc++.h>
using namespace std;

int T,n,sum;
string s1,s2,t1,t2;
int sum1,sum2,a1[100005],a2[100005];
int a3[100005],a4[100005];
int b1[100005],b2[100005];
bool c;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	for(int q=1;q<=T;q++){
		cin>>n>>s1>>s2>>t1>>t2;
	
		for(int i=0;i<n;i++){
			if(t1[i]=='0'){
				sum1++;
				b1[sum1]=i;
				if(s1[i]=='1')a1[sum1]--;
				if(s1[i]=='0')a3[sum1]--;
			}
			if(s1[i]=='1')a1[sum1]++;
			if(s1[i]=='0')a3[sum1]++;
			
			if(t2[i]=='0'){
				sum2++;
				b2[sum2]=i; 
				if(s2[i]=='1')a2[sum2]--;
				if(s2[i]=='0')a4[sum2]--;
			}
			if(s2[i]=='1')a2[sum2]++;
			if(s2[i]=='0')a4[sum2]++;
			
		}
		for(int i=0;i<n-1;i++){
			if(s1[i]!=s1[i+1])c++;
		}

		
		if(c==0){//特殊性质A 
			if(s1[0]=='1'){
				for(int i=0;i<=sum2;i++){
					sum+=a2[i];
				}
			}else{
				for(int i=0;i<=sum2;i++){
					sum+=a4[i];
				}
			}
			cout<<sum<<endl;
			
			for(int i=0;i<=n;i++){
				a1[i]=a2[i]=a3[i]=a4[i]=b1[i]=b2[i]=sum1=sum2=sum=c=0;
			}
			continue;
		}

		c=0;
		
		
		if(t1==t2){//特殊性质B 
			for(int i=0;i<=sum1;i++){
				sum+=min(a1[i],a2[i])+min(a3[i],a4[i]);
			}
			for(int e=1;e<=sum1;e++){
				if(s1[b1[e]]==s2[b2[e]])sum++;
			}
			cout<<sum<<endl;
			for(int i=0;i<=n;i++){
				a1[i]=a2[i]=a3[i]=a4[i]=b1[i]=b2[i]=sum1=sum2=sum=c=0;
			}
			continue;
		}
		
		
		if(sum1==sum2==1){//特殊性质C 
			if(b1[1]==b2[1]){
				sum+=min(a1[0],a2[0])+min(a3[0],a4[0]);
				sum+=min(a1[1],a2[1])+min(a3[1],a4[1]);
				if(s1[b1[1]]==s2[b2[1]]){
					sum++;
				}
			}else if(b1[1]<b2[1]){
				sum+=min(a1[0],a2[0])+min(a3[0],a4[0]);
				a2[0]-=a1[0]; a4[0]-=a3[0];
				sum+=min(a1[1],a2[0])+min(a3[1],a4[0]);
				a1[1]-=a2[0]; a3[1]-=a4[0];
				sum+=min(a1[1],a2[1])+min(a3[1],a4[1]);
				if(s2[b2[1]]=='1'&&a1[1]!=0){
					sum++;
				}else if(s2[b2[1]]=='0'&&a3!=0){
					sum++;
				}
			}else if(b1[1]>b2[2]){
				sum+=min(a1[0],a2[0])+min(a3[0],a4[0]);
				a1[0]-=a2[0]; a3[0]-=a4[0];
				sum+=min(a2[1],a1[0])+min(a4[1],a3[0]);
				a2[1]-=a1[0]; a4[1]-=a3[0];
				sum+=min(a2[1],a1[1])+min(a4[1],a3[1]);
				if(s1[b1[1]]=='1'&&a2[1]!=0){
					sum++;
				}else if(s1[b1[1]]=='0'&&a4!=0){
					sum++;
				}
			}
			cout<<sum<<endl;
			for(int i=0;i<=n;i++){
				a1[i]=a2[i]=a3[i]=a4[i]=b1[i]=b2[i]=sum1=sum2=sum=c=0;
			}
			continue;
			
		}
		
		cout<<0;
	}
	
	
	return 0;
//	fclose(stdin);
//	fclose(stdout);
}
