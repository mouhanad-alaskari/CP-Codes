#include <bits/stdc++.h>
using namespace std;
#define OO 100000000
#define ii pair < int , int >
#define F first
#define S second
typedef long long ll ;

const int N = 100100 , L = 17;
set<int>g[N];
int nn = 0, sb[N], pa[N] ;
int n , p[N][L] , dep[N] , m;
int ans[N];
void dfs(int u,int par)
{

    p[u][0]=par;
    dep[u]=1+dep[par];
    for(auto v:g[u])
        if( v !=par )
        {
            dfs(v,u);
        }

}

inline void pre()
{
	memset(p, 0, sizeof p);
	dfs(1, 0);

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

    return dep[u]+dep[v]-2*dep[LCA(u,v)];

}
void cal(int pos,int father)
{
	nn++;
	sb[pos] = 1;
	for (auto it = g[pos].begin(); it != g[pos].end();it++)
	if ( *it != father)
		cal(*it, pos), sb[pos] += sb[*it];
}
int find_centroid(int pos, int father)
{
	for (auto it = g[pos].begin(); it != g[pos].end();it++)
	if (*it != father&&sb[*it] > nn / 2)
		return find_centroid(*it, pos);
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
		g[*it].erase(cen);
		cd(*it, cen);
	}
	g[cen].clear();
}
inline void update(int pos)
{
	int x = pos;
	while (true)
	{   int dndn = dis(pos,x);
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
        int x = pos;
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
    scanf("%d", &n);
	int x , y ;
	for (int i = 2; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		g[y].insert(x);
		g[x].insert(y);
		ans[i] = ans[x] = OO;
	}
	pre();
  cd(1, -1);
	  scanf("%d",&m);
     update(1);
    for (int i = 0; i < m; i++){
            scanf("%d %d",&x,&y);
	 if ( x == 1 ) update(y);
	 else printf("%d\n",query(y));
	}

    return 0;
}
