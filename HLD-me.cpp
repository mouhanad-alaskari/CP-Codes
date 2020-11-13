/**
*
* Author: Mouhanad
* Lang: GNU C++14
*
**/
// this solution for problem https://www.spoj.com/problems/QTREE/
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >
typedef long long ll;
const int inf = 1<<30;
const int N = 10100 , L = 17;
int n , p[N][L] , dep[N] , seg[N<<2];
int sz[N] , timer= 1;
struct tt {
int v , c, id ;
 tt ( int x , int y , int z ){
   v = x , c = y , id = z ;
 }
};
vector<tt>adj[N] ;
int baseArray[N] , idx[N];
int chainNo, chainInd[N], chainHead[N], posInBase[N];

void build(int nd,int L,int R){
    if( L == R ){
        seg[nd]= baseArray[L];
        return ;
    }
    int mid = (L+R) >>1;
    build(nd<<1  ,L , mid);
    build(nd<<1|1,mid+1,R);
    seg[nd]=max( seg[nd<<1] , seg[nd<<1|1] );
}

void dfs(int u,int par = 0)
{   p[u][0]=par;
    dep[u]=1+dep[par];
    sz[u]=1;
    for(auto v:adj[u])
        if( v.v!=par )
        {
             dfs(v.v,u);
             idx[v.id] = v.v ;
            sz[u]+=sz[v.v];
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
void HLD(int u , int c = 0 , int par = 0 ) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = u;
	}
	chainInd[u] = chainNo;
	posInBase[u] = timer;
	baseArray[timer++] = c;

	int sc = -1, ncost;
	for( auto v : adj[u] )
        if( v.v  != par ) {
		if(sc == -1 || sz[sc] < sz[v.v]) {
			sc = v.v;
			ncost = v.c;
		}
	}

	if(sc != -1) {
		HLD(sc, ncost, u);
	}

	for( auto v : adj[u] )
        if( v.v != par ) {
		if(sc != v.v ) {
			chainNo++;
			HLD(v.v, v.c, u);
		}
	}
}

void update(int nd,int L,int R,int idx,int val){
    if( L == R ){
        seg[nd]=val;
        return ;
    }
    int mid = (L+R) >>1;
    if( idx<=mid )
         update(nd<<1  ,  L  ,mid,idx,val);
    else update(nd<<1|1,mid+1, R ,idx,val);
    seg[nd]=max( seg[nd<<1] , seg[nd<<1|1] );
}

int query(int nd,int L,int R,int from,int to){
//    push(nd,L,R);

    if( from<=L && R<=to )return seg[nd];
    if( from>R || to<L )return 0;

    int mid = (L+R) >>1;

    int leftAns = query(nd<<1  ,  L  ,mid,from,to);
    int rightAns= query(nd<<1|1,mid+1, R ,from,to);
    return max( leftAns ,rightAns );
}

int query_up(int u, int v) {
	if(u == v) return 0;       /// comment this when u ar working on nodes
	int uchain, vchain = chainInd[v],ANS = -1;
	while(1) {
		uchain = chainInd[u];
		if(uchain == vchain) {
			if(u==v) break;       /// comment this when u ar working on nodes
			ANS = max ( ANS  , query(1, 1, timer, posInBase[v]+1, posInBase[u]));  /// posInBase[v] when u are working on nodes

			break;
		}
		ANS = max ( ANS , query (1, 1, timer, posInBase[chainHead[uchain]], posInBase[u]));

		u = chainHead[uchain];
		u = p[u][0];
	}
	return ANS;
}
void query(int u, int v) {
	/*
	 * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
	 */
	int lca = LCA(u, v);
	int ANS = query_up(u, lca); // One part of path
	int temp = query_up(v, lca); // another part of path
	if(temp > ANS) ANS = temp; // take the maximum of both paths
	printf("%d\n", ANS);
}
void change(int i, int val) {
	int i = idx[i];                         /// comment this when u are working on nodes
	update(1, 1, timer, posInBase[i], val);
}
void init(){
 memset( chainHead , -1, sizeof chainHead );
 timer = 1 ;
 chainNo = 0;
}
void solve()  {
    init();
   scanf("%d",&n);
   for ( int i = 1 ; i <= n-1 ; i++  ){
     int x , y , c ;
     scanf("%d %d %d",&x,&y,&c);
     adj[x].push_back(tt(y,c,i));
     adj[y].push_back(tt(x,c,i));
   }

   dfs(1);
   HLD(1);
   timer--;
   build(1,1,timer);

       for(int j=1; j<L; j++)
        for(int i=1; i<=n; i++)
            p[i][j]=p[ p[i][j-1] ][j-1];

   char al[22] ;

    while  (1){
   scanf("%s",al);
   if ( al[0] == 'D') break;
   int x , y ;
   scanf("%d %d",&x,&y);
   if ( al[0] == 'Q') {
        query(x,y);
   }else {
        change(x,y);
   }
}
for  (int i = 1 ; i <= n; i++ ) adj[i].clear();
return ;
}

int main()
{
    int t ;
    scanf("%d",&t);
    while ( t-- ){
        solve();
    }
    return 0;
}
