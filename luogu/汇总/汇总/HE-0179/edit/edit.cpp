/*
1
6
011101
111010
111010
101101
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int w[N],ans[15];
string s1,s2,t1,t2;
int edit ( ) {
	int ans=0,n;
	memset( w,0,sizeof(w) );
	cin>>n;
	cin>>s1>>s2>>t1>>t2;
	for( int i=0;i<n;i++ ){
		if( s1[i]!=s1[i+1] && s1[i]!=s2[i] && t1[i]==t1[i+1]==1 ){
				swap( s1[i],s1[i+1] );
		}
	}
	for( int i=0;i<n;i++ ){  //
//		if( s2[i]!=s2[i+1] && s1[i]!=s2[i] && t2[i]==t2[i+1]==1 ){
		if( s2[i]!=s1[i] && s2[i+1]!=s1[i+1] && s1[i]!=s2[i+1] && t2[i]==t2[i+1]==1 ){
			swap( s2[i],s2[i+1] );
		}
	}
	for( int i=0;i<n;i++ ){
		if( s1[i]==s2[i] ) ans++;
	}
	return ans;
}
int main () {
	freopen( "edit.in","r",stdin );
	freopen( "edit.out","w",stdout );
	int T; cin>>T;
	for( int i=1;i<=T;i++ ){
		cout<<edit()<<endl;
	}

	fclose( stdin );
	fclose( stdout );
	return 0;
}
