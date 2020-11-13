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
int n , last = 0 ;
vector < int > adj[10004] ;
int parent[100004];
int vis[100004];
void bfs1 ( int v   )
{
    // cout <<"*" ;
    queue<int> q ;
    q.push(v);
    vis[v] = 1 ;
    while ( q.size())
    {
        int nv = q.front() ;
        q.pop();
 
        //  cout << nv << endl;
        for ( int i = 0 ; i < adj[nv].size() ; i++)
            if ( !vis[adj[nv][i]])
            {
                q.push(adj[nv][i]);
                last = adj[nv][i] ;
                vis[adj[nv][i]] = 1 ;
            }
    }
}
void  bfs2 ( int v , int u  )
{
    queue<int> q ;
    q.push(v);
    vis[v] = 1;
    while ( q.size())
    {
        int nv = q.front() ;
        q.pop();
        for ( int i = 0 ; i < adj[nv].size() ; i++)
            if ( !vis[adj[nv][i]])
            {
                parent [adj[nv][i]] = nv ;
                q.push(adj[nv][i]);
                if (adj[nv][i] == u ) return ;
                vis[adj[nv][i]] = 1 ;
            }
    }
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
    bfs1(1);
 
    int s = last ;
//cout << "__________"<<endl;
    memset( vis , 0 , sizeof vis );
 
    bfs1 (last) ;
    int d = last ;
    // cout << s << " " << d  <<endl;
 
    memset( vis , 0 , sizeof vis );
    bfs2 ( s , d );
    int cnt = 1 ;
 
    while ( parent[d] != s)
    {
        cnt++ ;
        d = parent [d] ;
    }
    cout << cnt <<endl;
    return 0 ;
}
 