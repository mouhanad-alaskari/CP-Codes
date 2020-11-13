///////////////////////////////////////////////////////////////////////////////////
// Given an array a[1 … N] of different integer numbers,
// your program must answer a series of questions Q(i, j, k) in the form:
// “What would be the k-th number in a[i … j] segment, if this segment was sorted?
// Solution:
// Let us assume we have a segment tree for all N * N ranges.
// That is for each i, j such that 1 <= i <= j <= N we have a segment tree ready to be used.
// In this case we can answer the query in O( log N ) which is what we need to do.
// But building those segment trees will take O(N*N*N) time and memory.
// Like in previous problem let me concentrate on reducing memory which will in turn reduce time complexity.
// #Trick 1 : In segment tree for range (i, j) each node can be calculated from respective nodes in segment tree for range (1, i-1) and range (1, j).
// That is for each node in segment tree for range (i, j) :
// node for (i, j) = node for (1, j) – node for (1, i-1). Awesome. We only need O(N) segment trees now.
// One segment tree for each of the prefixes. (This trick works only because all input values are distinct,
// see why it wont work in other case)
// #Trick 2 : Segment tree for prefix i is almost same as segment tree for prefix i-1,
// except some O( log N ) nodes that will change. So once again we can reduce the memory to O( N * log N ).
///////////////////////////////////////////////////////////////////////////////////

/// code

#include<bits/stdc++.h>
using namespace std;

#define sz size()
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)

#define N 111111

struct node
{
    int count;
    node *left, *right;

    node(int count, node *left, node *right):
        count(count), left(left), right(right) {}

    node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL); //see line 135

node * node::insert(int l, int r, int w)
{
    if(l <= w && w < r)
    {
        // With in the range, we need a new node
        if(l+1 == r)
        {
            return new node(this->count+1, null, null);
        }

        int m = (l+r)>>1;

        return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
    }

    // Out of range, we can use previous tree node.
    return this;
}



int query(node *a, node *b, int l, int r, int k)
{
    if(l+1 == r)
    {
        return l;
    }

    int m = (l+r)>>1;
    int count = a->left->count - b->left->count;
    if(count >= k)
        return query(a->left, b->left, l, m, k);

    return query(a->right, b->right, m, r, k-count);
}



int a[N], RM[N];
node *root[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    map <int, int> M;
    rep(i, n)
    {
        scanf("%d", &a[i]);
        M[a[i]];
    }

    int maxi = 0;

    for(map <int, int> :: iterator it = M.begin(); it != M.end(); it++)
    {
        M[it->first] = maxi;
        RM[maxi] = it->first;
        maxi++;
    }

    null->left = null->right = null;
    rep(i, n)
    {
        // Build a tree for each prefix using segment tree of previous prefix
        root[i] = (i == 0 ? null : root[i-1])->insert( 0, maxi, M[a[i]] );
    }

    while(m--)
    {
        int u, v, k;
        scanf("%d%d%d", &u, &v, &k);
        u--;
        v--;

        int ans = query(root[v], (u==0?null:root[u-1]), 0, maxi, k);
        printf("%d\n", RM[ans]);
    }
}
