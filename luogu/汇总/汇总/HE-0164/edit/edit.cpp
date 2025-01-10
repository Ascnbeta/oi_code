#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long T,n,ans;
string s1,s2,t1,t2;
bool ok[N],flag[N],ss1[N],ss2[N];
queue<long long> s10,s11,s20,s21; 
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>T;
	while(T--){
		memset(ok,0,sizeof(ok));
		memset(flag,0,sizeof(flag));
		memset(ss1,0,sizeof(ss1));
		memset(ss2,0,sizeof(ss2));
		while(!s10.empty()) s10.pop();
		while(!s11.empty()) s11.pop();
		while(!s20.empty()) s20.pop();
		while(!s21.empty()) s21.pop();
		ans=0;
		cin>>n;
		cin>>s1>>s2>>t1>>t2;
		for(long long i=0;i<n;i++){
			ss1[i]=s1[i]-'0';
			ss2[i]=s2[i]-'0';
			if(s1[i]==s2[i]){
				if(t1[i]!=t2[i] || (t1[i]=='0' && t2[i]=='0')) ok[i]=1;
				else{
					bool _=0;
					if(s1[i]=='0'){
						if(s11.empty()) s10.push(i);
						else{
							while(!s11.empty()){
								if(ok[s11.front()]==1) s11.pop();
								else{
									_=1;
									if(flag[s11.front()]==1){
										swap(ss1[i],ss1[s11.front()]);
										s10.push(s11.front());
										s11.pop();
										flag[s10.front()]=0;
									}
									else{
										swap(ss1[i],ss1[s11.front()]);
										ok[s11.front()]=1;
										s11.pop();
										break;
									}
								}
							}
							if(ok[i]==0) s10.push(i);
						}
					}
					if(s1[i]=='1'){
						if(s10.empty()) s11.push(i);
						else{
							while(!s10.empty()){
								if(ok[s10.front()]==1) s10.pop();
								else{
									_=1;
									if(flag[s10.front()]==1){
										swap(ss1[i],ss1[s10.front()]);
										s11.push(s10.front());
										s10.pop();
										flag[s11.front()]=0;
									}
									else{
										swap(ss1[i],ss1[s10.front()]);
										ok[s10.front()]=1;
										s10.pop();
										break;
									}
								}
							}
							if(ok[i]==0) s11.push(i);
						}
					}
					if(s2[i]=='0'){
						if(s21.empty()) s20.push(i);
						else{
							while(!s21.empty()){
								if(ok[s21.front()]==1) s21.pop();
								else{
									_=1;
									if(flag[s21.front()]==1){
										swap(ss2[i],ss2[s21.front()]);
										s20.push(s21.front());
										s21.pop();
										flag[s20.front()]=0;
									}
									else{
										swap(ss2[i],ss2[s21.front()]);
										ok[s21.front()]=1;
										s21.pop();
										break;
									}
								}
							}
							if(ok[i]==0) s20.push(i);
						}
					}
					if(s2[i]=='1'){
						if(s20.empty()) s21.push(i);
						else{
							while(!s20.empty()){
								if(ok[s20.front()]==1) s20.pop();
								else{
									if(flag[s20.front()]==1){
										swap(ss2[i],ss2[s20.front()]);
										s21.push(s20.front());
										s20.pop();
										flag[s21.front()]=0;
									}
									else{
										swap(ss2[i],ss2[s20.front()]);
										ok[s20.front()]=ok[i]=1;
										s20.pop();
										break;
									}
								}
							}
							if(ok[i]==0) s21.push(i);
						}
					}
					if(_==0) flag[i]=1;
				}
			}
			else{
				if(t1[i]=='0' && t2[i]=='0') ok[i]=0;
				else{
					if(t1[i]=='1'){
						if(s1[i]=='0'){
							if(s11.empty()) s10.push(i);
							else{
								while(!s11.empty()){
									if(ok[s11.front()]==1) s11.pop();
									else{
										if(flag[s11.front()]==1){
											swap(ss1[i],ss1[s11.front()]);
											ok[i]=1;
											s10.push(s11.front());
											s11.pop();
											flag[s10.front()]=0;
										}
										else{
											swap(ss1[i],ss1[s11.front()]);
											ok[s11.front()]=ok[i]=1;
											s11.pop();
											break;
										}
									}
								}
								if(ok[i]==0) s10.push(i);
							}
						}
						if(s1[i]=='1'){
							if(s10.empty()) s11.push(i);
							else{
								while(!s10.empty()){
									if(ok[s10.front()]==1) s10.pop();
									else{
										if(flag[s10.front()]==1){
											swap(ss1[i],ss1[s10.front()]);
											ok[i]=1;
											s11.push(s10.front());
											s10.pop();
											flag[s11.front()]=0;
										}
										else{
											swap(ss1[i],ss1[s10.front()]);
											ok[s10.front()]=ok[i]=1;
											s10.pop();
											break;
										}
									}
								}
								if(ok[i]==0) s11.push(i);
							}
						}
					}
					if(t2[i]=='1'){
						if(s2[i]=='0'){
							if(s21.empty()) s20.push(i);
							else{
								while(!s21.empty()){
									if(ok[s21.front()]==1) s21.pop();
									else{
										if(flag[s21.front()]==1){
											swap(ss2[i],ss2[s21.front()]);
											ok[i]=1;
											s20.push(s21.front());
											s21.pop();
											flag[s20.front()]=0;
										}
										else{
											swap(ss2[i],ss2[s21.front()]);
											ok[s21.front()]=ok[i]=1;
											s21.pop();
											break;
										}
									}
								}
								if(ok[i]==0) s20.push(i);
							}
						}
						if(s2[i]=='1'){
							if(s20.empty()) s21.push(i);
							else{
								while(!s20.empty()){
									if(ok[s20.front()]==1) s20.pop();
									else{
										if(flag[s20.front()]==1){
											swap(ss2[i],ss2[s20.front()]);
											ok[i]=1;
											s21.push(s20.front());
											s20.pop();
											flag[s21.front()]=0;
										}
										else{
											swap(ss2[i],ss2[s20.front()]);
											ok[s20.front()]=ok[i]=1;
											s20.pop();
											break;
										}
									}
								}
								if(ok[i]==0) s21.push(i);
							}
						}
					}
				}
			}
		}
		for(long long i=0;i<n;i++) if(ss1[i]==ss2[i]) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
