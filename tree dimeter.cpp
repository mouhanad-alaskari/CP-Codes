#include <bits/stdc++.h>
/*
*
*
*    Author by Mouhanad
*
*/
using namespace std;
typedef long long ll;
#define F first
#define S second
#define ii pair < int , int >
int n ;
vector < int > adj[10004] ;
 
pair < int , int > dimater ( int i , int par )
{
 
    int dam = 0 ;
    int maxh[3] = { -1 , -1 , -1 } ;
 
    for ( int j = 0 ; j < adj[i].size() ; j++)
   if ( adj[i][j] != par) {
        pair < int , int > p = dimater(adj[i][j] , i);
        dam = max (dam ,p.F );
 
        maxh[0] = p.S +1 ;
 
        sort ( maxh , maxh +3 );
    }
    for ( int w = 0 ; w  <  3 ; w++)
         if ( maxh[w] == -1 )
            maxh[w] = 0 ;
 
    dam = max ( dam , maxh[1] + maxh[2]) ;
     return { dam ,maxh[2]} ;
}
int main()
{
    cin >> n ;
 
    int x , y ;
 
    for (int i = 0 ; i < n-1 ; i++ )
    {
        cin >> x >> y ;
     adj[x].push_back(y);
     adj[y].push_back(x);
    }
 ii ans =     dimater(1 , -1 );
 
cout << ans.F <<endl ;
  return 0 ;
}
 