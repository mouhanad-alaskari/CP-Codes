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
const ll inf = 9999999999999999 ;
int n , k ;
ll dis [100004];
int parent [100004];
vector < pair < int , int > > adj[100004];
vector < int > ans ;
void dij ( int V )
{
    priority_queue < ii , vector <ii> , greater <ii> > pq ;
    pq.push({0 , V});

    while(pq.size())
    {
        ii u = pq.top() ;
        pq.pop();
        int  v = u.S ;

        for ( int i = 0 ; i < adj[v].size(); i++)
        {
            if ( dis[v] + adj [v][i].S < dis[adj[v][i].F] )
            {
                parent[adj[v][i].F] = v ;
                dis[ adj[v][i].F ]  = dis[v] + adj[v][i].S ;
                pq.push({dis[adj[v][i].F] ,adj[v][i].F });
            }
        }
    }
}
int main()
{

    scanf("%d %d " , &n , &k);

    while ( k-- )
    {

        int x , y , z ;

        scanf("%d %d %d" , &x , &y ,&z );

        adj[x].push_back({y ,z}) ;
        adj[y].push_back({x,z}) ;

    }
    for ( int i = 2 ; i <= n ; i++  )
        dis[i] = inf ;
    dij(1);

    // printf("%d" , dis[n]) ;
    if ( dis[n] == inf ) { return cout <<"-1" , 0 ; }
    int i = n ;
    ans.push_back(i);
    while ( i != 1 )
    {
        i = parent[i];
        ans.push_back(i) ;
    }

    reverse(ans.begin(),ans.end());

    for ( int i = 0 ; i < ans.size() ; i++)
        cout << ans[i] <<" " ;
    return 0 ;


}