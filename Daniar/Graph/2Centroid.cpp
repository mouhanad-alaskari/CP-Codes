// spoj Query on a tree V
#include<bits/stdc++.h>
using namespace std;

#define N 100005
#define OO N*7
#define ii pair < int , int >
#define F first
#define S second
set<int>g[N];

int n, m, res, dp[N][32], x, y, z, f[N], l[N], nn = 0, sb[N], pa[N], ans[N];

bool col[N];
bool vis[N];
set < ii > tony[N];
multiset < int > se[N];

void dfs(int pos, int le, int fa)
{
    vis[pos] = true;
    f[pos] = fa;
    l[pos] = le;
    for (auto it = g[pos].begin(); it != g[pos].end(); it++)
        if (!vis[*it])
            dfs(*it, le + 1, pos);
}
inline void pre()
{
    memset(dp, -1, sizeof dp);
    dfs(1, 1, 1);
    for (int i = 1; i <= n; i++)
        dp[i][0] = f[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
inline int lca(int ff, int ss)
{
    int high = ff, low = ss,lg=0;
    if (l[high] > l[low])
        swap(low, high);
    for (; (1 << lg) <= n; lg++);
    lg--;
    for (int i = lg; i >= 0; i--)
        if (l[low]-(1<<i) >= l[high])
            low = dp[low][i];
    if (low == high)
        return high;
    for (int i = lg; i >= 0; i--)
        if (dp[high][i]!=-1&&dp[low][i] != -1 && dp[high][i] != dp[low][i])
            high = dp[high][i], low = dp[low][i];
    return f[low];
}
inline int dis(int ff, int ss)
{
    return l[ff] + l[ss] - l[lca(ff, ss)] * 2;
}
void cal(int pos,int father)
{
    nn++;
    sb[pos] = 1;
    for (auto it = g[pos].begin(); it != g[pos].end(); it++)
        if (*it != father)
            cal(*it, pos), sb[pos] += sb[*it];
}
int find_centroid(int pos, int father)
{
    for (auto it = g[pos].begin(); it != g[pos].end(); it++)
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
inline void update1(int pos)
{
    x = pos;
    while (true)
    {
        int dndn = dis(pos,x);
        ans[x] = min(ans[x], dndn);
        tony[x].insert({pos,dndn});
        se[x].insert(dndn);
        if (pa[x] == x)break;
        x = pa[x];
    }
}
inline void update2(int pos)
{
    x = pos;
    while (true)
    {
        auto mars = tony[x].lower_bound({pos,-1});
        if  ( mars != tony[x].end())
        {
            se[x].erase(se[x].find((*mars).S));
            tony[x].erase(mars);
        }
        if ( se[x].size() == 0 ) ans[x] = OO ;
        else ans[x] = *se[x].begin();
        if (pa[x] == x)break;
        x = pa[x];
    }
}
inline int query(int pos)
{
    x = pos;
    int ra = OO;
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
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        g[x].insert(y);
        g[y].insert(x);
        ans[x] = ans[y] = OO;
    }
    pre();
    cd(1, -1);
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &y, &z);
        if (y == 0)
        {
            if ( !col[z] )
            {
                col[z] = 1- col[z] ;
                update1(z);
            }
            else
            {
                col[z] = 1- col[z] ;
                update2(z);
            }
        }
        else
        {
            res = query(z);
            if ( res == OO ) res = -1 ;
            printf("%d\n", res);
        }
    }
    return 0;
}
