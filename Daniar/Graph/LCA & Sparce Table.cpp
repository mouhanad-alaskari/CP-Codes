#include <bits/stdc++.h>
using namespace std;

const int N = 100100, L = 20;
int timer, in[N], out[N], sz[N];
int n, p[N][L], dep[N];
vector<int>adj[N];

void DFS(int u,int par)
{
    p[u][0]=par;
    dep[u]=1+dep[par];
    in[u]=++timer;
    sz[u]=1;

    for(auto v:adj[u])
        if( v!=par )
        {
            DFS(v,u);
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
    for(int i=1; i<n; i++)
    {
        int a , b ;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1,0);

    for(int j=1; j<L; j++)
        for(int i=1; i<=n; i++)
            p[i][j]=p[ p[i][j-1] ][j-1];

    cout<<LCA(3,6)<<endl;
    cout<<dis(3,6)<<endl;

    return 0;
}
