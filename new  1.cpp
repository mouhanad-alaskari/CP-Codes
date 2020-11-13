#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = (1<<25)+10 ;
int bits[MX], n, m, ans = MX ;
int mask[40];
string row[40] ;
void try_( int pos, int msk, int bomb )
{
    if( pos >= n )
    {
        int mx = max( bits[msk], bomb ) ;
        ans = min( ans, mx ) ;
        return ;
    }
    try_(pos+1,msk|mask[pos],bomb); // ignore and go
    try_(pos+1,msk,bomb+1); // put bomb then no bit will be on except the old one
}
void set_on(int x, int shft)
{
    mask[x] = mask[x] + ( 1 << shft ) ;
}
void set_off(int x, int shft)
{
    mask[x] = mask[x] - ( 1 << shft ) ;
}
bool is_off(int x, int shft)
{
    return !( mask[x] & ( 1 << shft ) ) ;
}
void check( int x, int y )
{
    if( row[x][y] == '*' )
        set_on(x,y) ;
//        else if( is_off(x,y) )
//        set_off(x,y) ;
}
int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    for(int i = 1 ; i < MX ; i++ )
        bits[i] = bits[i- ( i & (-i) ) ] + 1 ;
//        for( int i = 0 ; i < (1<<3) ; ++i )
//           cout<<i<<" "<<bits[i]<<"\n";
cerr << bits[31] <<endl;
    cin>>n>>m ;
    for( int i = 0 ; i < n ; i++ )
    {
        cin>>row[i] ;
        for( int j = 0 ; j < m ; j++ )
            check(i,j) ;
    }
    try_(0,0,0);

    cout<<ans<<"\n";
    return 0;
}
