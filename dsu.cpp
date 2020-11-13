int n , m , k , p[N] , comp ;

int Par(int i){ return p[i]=( i==p[i] )?i:Par(p[i]); }
bool same(int i,int j){ return Par(i)==Par(j); }

void mrg(int i,int j){
if(same(i,j))return;
i=Par(i);j=Par(j);
if( rand()&1 )swap(i,j);
p[i]=p[j];
comp --;
}

vector<int>adj[N];
vector<int>ADJ[N];
vector<pair<int,int>>bridges;
int low[N] , num[N] , p[N] ;
int n , m , x , y , cnt , timer ;

void dfs(int u,int pr){
num[u]=low[u]=++timer;
for(auto v:adj[u])if( v!=pr ){
if( num[v]==-1 )dfs(v,u);
if( low[u]<low[v] )bridges.push_back({u,v});
else mrg(u,v);
low[u]=min(low[u],low[v]);
}
}
 