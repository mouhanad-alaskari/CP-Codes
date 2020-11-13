#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dbl;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// Input macros
#define si(n)                       scanf("%d",&n)
#define sii(a,b)                    scanf("%d%d",&a,&b)
#define sc(n)                       scanf(" %c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sll(a,b)                    scanf("%lld%lld",&a,&b)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf(" %s",n)
// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
const ll MOD = 1e9 + 7;
#define all(a)                      a.begin(), a.end()
#define lp(i,n) 					for(int i=0;i<(int)n;i++)
#define lp1(i,n)					for(int i=1;i<=(int)n;i++)
const ll LONG_INF = 1ll << 63 - 1ll;
//#ifdef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

///////////////////////////////////////////////////////////
int girl[30];
int main() {
	int t;
	si(t);
	while (t--) {
	memset( girl , 0 , sizeof girl ) ;
		int n, p;
		sii(p, n);

		lp(i,n)
		{
			int x, y;
			sii(x, y);
			girl[y] |= 1 << (x - 1);
		}
		int last=(1<<p);
		int mask;
		int mx=-1;
		int cnt;
		lp(i,last){
			cnt=0;
			mask=i;
			lp1(j,p){
				if((i&girl[j])==i)cnt++;
			}
			cnt+=bitcount(i);
			mx=max(mx,cnt);

		}
		printf("%d\n",mx);

	}

}
