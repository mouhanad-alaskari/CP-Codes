#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < ll , ll >
typedef long long ll;

const ll inf = 1LL<<60;

const int N=10010 , M=1000100;
vector<pair<int,ii>>adj[N];
bool prime[M];
vector<int>pr;

ll dis[N][111];

void dij(int s,int kk)
{
    priority_queue< pair<ll,ii> , vector <pair<ll,ii>> , greater <pair<ll,ii>> > pq ;
    pq.push({0 , {s,kk} });

    while(pq.size())
    {
        ll c = pq.top().F;
        int v = pq.top().S.F ;
        int k = pq.top().S.S ;
        pq.pop();

        if(dis[v][k] != c) continue;

        for( auto x : adj[v] )
        {
            if ( dis[v][k] + x.S.F < dis[x.F][k] )
            {
                dis[x.F][k]  = dis[v][k] + x.S.F ;
                pq.push({dis[x.F][k],{x.F,k}});
            }

            if(k <= 0) continue;

            if ( dis[v][k] + x.S.S < dis[x.F][k-1] )
            {
                dis[x.F][k-1]  = dis[v][k] + x.S.S ;
                pq.push({dis[x.F][k-1],{x.F,k-1}});
            }
        }
    }
}


int main()
{

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        int bw=w , x=w;

        for(int i=0 ; i<pr.size() ; i++)
        {
            if(pr[i]*pr[i] > x) break;
            if(prime[x]) break;

            bool f=0;
            while(x%pr[i] == 0)
            {
                f=1;
                x/=pr[i];
            }

            if(f) bw=min(bw,w/pr[i]+2*pr[i]);

        }

        if(x > 1) bw=min(bw,w/x+2*x);

        adj[u].push_back({v,{w,bw}});
        adj[v].push_back({u,{w,bw}});
    }


    for(int i=0 ; i<N ; i++)
        for(int j=0 ; j<111 ; j++)
            dis[i][j]=inf;


    int s,d;
    scanf("%d%d",&s,&d);

    dis[s][k]=0;
    dij(s,k);

    ll ans=inf;
    for(int i=0 ; i<111 ; i++)
    {
        ans=min(ans,dis[d][i]);
    }

    if(ans >= inf) printf("-1\n");
    else printf("%lld\n",ans);

    for(int i=0 ; i<N ; i++)
        adj[i].clear();
}
