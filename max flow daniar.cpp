#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// Input macros
#define si(n)                       scanf("%d",&n)
#define sii(a,b)                    scanf("%d%d",&a,&b)
#define sc(n)                       scanf(" %c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sll(a,b)                    scanf("%lld%lld",&a,&b)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf(" %s",n)
// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
const ll MOD = 1e9 + 7;
#define all(a)                      a.begin(), a.end()
#define lp(i,n) 					for(int i=0;i<(int)n;i++)
#define lp1(i,n)					for(int i=1;i<=(int)n;i++)
const ll LONG_INF = 1ll << 63 - 1ll;
//#ifdef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

///////////////////////////////////////////////////////////

typedef long long LL;

struct Edge {
	int u, v;
	LL cap, flow;
	Edge() {
	}
	Edge(int u, int v, LL cap) :
			u(u), v(v), cap(cap), flow(0) {
	}
};

struct Dinic {
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;

	Dinic(int N) :
			N(N), E(0), g(N), d(N), pt(N) {
	}

	void AddEdge(int u, int v, LL cap) {
		if (u != v) {
			E.emplace_back(Edge(u, v, cap));
			g[u].emplace_back(E.size() - 1);
			E.emplace_back(Edge(v, u, 0));
			g[v].emplace_back(E.size() - 1);
		}
	}

	bool BFS(int S, int T) {
		queue<int> q( { S });
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == T)
				break;
			for (int k : g[u]) {
				Edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
					d[e.v] = d[e.u] + 1;
					q.emplace(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}

	LL DFS(int u, int T, LL flow = -1) {
		if (u == T || flow == 0)
			return flow;
		for (int &i = pt[u]; i < g[u].size(); ++i) {
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i] ^ 1];
			if (d[e.v] == d[e.u] + 1) {
				LL amt = e.cap - e.flow;
				if (flow != -1 && amt > flow)
					amt = flow;
				if (LL pushed = DFS(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	LL MaxFlow(int S, int T) {
		LL total = 0;
		while (BFS(S, T)) {
			fill(pt.begin(), pt.end(), 0);
			while (LL flow = DFS(S, T))
				total += flow;
		}
		return total;
	}
};

const int N = 100005;
int u_n[N] , u_m[N];
Dinic dinic(0);
void solve(){
	int n, m, p ;
    scanf("%d%d%d",&n,&m,&p);
	int dnsz = n +m + 2;
	int src = 0;
	int dest = n+ m + 1;
	dinic = Dinic(dnsz);
    int x ,y ;
    for(int i=1;i<=p;i++){
        scanf("%d%d",&x,&y);
       if ( !u_n[x] ) dinic.AddEdge(src , x , 1);
        dinic.AddEdge(x , n+y , 1);
       if (!u_m[y]) dinic.AddEdge(y+n ,dest,1);
       u_n[x] = u_m[y] = 1 ;
    }

	ll mf = dinic.MaxFlow(src, dest);
/*        for ( auto x : dinic.E){
            cerr << x.u << "-------->" << x.v <<" CAP " << x.cap <<" FLOW  " << x.flow<<endl;
        }*/
    printf("%lld\n",mf);
}

int main() {
	solve();
    return 0;
}
