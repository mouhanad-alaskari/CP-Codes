/**
*
* Author: Mouhanad
* Lang: GNU C++14
*
**/
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ii pair < int , int >
#define LS pair < ll , string >
typedef long long ll;
const int inf = 1<<30;
const int N =200100;
int n , ANS[N] , a[N] , q ;
struct tt {
int  l , r , k , id ;
};
tt Q[N] ;
map < int , int > mp ;
int frq[N] , above[N] , sqr ;
bool cmp ( tt a , tt b ){
if ( a.l/sqr == b.l/sqr ) return (((a.l/sqr)&1) ? a.r < b.r : a.r > b.r ) ;
return a.l/sqr < b.l/sqr ;
}
void add ( int x ){
 above[frq[x]]++;
 frq[x]++;
}
void del ( int x ){
 frq[x]--;
 above[frq[x]]--;
}
void solve() {
 scanf("%d%d",&n,&q);
 sqr = 350;
 for ( int i = 1;  i<= n ;i++ ) {
        scanf("%d",a+i);
   mp[a[i]] ;
 }
 int cnt =0  ;
 for ( auto &x : mp ){
      x.S = ++cnt ;
 }
 for ( int i = 1 ; i <= n ;i++ ) a[i]= mp[a[i]];
 for ( int i = 1;  i<= q ;i++ ){
     scanf("%d%d%d",&(Q[i].l),&(Q[i].r),&(Q[i].k));
     Q[i].id = i ;
 }
 sort(Q+1,Q+1+q,cmp);
 int L , R , l = 1, r=0 ;

 for ( int i = 1;  i<= q ; i++ ){
    L = Q[i].l , R=Q[i].r ;


    while ( r > R ){
       del(a[r]);
       r--;
     }
    while ( r < R ){
        r++;
        add(a[r]);
    }

    while ( l < L ){
         del(a[l]);
         l++;
    }
    while ( l > L ){
        l--;
        add(a[l]);
    }
 //   cerr << frq[1] << " " << frq[2] <<" " << frq[3] <<endl;
    ANS[Q[i].id] = above[0]-above[Q[i].k]  ;
    //cerr << l <<" " << r <<" " << L << " " << R <<endl;
 }
 for ( int i = 1 ; i <= q ; i++ )
    printf("%d\n",ANS[i]);
}
int main ( ){
int t ;
scanf("%d",&t);
while (t--){
    solve();
    mp.clear();
    memset( above , 0 , sizeof above );
    memset( ANS , 0 , sizeof ANS );
    memset( frq , 0 , sizeof frq );
}

return 0 ;
}
///     hilbert
/*
constexpr int logn = 20;
constexpr int maxn = 1 << logn;

long long hilbertorder(int x, int y)
{
	long long d = 0;
	for (int s = 1 << (logn - 1); s; s >>= 1)
	{
		bool rx = x & s, ry = y & s;
		d = d << 2 | rx * 3 ^ static_cast<int>(ry);
		if (!ry)
		{
			if (rx)
			{
				x = maxn - x;
				y = maxn - y;
			}
			swap(x, y);
		}
	}
	return d;
}
struct tt {
int  l , r , id ;
ll ord ;
inline void calcOrder() {
		ord = hilbertorder(l, r);
	}

};
bool cmp ( tt a , tt b ){
return a.ord < b.ord ;
}
*/

/// hilbert-v2

/*
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct tt {
int  l , r , id ;
int64_t ord ;
inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}

};
bool cmp ( tt a , tt b ){
return a.ord < b.ord;
}

*/
