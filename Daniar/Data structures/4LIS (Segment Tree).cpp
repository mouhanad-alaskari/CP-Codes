#include<bits/stdc++.h>
using namespace std;

const int inf=1<<30;
const int N =100100;
int seg[N<<2] ;

void update(int nd,int L,int R,int idx,int val){
    if( L == R ){
        seg[nd]=val;
        return ;
    }
    int mid = (L+R) >>1;
    if( idx<=mid )
         update(nd<<1  ,  L  ,mid,idx,val);
    else update(nd<<1|1,mid+1, R ,idx,val);
    seg[nd]=max( seg[nd<<1] , seg[nd<<1|1] );
}

int query(int nd,int L,int R,int from,int to){
    if( from<=L && R<=to )return seg[nd];
    if( from>R || to<L )return -inf;

    int mid = (L+R) >>1;

    int leftAns = query(nd<<1  ,  L  ,mid,from,to);
    int rightAns= query(nd<<1|1,mid+1, R ,from,to);
    return max( leftAns ,rightAns );
}


int main(){
    int n;
    scanf("%d",&n);
    int ANS = 0 , x ;
    for (int i=0 ; i<n ; i++){
        scanf("%d",&x);
        int mx = 0 ;
        if ( x != 1 ) mx = query(1,1,n,1,x-1);
        ANS = max ( ANS , x ) ;
        update(1,1,n,x,mx+1);
    }

    printf("%d", query (1,1,n,1,ANS));
    return 0;
}
