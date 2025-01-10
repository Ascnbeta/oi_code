#include<bits/stdc++.h>
using namespace std;
bool pa[100100],pb[100100];
char a[100100],b[100100],spa[100100],spb[100100];
int cases,n,cnt[4][4],ans;
// inline void read(){
// 	cout<<cnt[0][0]<<" "<<cnt[0][1]<<"  "<<cnt[1][0]<<" "<<cnt[1][1]<<endl;
// }
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&cases);
	for(;cases;--cases){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%d %s %s %s %s ",&n,a+1,b+1,spa+1,spb+1);
		for(int i=1;i<=n;++i){
			pa[i]=spa[i]-'0';
			pb[i]=spb[i]-'0';
		}
		int ia=1,ib=1;
		for(;ia<=n&&pa[ia];++ia){
			++cnt[0][a[ia]-'0'];
		}
		for(;ib<=n&&pb[ib];++ib){
			++cnt[1][b[ib]-'0'];
		}
		for(;ia<=n||ib<=n;){
			ans+=min(cnt[0][0],cnt[1][0])+min(cnt[0][1],cnt[1][1]);
			// cout<<ia<<" "<<ib<<" "<<ans<<endl;
			// read();
			if(ia<ib){
				if(cnt[0][0]<=cnt[1][0]){
					cnt[1][0]-=cnt[0][0];
				}else{
					cnt[1][1]-=cnt[0][0]-cnt[1][0];
					cnt[1][0]=0;
				}
				if(cnt[0][1]<=cnt[1][1]){
					cnt[1][1]-=cnt[0][1];
				}else{
					cnt[1][0]-=cnt[0][1]-cnt[1][1];
					cnt[1][1]=0;
				}
				cnt[0][0]=0;
				cnt[0][1]=0;
				if(ia<=n){
					if(cnt[1][a[ia]-'0']){
						--cnt[1][a[ia]-'0'];
						++ans;
					}else{
						--cnt[1][(a[ia]-'0')^1];
					}
					++ia;
				}
				for(;ia<=n&&pa[ia];++ia){
					++cnt[0][a[ia]-'0'];
				}
			}else if(ia>ib){
				if(cnt[1][0]<=cnt[0][0]){
					cnt[0][0]-=cnt[1][0];
				}else{
					cnt[0][1]-=cnt[1][0]-cnt[0][0];
					cnt[0][0]=0;
				}
				if(cnt[1][1]<=cnt[0][1]){
					cnt[0][1]-=cnt[1][1];
				}else{
					cnt[0][0]-=cnt[1][1]-cnt[0][1];
					cnt[0][1]=0;
				}
				cnt[1][0]=0;
				cnt[1][1]=0;
				if(ib<=n){
					if(cnt[0][b[ib]-'0']){
						--cnt[0][b[ib]-'0'];
						++ans;
					}else{
						--cnt[0][(b[ib]-'0')^1];
					}
					++ib;
				}
				for(;ib<=n&&pb[ib];++ib){
					++cnt[1][b[ib]-'0'];
				}
			}else{
				memset(cnt,0,sizeof(cnt));
				if(a[ia]==b[ib]){
					++ans;
				}
				++ia;
				++ib;
				for(;ia<=n&&pa[ia];++ia){
					++cnt[0][a[ia]-'0'];
				}
				for(;ib<=n&&pb[ib];++ib){
					++cnt[1][b[ib]-'0'];
				}
			}
			// read();
			// cout<<ans<<endl;
		}
		ans+=min(cnt[0][0],cnt[1][0])+min(cnt[0][1],cnt[1][1]);
		printf("%d\n",ans);
	}
	return 0;
}