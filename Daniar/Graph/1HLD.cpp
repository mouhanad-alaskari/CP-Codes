int chainNo=0,chainHead[N],chainPos[N],chainInd[N],chainSize[N];
void hld(int u , int par = 0)
{
    if(chainHead[chainNo] == -1) chainHead[chainNo]= u;
    chainInd[u] = chainNo;
    chainPos[u] = chainSize[chainNo];
    chainSize[chainNo]++;

    int  mx = -1 , mai = -1 ;
    for( auto v : adj[u] )
    {
        if ( v == par ) continue ;
        if( sz[ v ] > mai)
        {
            mai = sz[ v ];
            mx = v;
        }
    }

    if( mx >= 0) hld( mx , u );

    for(auto v : adj[u] )
    {
        if(mx != v)
        {
            chainNo++;
            hld( v , u );
        }
    }
}


int query_up(int u, int v)
{
    if(u == v) return 0; // Trivial
    int uchain, vchain = chainInd[v], ans = -1;
    // uchain and vchain are chain numbers of u and v
    while(1)
    {
        uchain = chainInd[u];
        if(uchain == vchain)
        {
            // Both u and v are in the same chain, so we need to query from u to v, update answer and break.
            // We break because we came from u up till v, we are done
            if(u==v) break;
            query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
            // Above is call to segment tree query function
            if(qt[1] > ans) ans = qt[1]; // Update answer
            break;
        }
        query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
        // Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
        // start till head. We then update the answer
        if(qt[1] > ans) ans = qt[1];
        u = chainHead[uchain]; // move u to u's chainHead
        u = pa[0][u]; //Then move to its parent, that means we changed chains
    }
    return ans;
}

void HLD(int curNode, int cost, int prev)
{
    if(chainHead[chainNo] == -1)
    {
        chainHead[chainNo] = curNode; // Assign chain head
    }
    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
    baseArray[ptr++] = cost;

    int sc = -1, ncost;
    // Loop to find special child
    for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev)
        {
            if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]])
            {
                sc = adj[curNode][i];
                ncost = costs[curNode][i];
            }
        }

    if(sc != -1)
    {
        // Expand the chain
        HLD(sc, ncost, curNode);
    }

    for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev)
        {
            if(sc != adj[curNode][i])
            {
                // New chains at each normal node
                chainNo++;
                HLD(adj[curNode][i], costs[curNode][i], curNode);
            }
        }
}

void query(int u, int v)
{
    /*
     * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
     */
    int lca = LCA(u, v);
    int ans = query_up(u, lca); // One part of path
    int temp = query_up(v, lca); // another part of path
    if(temp > ans) ans = temp; // take the maximum of both paths
    printf("%d\n", ans);
}
void change(int i, int val)
{
    int u = otherEnd[i];
    update_tree(1, 0, ptr, posInBase[u], val);
}
