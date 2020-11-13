#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100100;

vector<int>adj[N],SCC_NUM[N];
int ticks=1, current_scc =1;
int d[N], low[N];
bool stacked[N];
stack<int> s;

void tarjan(int u)
{
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    const vector<int> &out = adj[u];
    for(int k=0, m=out.size() ; k<m ; ++k)
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
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
    }

    memset(d,-1,sizeof d);
    memset(low,-1,sizeof low);
    for(int i = 1 ; i <= n ; i++)
    {
        if(d[i] == -1)
            tarjan(i);
    }

    for(int i = 1 ; i<current_scc ; i++)
    {
        for(auto it : SCC_NUM[i])
        {

        }
    }
    return 0;
}
