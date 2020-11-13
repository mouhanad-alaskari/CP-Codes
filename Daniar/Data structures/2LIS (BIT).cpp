#include<bits/stdc++.h>
using namespace std;

const int N =100100;
int bit[N] , mx;

int get(int i)
{
    int ret=0;
    while( i )
    {
        ret = max ( ret , bit[i]) ;
        i-=i&-i;
    }
    return ret;
}

void add(int i,int v)
{
    while( i< N  )
    {
        bit[i]= max ( v , bit[i] );
        i+=i&-i;
    }
}

int main ( )
{
    int n;
    scanf("%d",&n);
    for ( int i = 0 ; i < n ; i++ )
    {
        int x;
        scanf("%d",&x);
        add(x,get(x-1)+1);
        /// add(x,get(x)+1);  to add frquency
        mx=max(mx,x);
    }
    printf("%d",get(mx));
    return 0 ;
}
