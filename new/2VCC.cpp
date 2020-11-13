/*
notes :
when update a cut node updates her and her parent .
when calc value for a 2VCC component don't use parent value .
if ( u == v ) ans dirctly .
when 2VCC[v] == 2VCC[u] ANS dirctly. 

*/


#include<bits/stdc++.h>
 
 
using namespace std;
using ii = pair < int , int >;
 
 
const int N   = 5e5 + 5;
const int INF = 2e9;
 
vector < int > adj[N];
 
vector < int > Tree[N];///bi-connected component tree
 
///it's a set because there are duplicates
set < int > BCC[N];///contains the bi-connected components
 
///maybe here a vector will work
set < int > belong[N];///witch components this node belongs to,
///if it's not cut point then it belongs to just one component.
 
vector < ii > edges_stack;
 
int low[N] , dfn[N];
int timer = 0 , bcc_count = 0;
bool cut[N];///for cut points
bool is_node[N];///after mapping each component with a number larger than n
///we sometimes need to know if this number refers to some component or not
 
int n , m;
 
 
int code(int x){
    return x + n + 1;
}
 
int decode(int x){
    return x - n - 1;
}
 
void make_bcc(int u , int v){
    ii E = make_pair(u , v);
 
    if((int)edges_stack.size() > 0)bcc_count ++;
 
    while( !edges_stack.empty() ){
        ii E2 = edges_stack.back(); edges_stack.pop_back();
 
        int x = E2.first;
        int y = E2.second;
 
        BCC[bcc_count].insert(x);
        BCC[bcc_count].insert(y);
 
        belong[x].insert(bcc_count);
        belong[y].insert(bcc_count);
 
        if(E2 == E)break;
    }
}
 
void tarjan_BCC(int u , int p){
    low[u] = dfn[u] = ++ timer;
    int children = 0;
 
    for(int v : adj[u]){
        if(v == p)continue;
 
        if(dfn[v] == 0){
            children ++;
            edges_stack.push_back({u , v});
 
            tarjan_BCC(v , u);
 
            low[u] = min(low[u] , low[v]);
 
            if( ((p == -1) && (children > 1) ) || ( (p != -1) && (dfn[u] <= low[v]) ) ){
                cout << u << " -> " << v << " " << children << endl;
                cut[u] = 1;
                make_bcc(u , v);
            }
 
        }
        else if(v != p){
            if(dfn[v] < low[u]){
                low[u] = dfn[v];
                edges_stack.push_back({u , v});
            }
        }
 
    }
}
 
 
void build_BCC_Tree(){
 
    for(int i = 1 ; i <= n ; i ++){
        if(cut[i]){
 
            is_node[i] = true;
 
            for(int b : belong[i]){
 
                int node = code(b);
                is_node[node] = true;
 
                Tree[node].push_back(i);
                Tree[i]   .push_back(node);
 
            }
        }
    }
 
}
 
void solve(int cs){
    scanf("%d %d" , &n , &m);
 
    for(int i = 0 ; i < m ; i ++){
        int u , v;
        scanf("%d %d" , &u , &v);
 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for(int i = 1 ; i <= n ; i ++){
        if(!dfn[i]){
            tarjan_BCC(i , -1);
            make_bcc(-1 , -1);
        }
    }
 
    cout << endl;
    cout << "Case " << cs << ":\n";
    cout << "bi-connected components:\n";
    for(int i = 1 ; i <= bcc_count ; i ++){
        cout << "BCC " << i << ":";
        for(int node : BCC[i])cout << " " << node;
        cout << endl;
    }
    cout << endl;
 
    cout << "components that each node belongs to:\n";
 
    for(int i = 1 ; i <= n ; i ++){
        cout << "node " << i << " belongs to:";
        for(int comp : belong[i])cout << " " << comp;
        cout << endl;
    }
    cout << endl;
}
 
void init(){
 
    timer = 0 , bcc_count = 0;
    for(int i = 1 ; i <= 3*n ; i ++){
        adj[i].clear();
        cut[i] = 0;
        Tree[i].clear();
        belong[i].clear();
        BCC[i].clear();
        low[i] = dfn[i] = 0;
        is_node[i] = 0;
    }
}
 
main(){
 
    int t = 1;
    scanf("%d" , &t);
 
    for(int cs = 1 ; t -- ; cs ++){
        solve(cs);
        init();
    }
 
    return 0;
}