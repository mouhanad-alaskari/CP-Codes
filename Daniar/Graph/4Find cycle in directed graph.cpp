#include<bits/stdc++.h>
using namespace std;
const int N=100100;

vector<int>adj[N];
int vis[N];

bool cyc (int u)
{
    vis[u] = 1;
    for (auto v :  adj[u])
    {
        if (vis[v] == 1) return 1;
        if (vis[v] == 0 && cyc(v)) return 1 ;
    }
    vis[u] = 2;
    return 0;
}


int main()
{
    int n;
    for (int i = 1 ; i<=n ; i++)
    {
        if (vis[i] != 2)
        {
            bool f = cyc(i);
            if (f)
            {
                printf("-1");
                return 0 ;
            }
        }
    }
    return 0;
}
