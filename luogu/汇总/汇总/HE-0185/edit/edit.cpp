#include<bits/stdc++.h>
#define ll long long
#define st string 
using namespace std;
const int N = 1e5 ;
ll n , t ;
st s1 , s2 , t1 , t2 ;
ll cnt = 0 ; 
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin >> t ;
	for ( int i = 1 ; i <= t ; i ++ ){
		cin >> n ;
		cin >> s1 >> s2 >> t1 >> t2 ;
		for ( int j = 0 ; j < n ; j ++ ){
			if ( s1[ j ] == s2[ j ] )  s1[ j ] = 10 ;	
	    } 
		for ( int j = 0 ; j < n ; j ++ ){
		    ll h = j ;
	        while( s1[ j ] != 10 ) {
	        	cnt ++ ; h ++ ;
	        	if (  s1[ h ] != 10 ) {
	        		s1[ j ] = 10 , s1[ h ] = 10 ;
				}
			}
	    }  
	}
	cout << cnt << endl ;
	return 0 ;
	fclose(stdin);
	fclose(stdout);
}

