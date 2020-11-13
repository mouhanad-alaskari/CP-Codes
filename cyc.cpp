bool cyc ( int u ){
 vis[u] = 1 ;
 for ( auto v :  adj[u] ){
  if ( vis[v] == 1 ){
    return 1;
  }
  if ( vis[v] == 0 && cyc(v))
    return 1 ;
 }
 vis[u] = 2 ;
 return 0 ;
}