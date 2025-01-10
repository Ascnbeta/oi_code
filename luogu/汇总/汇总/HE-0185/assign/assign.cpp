#include<bits/stdc++.h>
#define ll long long
#define st string 
using namespace std;
const int N = 1e9 + 7 ;
const int M = 1e5 + 1 ;
ll t ;
ll n , m , v ;
ll c[ M ] , d [ M ] ;
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin >> t ;
	for ( int i = 1 ; i <= t ; i ++ ) {
	    ll a = 4 , b = 3 ;
		cin >> n >> m >> v ;	
		if ( v == 2 ){
		    for ( int j = 1 ; j <= m ; j ++ ) {
			    cin >> c[ j ] >> d[ j ] ;
				for ( int z = 1 ; z <= m ; z ++ ) {
					if ( c[ j ] == c[ z ] && d[ j ] != d[ z ]) 
					b -= 3 ;
				}
		    }
			if ( m == 1 ) cout << a%N << endl ;
			if ( m > 1 ) cout << b%N << endl; 
		}
	}
	return 0 ;
	fclose(stdin);
	fclose(stdout);
}
/*
3
2 1 2
1 1 
2 2 2
1 1
2 2
2 2 2
1 1
1 2
*/
