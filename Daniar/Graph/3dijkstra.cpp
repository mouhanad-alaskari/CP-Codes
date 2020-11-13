#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >

typedef long long ll;
const ll inf = 1e9;

const int N=100100;

/// int parent[N];
/// vector<int>ans ;

ll dis[N]; /// distance between source & destinations
vector<ii>adj[N];

void dij(int s)
{
    priority_queue< ii , vector <ii> , greater <ii> > pq ;
    pq.push({0 , s});

    while(pq.size())
    {
        int c = pq.top().F;
        int v = pq.top().S;
        pq.pop();

        if(dis[v] != c) continue;

        for( auto x : adj[v] )
        {
            if ( dis[v] + x.S < dis[x.F] )
            {
                /// parent[x.F] = v ;
                dis[x.F]  = dis[v] + x.S ;
                pq.push({dis[x.F] ,x.F});
            }
        }
    }
}

int main()
{
    int t ;
    scanf("%d" , &t);
    while (t--)
    {
        int  n , k , s , d ;
        /// s : source
        /// d : destination
        scanf("%d%d%d%d" , &n , &k , &s , &d);

        while ( k-- )
        {

            int x , y , z ;

            scanf("%d %d %d" , &x , &y ,&z );

            adj[x].push_back({y,z}) ;
            adj[y].push_back({x,z}) ;

        }
        for (int i = 1 ; i <= n ; i++ ) dis[i] = inf ;

        dis[s] = 0 ;
        dij(s);

        if ( dis[d] == inf ) printf("NONE\n");
        else printf("%d\n" , dis[d]);


        /** Get path

        int i = d ; /// : destination
        ans.push_back(i);
        while ( i != 1 ){
            i = parent[i];
            ans.push_back(i) ;
        }

        reverse(ans.begin(),ans.end());

        for ( int i = 0 ; i < ans.size() ; i++)
            cout << ans[i] <<" " ; */

    }
    return 0 ;
}
