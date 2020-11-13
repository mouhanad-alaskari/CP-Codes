#include <bits/stdc++.h>

using namespace std;
const int inf = 1<<30;
const int N =100100;
int n , a[N];
int seg[N<<2];

void build(int nd,int L,int R)
{
    if( L == R )
    {
        seg[nd]=a[L];
        return ;
    }
    int mid = (L+R) >>1;
    build(nd<<1  ,L , mid);
    build(nd<<1|1,mid+1,R);
    seg[nd]=max( seg[nd<<1] , seg[nd<<1|1] );
}

void update(int nd,int L,int R,int idx,int val)
{
    if( L == R )
    {
        seg[nd]=val;
        return ;
    }
    int mid = (L+R) >>1;
    if( idx<=mid )
        update(nd<<1  ,  L  ,mid,idx,val);
    else update(nd<<1|1,mid+1, R,idx,val);
    seg[nd]=max( seg[nd<<1] , seg[nd<<1|1] );
}


int query(int nd,int L,int R,int from,int to)
{
    if( from<=L && R<=to )return seg[nd];
    if( from>R || to<L )return -inf;

    int mid = (L+R) >>1;

    int leftAns = query(nd<<1  ,  L  ,mid,from,to);
    int rightAns= query(nd<<1|1,mid+1, R ,from,to);
    return max( leftAns ,rightAns );
}

int main()
{

    return 0;
}
