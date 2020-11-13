

/**
*
* Author: MARC
* Lang: GNU C++14
*
**/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >

typedef unsigned long long ull;
typedef long double ldbl;
typedef long long ll;
typedef double dbl;

const ldbl pi = 3.1415926535897932385;
const ldbl E = 2.71828182845904523536;
const dbl eps = 1e-9;
const ll mod = 1e9+7;
const ll inf = 1<<30;

/** /////////// ** Code ** /////////// **/

const int N=500500 , L=20;
vector<int>adj[N];
int a[N] , dep[N] , f[N] , ans[N];
ll cost[N][L] , p[N][L] ;
map<ii,int>mp;

void DFS1(int u,int par){
    p[u][0]=par;
    dep[u]=1+dep[par];
    cost[u][0]=mp[{u,par}];
    for(auto v:adj[u]) if(v != par) DFS1(v,u);
}

void jump(int u){
    int v=u , c=a[u];
    for(int i=L-1 ; i>=0 ; i--){
        if(cost[u][i] <= c){
            c-=cost[u][i];
            u=p[u][i];
        }
    }


    if(v != u){
        if(!u) u=1;
        f[v] += 1;
        f[u] -= 1;
    }

}


int DFS2(int u,int p){
    for(auto v:adj[u]) if(v != p )DFS2(v,u);
    for(auto v:adj[u]) if(v != p) ans[u]+=(ans[v]+f[v]);
}

int main()
{
    freopen("car.in" , "r" , stdin );
    int T; scanf("%d",&T);
    while(T--){

        memset(a,0,sizeof a);
        memset(dep,0,sizeof dep);
        memset(f,0,sizeof f);
        memset(ans,0,sizeof ans);
        memset(cost,0,sizeof cost);
        memset(p,0,sizeof p);

        mp.clear();
        for(int i=0 ; i<N-1 ; i++) adj[i].clear();

        int n; scanf("%d",&n);
        for(int i=1 ; i<=n ; i++) scanf("%d",&a[i]);
        for(int i=0 ; i<n-1 ; i++){
            int a1,b1,c1;
            scanf("%d%d%d",&a1,&b1,&c1);
            adj[a1].push_back(b1);
            adj[b1].push_back(a1);
            mp[{a1,b1}]=c1;
            mp[{b1,a1}]=c1;
        }

        DFS1(1,0);

        for(int j=1 ; j<L ; j++)
            for(int i=1 ; i<=n ; i++)
                p[i][j]=p[ p[i][j-1] ][j-1];

        for(int j=1 ; j<L ; j++)
            for(int i=1 ; i<=n ; i++)
                cost[i][j] = cost[ p[i][j-1] ][j-1] + cost[i][j-1];

        for(int i=2 ; i<=n ; i++) jump(i);


        DFS2(1,0);

        for(int i=1 ; i<=n ; i++) printf("%d%c",ans[i],i<n?' ':'\n');


    }

    return 0;
}






#include <bits/stdc++.h>
#define MEM(dp,i) memset(dp,i,sizeof(dp))
#define R return
#define F first
#define S second
#define C continue
#define pb push_back
#define PI 3.14159265
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=(1ll<<60);
const int MX=1e4+9;
const ll mod=1e9+7;
int n,q;
bool vis[MX];
vector<pll>v[MX];
ll dp[30][MX],par[30][MX],lvl[MX];
void dfs(int x,int p=-1){
    if(vis[x])R;
    vis[x]=1;
    for(auto pp:v[x]){
        int nxt=pp.F;
        ll c=pp.S;
        if(nxt==p)C;
        lvl[nxt]=lvl[x]+1;
        dp[0][nxt]=c;
        par[0][nxt]=x;
        dfs(nxt,x);
    }
}
ll dis(ll x,ll y){
    ll ret=0;
    if(lvl[x]<lvl[y])swap(x,y);
    for(int i=29;i>=0;i--){
        ll a=par[i][x];
        if(lvl[a]<lvl[y])C;
        ret+=dp[i][x];
        x=a;
    }
    R ret;
}
void build(){
    for(int i=1;i<30;i++){
        for(int j=1;j<=n;j++){
            ll x=par[i-1][j];
            ll c=dp[i-1][j];
            par[i][j]=par[i-1][x];
            dp[i][j]=dp[i-1][x]+dp[i-1][j];
        }
    }
}
int main(){
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    lvl[1]=1;
    dfs(1);
    build();
    while(q--){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",dis(a,b));
    }
}



//// sparc table in array
/**
*
* Author: Mouhanad
* Lang: GNU C++14
*
**/
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >
typedef long long ll;
const int inf = 1<<30 , L = 22;
const int N =300100;
int n , a[N];
int gcd[N][L];
int mn[N][L];
ll Gcd(ll x, ll y){
    if(x <= 0)return y;
    if(y <= 0)return x;
    if(x%y == 0)
        return y;
    return Gcd(y,x%y);
}
void add(){
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j < 20 ; j++)
            gcd[i][j] = -1;
    }
    for(int i= 1; i<=n ; i++){
        gcd[i][0] = a[i];
    }

    for(int j=1; (1<<j) <=n ; j++){
        for(int i=1 ; i <= n ; i++){
            if(i + (1<<(j-1)) >= n+1)continue;
            gcd[i][j] = Gcd(gcd[i][j-1],gcd[i + (1<<(j-1))][j-1]);
        }
    }
}
void add1(){

    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j <20 ; j++)
            mn[i][j] = inf;
    }
    for(int i=1; i<=n ;i ++){
        mn[i][0] = a[i];
    }

    for(int j=1 ; 1<<j <= n ; j++){
        for(int i=1; i <= n; i++){
            if(i + (1<<(j-1)) >= n+1)continue;
            mn[i][j] = min(mn[i][j-1],mn[i + (1<<(j-1))][j-1]);
        }
    }

}

int calc1(int a,int b){
    int l = b-a + 1;
    int k = log2(l);
    return Gcd(gcd[a][k],gcd[a + l - (1<<k)][k]);
}

int calc2(int a,int b){
    int l = b-a + 1;
    int k = log2(l);
    return min(mn[a][k],mn[a + l - (1<<k)][k]);
}
int main(){
   scanf("%d",&n);
   memset( mn , 1111 , sizeof mn );
   for ( int i = 1 ; i <=  n; i++)  {
        scanf("%d",a+i);
   }
   add();
   add1();

