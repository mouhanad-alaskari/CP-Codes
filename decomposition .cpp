#include <bits/stdc++.h>
using namespace std;
#define OO 100000000000000000
#define ii pair < int , int >
#define F first
#define S second
typedef long long ll ;

const int N = 100100 , L = 17;
set<ii>g[N];
int nn = 0, sb[N], pa[N] ;
int n , p[N][L] , dep[N] , m;
ll cost[N]  , ans[N];
struct tt {
int v , u , id ;
};
tt Q[N];
ll ANS [N];
bool cmp ( tt a , tt b ){
return a.v < b.v ;
}

void dfs(int u,int par,ll c)
{

    p[u][0]=par;
    dep[u]=1+dep[par];
    cost[u] = c ;
    for(auto v:g[u])
        if( v.F !=par )
        {
            dfs(v.F,u,c+v.S);
        }

}

inline void pre()
{
	memset(p, 0, sizeof p);
	dfs(1, 0 , 0LL);

         for(int j=1 ; j<L ; j++)
            for(int i=1 ; i<=n ; i++)
                p[i][j]=p[ p[i][j-1] ][j-1];


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

ll dis(int u,int v)
{

    return cost[u]+cost[v]-2*cost[LCA(u,v)];

}
void cal(int pos,int father)
{
	nn++;
	sb[pos] = 1;
	for (auto it = g[pos].begin(); it != g[pos].end();it++)
	if ((*it).F != father)
		cal((*it).F, pos), sb[pos] += sb[(*it).F];
}
int find_centroid(int pos, int father)
{
	for (auto it = g[pos].begin(); it != g[pos].end();it++)
	if ((*it).F != father&&sb[(*it).F] > nn / 2)
		return find_centroid((*it).F, pos);
	return pos;
}
void cd(int pos, int root)
{
	nn = 0;
	cal(pos, pos);
	int cen = find_centroid(pos, pos);
	int p = root;
	if (p == -1)p = cen;
	pa[cen] = p;
	for (auto it = g[cen].begin(); it != g[cen].end(); it++)
	{
		g[(*it).F].erase(g[(*it).F].lower_bound({cen,-8}));
		cd((*it).F, cen);
	}
	g[cen].clear();
}
inline void update1(int pos)
{
	int x = pos;
	while (true)
	{   ll dndn = dis(pos,x);
		//if ( pos == 3 ) cerr << x <<" " << dndn <<endl;
		ans[x] = min(ans[x], dndn);
		if (pa[x] == x)break;
		x = pa[x];
	}
}

inline void del(int pos)
{
	int x = pos;
	while (true)
	{
	    ans[x] = OO ;
		if (pa[x] == x)break;
		x = pa[x];
	}
}
inline ll query(int pos)
{
int 	x = pos;
	ll ra = OO;
	while (true)
	{
		ra = min(ra, ans[x] + dis(pos, x));
		if (x == pa[x])return ra;
		x = pa[x];
	}
}
int main()
{
    while ( 1 ){
	scanf("%d", &n);
	if ( n == 0 ) break;
	int x , y ;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		x++;
		g[i].insert({x,y});
		g[x].insert({i,y});
		ans[i] = ans[x] = OO;
	}
	pre();
  cd(1, -1);
	  scanf("%d",&m);
        for ( int i = 0 ; i < m; i++ ){
            scanf("%d %d",&x,&y);
    if ( x > y ) swap(x,y);
            Q[i].v = ++x ;
            Q[i].u = ++y ;
            Q[i].id = i ;
        }
        sort(Q,Q+m,cmp);
	int last = -1 ;
	for (int i = 0; i < m; i++){
        if ( Q[i].v != last ){
        if ( last != -1 ) del(last);
         update1(Q[i].v);
          last = Q[i].v ;
          }

       ANS[Q[i].id] = query(Q[i].u);
	}
	for ( int i = 0 ; i < m ; i++ )
        printf("%lld%c",ANS[i],(i==m-1?'\n':' '));
     for ( int i = 1 ; i <= n ;i++ ) g[i].clear();

    }
	return 0;
}
