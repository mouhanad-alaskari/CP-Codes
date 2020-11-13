#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100100 , L = 17 ;

int n , q , vis[N] ;
int par[N] , ans[N] ;
int dep[N] , p[N][L];

set<int>add[N],del[N];
map<int,int>idx[N];
vector< pair<int,int> >adj[N];
vector< pair< pair<int,int> , int > >ask;
vector< pair< pair<int,int> , int > >tmp;

void join(set<int>&A,set<int>&B){
if( A.size() < B.size() )swap(A,B);
for(auto x:B)A.insert(x);
}

int get(int i){ return par[i]=( par[i]==i?i:get(par[i]) );}

bool mrg(int i,int j){
    i = get(i);j = get(j);
    if( i == j ) return 0;
    if(rand()&1)swap(i,j);
    par[i] = j;  return 1;
}

void dfs(int u,int dad){
dep[u]=1+dep[dad];
p[u][0]=dad;
for(int i=1;i<L;i++)p[u][i]=p[p[u][i-1]][i-1];
for(auto pr:adj[u]){
    int v = pr.first;
    if( v!=dad )dfs(v,u);
    }
}

int LCA(int u,int v){
if( u == v )return u;
if( dep[u]<dep[v] )swap(u,v);
int k = dep[u]-dep[v];
for(int i=0;i<L;i++)
    if( k&(1<<i) )
        u=p[u][i];
if( u == v )return u;
for(int i=L-1;i>=0;i--)
    if( p[u][i] != p[v][i] )
        u=p[u][i],v=p[v][i];
return p[u][0];
}

void dfs2(int u,int dad){
vis[u]=1;

for(auto e:adj[u]){
    int v = e.first;
    int i = e.second;
    if( v == dad )continue;
    dfs2(v,u);
    ans[i] = ( !add[v].empty() ? *add[v].begin() : 1<<30 );
    join(add[u],add[v]);
}
for(auto x:del[u])add[u].erase(x);
}


void solve(){

scanf("%d %d",&n,&q);

for(int i=1;i<=q;i++)ans[i]=1<<30;

for(int i=1;i<=n;i++){
        par[i]=i;
        dep[i]=vis[i]=0;
        adj[i].clear();
        idx[i].clear();
        add[i].clear();
        del[i].clear();
    }
tmp.clear();
ask.clear();

for(int i=1;i<=q;i++){
    int u,v,t;
    scanf("%d %d %d",&t,&u,&v);
    if( u > v )swap(u,v);

    if( t == 1 ){
            if( mrg(u,v) )
                adj[u].push_back( {v,i} ),
                adj[v].push_back( {u,i} );
            else
                tmp.push_back( { { u , v } , i } );

        idx[u][v]=i;
    }else{
            ask.push_back( {{u,v},i} );
    }
}

for(int i=1;i<=n;i++)
    if( !dep[i] )
        dfs(i,0);
for(auto e:tmp){
    int u = e.first.first;
    int v = e.first.second;
    int i = e.second;
    ans[i]=i;
    add[u].insert(i);
    add[v].insert(i);
    del[LCA(u,v)].insert(i);
}

for(int i=1;i<=n;i++)
    if( !vis[i] )
        dfs2(i,0);

for(auto e:ask){
    int u = e.first.first;
    int v = e.first.second;
    int j = e.second;
    int i = idx[u][v];
    if( ans[i]<j )printf("YES\n");
    else          printf("NO\n");
}

}

int main(){

int t;scanf("%d",&t);
while( t-- )solve();

return 0;
}
