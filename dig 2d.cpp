include <bits/stdc++.h>
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
#define iii pair < int , pair < int , int > >
const int inf = 99999999 ;
int n , m ;
int dis [104][104];
char grid [30][30];
int adj [30][30];
inline bool inside ( int x , int y )
{
    return x >= 0 && x < m && y >=0 && y < n ;
}
int X[] = { 0 , 0 , 1 , -1 };
int Y[] = { -1 , 1 , 0 , 0 };
void dij ( int i , int j )
{
    priority_queue < iii , vector <iii> , greater <iii> > pq ;
    pq.push({ 0 , {i,j}});
 
    while(pq.size())
    {
        iii u = pq.top() ;
        pq.pop();
        int l = u.F , nx = u.S.F  , ny = u.S.S;
         //cerr<< nx << " " << ny <<endl;
        for ( int k = 0 ; k < 4; k++)
        {
            if ( inside ( nx+X[k] , ny+Y[k] ) && grid[nx+X[k]][ny+Y[k]] != 'X' && dis[nx][ny] + adj [nx+X[k]][ny+Y[k]] <= dis[nx+X[k]][ny+Y[k]] )
            { //cerr << "*" ;
                dis[nx+X[k]][ny+Y[k]]  = dis[nx][ny] + adj[nx+X[k]][ny+Y[k]] ;
                pq.push({dis[nx+X[k]][ny+Y[k]]  , {nx+X[k] , ny+Y[k] }});
            }
        }
    }
}
int main()
{
    while (scanf("%d %d" , &n , &m) ){
            if (!n && !m) return 0;
 
 
        ii s , d ;
        for ( int i = 0 ; i < m ; i++ )   scanf("%s" ,&(grid[i])  );
 
        for ( int i = 0 ; i < m ; i++)
            for ( int j = 0 ; j < n ; j++)
            {
                if ( grid [i][j] == 'S' )
                {
                    s.F = i ;
                    s.S = j ;
                    adj[i][j] = 0 ;
                }
                else if ( grid[i][j] == 'D')
                {
                    d.F = i ;
                    d.S = j ;
                    adj[i][j] = 0 ;
                }
                else
                    adj[i][j] = grid[i][j] - '0' ;
            }
 
        for ( int i = 0 ; i < m ; i++)
            for ( int j = 0 ; j < n ; j++)
                dis[i][j] = inf ;
                  dis [s.F][s.S] = 0 ;
            dij( s.F , s.S  );
 
        /*for ( int i = 0 ; i < m ; i++)
            {for ( int j = 0 ; j < n ; j++)
                cerr << dis[i][j] << " " ;
             cerr << endl ;}*/
        printf("%d\n" , dis[d.F][d.S]);
 
    }
    return 0 ;
 
 
}