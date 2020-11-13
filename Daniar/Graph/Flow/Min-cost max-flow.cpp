// Implementation of min cost max flow algorithm using adjacency
// matrix (Edmonds and Karp 1972). This implementation keeps track of
// forward and reverse edges separately (so you can set cap[i][j] !=
// cap[j][i]). For a regular max flow, set all edge costs to 0.
//
// Running time, O(|V|ˆ2) cost per augmentation
// max flow: O(|V|ˆ3) augmentations
// min cost max flow: O(|V|ˆ4 * MAX_EDGE_COST) augmentations
//
// INPUT:
// - graph, constructed using AddEdge()
// - source
// - sink
//
// OUTPUT:
// - (maximum flow value, minimum cost value)
// - To obtain the actual flow, look at positive values only.

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
const L INF = numeric_limits<L>::max()/ 4;
struct MinCostMaxFlow
{
    int N;
    VVL cap, flow, cost;
    VI found;
    VL dist, pi, width;
    VPII dad;
    MinCostMaxFlow(int N) :
        N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
        found(N), dist(N), pi(N), width(N), dad(N) {}
    void AddEdge(int from, int to, L cap, L cost)
    {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
    }
    void Relax(int s, int k, L cap, L cost, int dir)
    {
        L val = dist[s] + pi[s] - pi[k] + cost;
        if (cap && val < dist[k])
        {
            dist[k] = val;
            dad[k] = make_pair(s, dir);
            width[k] = min(cap, width[s]);
        }
    }
    L Dijkstra(int s, int t)
    {
        fill(found.begin(), found.end(), false);
        fill(dist.begin(), dist.end(), INF);
        fill(width.begin(), width.end(), 0);
        dist[s] = 0;
        width[s] = INF;
        while (s != -1)
        {
            int best = -1;
            found[s] = true;
            for (int k = 0; k < N; k++)
            {
                if (found[k]) continue;
                Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
                Relax(s, k, flow[k][s], -cost[k][s], -1);
                if (best == -1 || dist[k] < dist[best]) best = k;
            }
            s= best;
        }
        for (int k = 0; k < N; k++)
            pi[k] = min(pi[k] + dist[k], INF);
        return width[t];
    }
    pair<L, L> GetMaxFlow(int s, int t)
    {
        L totflow = 0, totcost = 0;
        while (L amt = Dijkstra(s, t))
        {
            totflow += amt;
            for (int x = t; x != s; x = dad[x].first)
            {
                if (dad[x].second == 1)
                {
                    flow[dad[x].first][x] += amt;
                    totcost += amt * cost[dad[x].first][x];
                }
                else
                {
                    flow[x][dad[x].first] -= amt;
                    totcost -= amt * cost[x][dad[x].first];
                }
            }
        }
        return make_pair(totflow, totcost);
    }
};
// BEGIN CUT
// The following code solves UVA problem #10594: Data Flow
int sum[155];
int main()
{
    int N;
    scanf("%d", &N ) ;

        VVL v(N, VL(N));
        for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%Ld", &v[i][j]);
       int sz = N+N+2 ;
        MinCostMaxFlow mcmf(sz);
        for (int j = 0; j < N; j++)
        {
            for  (int i =0 ; i < N ; i++ ){
               sum[j] += v[j][i] ;
            }
        }for (int j = 0; j < N; j++)
        {
            mcmf.AddEdge(0,j+1,1,0);
            int cost = sum[j] ;
            for  (int i =0 ; i < N ; i++ ){
                cost -= v[j][i] ;
                mcmf.AddEdge(j+1,i+1+N,1,cost);
                cost += v[j][i];
            }
            mcmf.AddEdge(N+j+1,N+N+1,1,0);
        }

        pair<L, L> res = mcmf.GetMaxFlow(0, N+N+1);

            printf("%Ld\n", res.second);



    return 0;
}
// END CUT
