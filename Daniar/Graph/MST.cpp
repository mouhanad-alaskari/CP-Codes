#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >

const int N = 200100;
vector<pair<int,ii>>edge;
int p[N] ;
const int L = 17;
int n , p[N][L] , dep[N] , q;
vector<int>adj[N];
bool use[N];

void dfs(int u,int par)
{

    p[u][0]=par;
    dep[u]=1+dep[par];

    for(auto v:adj[u])
        if( v.F!=par )
        {
            dfs(v.F,u);
            mx[v][0] = v.S ;
        }
 return ;
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

int Par(int i)
{
    return p[i]=( i==p[i] )?i:Par(p[i]);
}
bool same(int i,int j)
{
    return Par(i)==Par(j);
}

void mrg(int i,int j)
{
    if(same(i,j))return;
    i=Par(i);
    j=Par(j);
    if( rand()&1 )swap(i,j);
    p[i]=p[j];
}

void solve()
{
    for(int i=0; i<N; i++)
        p[i]=i;
    edge.clear();

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int a , b , c ;
        scanf("%d %d %d",&a,&b,&c);
        edge.push_back( {c,{a,b}} );
    }
    sort(edge.begin(),edge.end());

    int all=0;
    for(int i=0; i<m; i++)
    {
        int a = edge[i].S.F;
        int b = edge[i].S.S;
        int c = edge[i].F;
        mp[{min(a,b),max(a,b)}] = i ;
        if( same(a,b) )continue;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        use[i] = 1;
        mrg(a,b);
        all+=c;
    }
   dfs(1,0);
    for(int j=1; j<L; j++)
        for(int i=1; i<=n; i++)
            p[i][j]=p[ p[i][j-1] ][j-1], mx[i][j] = max ( mx[ mx[i][j-1] ] [j-1] , mx[i][j-1]);
   scanf("%d",&q);
   while ( q-- ){
   int a , b ; scanf("%d %d",&a,&b);
      if ( use[ mp[{min(a,b),max(a,b)}]] ){
        printf("%d\n",all);
        continue
      }
      printf("%d\n",all+edge[mp[{min(a,b),max(a,b)}]].F-_get(a,b));
   }

    printf("%d\n",ans);
}

int main()
{

    int T = 1 ;
    //canf("%d",&T);
    while( T-- )solve();

    return 0;
}
