#include<bits/stdc++.h>
using namespace std;
int n,T,same;
string s1,s2,t1,t2;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;++o){
		cin>>n>>s1>>s2>>t1>>t2;
			for(int i=0;i<n;++i)
			if(s1[i]!=s2[i]&&t1[i]=='1'&&t1[i+1]=='1')
				swap(s1[i],s1[i+1]);
			for(int i=0;i<n;++i)
			if(s2[i]!=s1[i]&&t2[i]=='1'&&t2[i+1]=='1')
				swap(s2[i],s2[i+1]);
		for(int i=0;i<n;++i)
			if(s1[i]==s2[i])
				same++;
		cout<<same<<endl;
		same=0;
		}
	return 0;
	fclose(stdin);
	fclose(stdout);
}








