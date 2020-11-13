int cnt[N], sz[N] , col[N];
bool big[N];
void add(int u, int p, int x){
    cnt[ col[u] ] += x;
    for(auto v: adj[u])
        if(v != p && !big[v])
            add(v, u, x);
}
void dfs(int u, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto v : adj[u])
       if(v != p && sz[v] > mx)
          mx = sz[v], bigChild = v;
    for(auto v : adj[u])
        if(v != p && v != bigChild)
            dfs(v, u, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        dfs(bigChild, u, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt
    add(u, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(u, p, -1);
}