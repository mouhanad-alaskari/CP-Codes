// C++ implementation of Dinic's Algorithm
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
// A structure to represent a edge between
// two vertex
struct Edge
{
	int v ; // Vertex v (or "to" vertex)
			// of a directed edge u-v. "From"
			// vertex u can be obtained using
			// index in adjacent array.

	ll flow ; // flow of data in edge

	ll C; // capacity

	int rev ; // To store index of reverse
			// edge in adjacency list so that
			// we can quickly find it.
};

// Residual Graph
class Graph
{
	int V; // number of vertex
	int *level ; // stores level of a node
	vector< Edge > *adj;
public :
	Graph(int V)
	{
		adj = new vector<Edge>[V];
		this->V = V;
		level = new int[V];
	}

	// add edge to the graph
	void addEdge(int u, int v, int C)
	{
		// Forward edge : 0 flow and C capacity
		Edge a{v, 0, C, adj[v].size()};

		// Back edge : 0 flow and 0 capacity
		Edge b{u, 0, 0, adj[u].size()};

		adj[u].push_back(a);
		adj[v].push_back(b); // reverse edge
	}

	bool BFS(int s, int t);
	ll sendFlow(int s, ll flow, int t, ll ptr[]);
	ll DinicMaxflow(int s, int t);
};

// Finds if more flow can be sent from s to t.
// Also assigns levels to nodes.
bool Graph::BFS(int s, int t)
{
	for (int i = 0 ; i < V ; i++)
		level[i] = -1;

	level[s] = 0; // Level of source vertex

	// Create a queue, enqueue source vertex
	// and mark source vertex as visited here
	// level[] array works as visited array also.
	list< int > q;
	q.push_back(s);

	vector<Edge>::iterator i ;
	while (!q.empty())
	{
		int u = q.front();
		q.pop_front();
		for (i = adj[u].begin(); i != adj[u].end(); i++)
		{
			Edge &e = *i;
			if (level[e.v] < 0 && e.flow < e.C)
			{
				// Level of current vertex is,
				// level of parent + 1
				level[e.v] = level[u] + 1;

				q.push_back(e.v);
			}
		}
	}

	// IF we can not reach to the sink we
	// return false else true
	return level[t] < 0 ? false : true ;
}

// A DFS based function to send flow after BFS has
// figured out that there is a possible flow and
// constructed levels. This function called multiple
// times for a single call of BFS.
// flow : Current flow send by parent function call
// start[] : To keep track of next edge to be explored.
//		 start[i] stores count of edges explored
//		 from i.
// u : Current vertex
// t : Sink
ll Graph::sendFlow(int u, ll flow, int t, ll start[])
{
	// Sink reached
	if (u == t)
		return flow;

	// Traverse all adjacent edges one -by - one.
	for ( ; start[u] < adj[u].size(); start[u]++)
	{
		// Pick next edge from adjacency list of u
		Edge &e = adj[u][start[u]];

		if (level[e.v] == level[u]+1 && e.flow < e.C)
		{
			// find minimum flow from u to t
			ll curr_flow = min(flow, e.C - e.flow);

			ll temp_flow = sendFlow(e.v, curr_flow, t, start);

			// flow is greater than zero
			if (temp_flow > 0)
			{
				// add flow to current edge
				e.flow += temp_flow;

				// subtract flow from reverse edge
				// of current edge
				adj[e.v][e.rev].flow -= temp_flow;
				return temp_flow;
			}
		}
	}

	return 0;
}

// Returns maximum flow in graph
ll Graph::DinicMaxflow(int s, int t)
{
	// Corner case
	if (s == t)
		return -1;

	ll total = 0; // Initialize result

	// Augment the flow while there is path
	// from source to sink
	while (BFS(s, t) == true)
	{
		// store how many edges are visited
		// from V { 0 to V }
		ll *start = new ll[V+1];

		// while flow is not zero in graph from S to D
		while (ll flow = sendFlow(s, (1LL<<60), t, start))

			// Add path flow to overall flow
			total += flow;
	}

	// return maximum flow
	return total;
}
int n , m ;
int main()
{
    scanf("%d%d",&n,&m);
	Graph g(n+7);
    int x , y , c ;
    for ( int i = 1 ; i <= m ;i++ ){
     scanf("%d%d%d",&x,&y,&c);
      g.addEdge(y-1,x-1,c);
      g.addEdge(x-1,y-1,c);
    }

	printf("%lld\n", g.DinicMaxflow(0,n-1));
	return 0;
}
