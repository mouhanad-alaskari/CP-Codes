#include <bits/stdc++.h>
using namespace std;
 
const int N = 100100 , L = 17;
int n , p[N][L] , dep[N] ;
int timer , in[N] , out[N] , sz[N] ;
vector<int>adj[N];
 
 
void dfs(int u,int par)
{
 
    p[u][0]=par;
    dep[u]=1+dep[par];
    in[u]=++timer;
    sz[u]=1;
 
    for(auto v:adj[u])
        if( v!=par )
        {
            dfs(v,u);
            sz[u]+=sz[v];
        }
 
    out[u]=timer;
}
 
int jump(int u,int k)
{
 
    for(int i=0; i<L; i++)
        if( k&(1<<i) )
            u=p[u][i];
 
    return u;
}
 
int LCA(int u,int v)
{
 
    if( u == v )return u;
    if( dep[u]<dep[v] )swap(u,v);
 
    int dif = dep[u]-dep[v];
    u=jump(u,dif);
 
    if( u == v )return u;
 
    for(int i=L-1; i>=0; i--)
        if( p[u][i]!=p[v][i] )
        {
            u=p[u][i];
            v=p[v][i];
        }
 
    return p[u][0];
}
 
int dis(int u,int v)
{
 
    return dep[u]+dep[v]-2*dep[LCA(u,v)];
 
}
 
int main()
{
 
    cin>>n;
    for(int i=1; i<n; i++) // n-1 edges
    {
        int a , b ;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
 
    for(int j=1; j<L; j++)
        for(int i=1; i<=n; i++)
            p[i][j]=p[ p[i][j-1] ][j-1];
 
 
    return 0;
}


//******* sum in array 
nxt[  i ][ j ] =nxt[  nxt[  i][  j-1]  ][ j-1 ]
S[ i ] [ j ] = S[  i ][ j-1 ]+S[  nxt[ i ][j-1  ]  ][ j-1 ]


int low[N*N] , num[N*N],timer,sz[N*N],idx[N*N];
int in[N*N] , out[N*N];
bool AP[N*N] , vis[N*N];
int par[N*N],f[N*N];
set<int>adj[N*N];


void dfs(int u,int p){
par[u]=p;
timer++;
low[u]=num[u]=timer;
idx[timer]=u;
in[u]=timer;
vis[u]=1;

for(auto v:adj[u])if( v != p ){

if( !vis[v] ){
 dfs(v,u);
 low[u]=min(low[u],low[v]);
 if( low[v]>=num[u] ){
        AP[u]=1;
        sz[u]+=out[v]-in[v]+1;
    }
 }else{
 low[u]=min(low[u],num[v]);
 }

}
out[u]=timer;
} 