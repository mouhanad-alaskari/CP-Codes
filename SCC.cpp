#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100100;
const ll mod = 1e9+7;
int n,m,in[N],out[N];
int a[N],id,cnt=1;
vector<int>adj[N] , ADJ[N];
vector<int>SCC[N];
ll c[N] , ans , ways=1 ;
bool vis[N];

void dfs(int ver){
vis[ver]=1;
in[ver]=cnt++;
for(auto nxt:adj[ver])if(!vis[nxt])dfs(nxt);
out[ver]=cnt++;
}

bool cmp(int x,int y){ return out[x]>out[y]; }

void DFS(int ver,int id){
vis[ver]=1;
SCC[id].push_back(ver);
for(auto nxt:ADJ[ver])if(!vis[nxt])DFS(nxt,id);
}

int main()
{
cin>>n;
for(int i=1;i<=n;i++){cin>>c[i];a[i]=i;}
cin>>m;
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    ADJ[v].push_back(u);
}
for(int i=1;i<=n;i++)
    if( !vis[i] )
    dfs(i);

sort(a+1,a+1+n,cmp);
memset(vis,0,sizeof vis);

for(int i=1;i<=n;i++)
    if(!vis[a[i]])
    DFS(a[i],id++);

for(int i=0;i<id;i++){
ll mn=1ll<<40 , cnt=0;
for(auto ver:SCC[i]){
         if( c[ver] <  mn ){mn=c[ver],cnt=1;}
    else if( c[ver] == mn )cnt++;
}
ans+=mn;
ways*=cnt;
ways%=mod;
}

cout<<ans<<" "<<ways<<endl;
    return 0;
}





#include<bits/stdc++.h>
#include <list>
#include <stack>
#define NIL -1
using namespace std;
typedef long long ll ;
ll md = 1000000000+7 ;
const int MX = 400000 ;
vector<int> g[MX],SCC_NUM[MX];
int n;
ll same[MX], prdct = 1ll, sm, cost[MX];
int d[MX], low[MX] ;
bool stacked[MX];
stack<int> s;
int ticks = 1, current_scc = 1 ;
void tarjan(int u)
{
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    const vector<int> &out = g[u];
    for (int k=0, m=out.size(); k<m; ++k)
    {
        const int &v = out[k];
        if (d[v] == -1)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (stacked[v])
            low[u] = min(low[u], low[v]);
    }
    if (d[u] == low[u])
    {
        int v;
        do
        {
            v = s.top();
            s.pop();
            stacked[v] = false;
            SCC_NUM[current_scc].push_back(v) ;
        }
        while (u != v);
        current_scc++;
    }
}
int main()
{
    memset(d,-1,sizeof d) ;
    memset(low,-1,sizeof low) ;
    int a, b, m ;
    cin>>n ;
    for( int i = 1; i <= n ; ++i )
        cin>>cost[i] ;
    cin>>m;
    while(m--)
    {
        cin>>a>>b ;
        g[a].push_back(b) ;
    }
    for( int i = 1 ; i <= n ; ++i )
        if( d[i] == -1 )tarjan(i) ;

//    for( int i = 1 ; i <= n ; ++i )
//    {
//        cout<<i<<" belong to "<<SCC_NUM[i]<<"\n";
//    }
    for( int i = 1 ; i< current_scc ; ++i )
    {
        ll mn = 1e18, same = 0 ;
        for( auto it : SCC_NUM[i] )
        {
            if( cost[it] == mn )same++ ;
            else if( cost[it] < mn )
            {
                same = 1 ;
                mn = cost[it] ;
            }
        }
        sm+=mn ;
        prdct*=same ;
        prdct%=md ;
    }
    cout<<sm<<" "<<prdct<<"\n";
    return 0;
}