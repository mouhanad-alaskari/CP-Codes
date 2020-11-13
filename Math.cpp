ll mul(ll a , ll b){
  return (a*b)%mod;
}
ll adl(ll a , ll b){
  return (a+b)%mod;
}
ll subl(ll a, ll b){
  return (a-b+mod)%mod;
}
ll fast(ll a , ll b){
  if(!b)return 1ll;
  ll res = fast(a,b/2);
  res = mul(res,res);
  if(b&1)return mul(res,a);
  return res;
}

fast divisor 
    d[1]=1;
for(int i=2;i<1000002;i++){
    d[i]=1;
    int x=i;
    for(int j=2;j*j<=x;j++){
        if( x%j )continue;
        int c = 0;
        while( x%j==0 )x/=j,c++;
        d[i]*=(c+1);
    }
    if( x!=1 )d[i]*=2;
}
================================================================
  fact 1 --> N
  inv[N-1] = pow(N-1,mod-2);
  for ( N-2 --> 1) inv[i] = inv[i+1]*(i+1)%mod ;


long long  GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a%b); }
long long LCM(ll a, ll b) { return a / GCD(a, b) * b; }

const long double pi =  3.1415926535897932385;
const long double E  = 2.71828182845904523536;
const long double eps = 1.0e-12;
const int mod = 1e9+7;



long double f(long double x,int t)
{
    long double res=1.0;
    for(int i=1; i<=t; i++)res*=x/i;
    return res;
}


long double Sine(long double x)
{
    long double pos = 1.0;
    x = fmod(x,(2.0*pi));
    if (x < 0.0)
    {
        x = -1.0 * x;
        pos = -1.0*pos;
    }
    if ((pi+eps)>x && x>(pi/2.0)) x = pi - x;//second
    if (x>pi && x <(1.5*pi + eps)) //third
    {
        x = x - pi;
        pos = -1.0 * pos;
    }
    if (x>(1.5*pi) && x <(2.0*pi+eps))//forth
    {
        x = 2.0*pi - x;
        pos = -1.0 * pos;
    }
    long double res=0.0;
    bool sign=1;
    for(int i=1; i<35; i+=2,sign=!sign)
        res+= (sign?1.0:-1.0)*f(x,i);
    res = res * pos;
    return res;
}

long double Cos(long double x)
{
    long double pos = 1.0;
    x = fmod(x,(2.0*pi));
    if (x<0.0) x = -1.0*x;
    if ((pi+eps)>x && x>(pi/2.0))//second
    {
        x = pi - x;
        pos = -1.0 * pos;
    }
    if (x>pi && x <(1.5*pi + eps)) //third
    {
        x = x - pi;
        pos = -1.0 * pos;
    }
    if (x>(1.5*pi) && x <(2.0*pi+eps))x = 2.0*pi - x;//forth

    long double res=0.0;
    bool sign=1;

    for(int i=0; i<35; i+=2,sign=!sign)
        res+=  ( sign?1.0:-1.0 )*f(x,i);
    res = pos * res;
    return res;
}

long double Tan(long double x)
{
    return Sine(x)/Cos(x) ;
}

============================================================================

double logten (double x)
{
	// it only calculates log10
	//x > 0
	const double eps = 1e-9;
	if (fabs(x - 1.0)<eps) return 0.0;
	if (fabs(x- 10.0)<eps) return 1.0;
	bool small = 0;
	if (x<1.0) 
	{
		small = 1;
		x = 1.0/x;
	}
	
	double ans = 1.0 ;
	for (int i = 0;;i++)
	{
		if (x < 10) break;
		x = x / 10.0;
		ans = ans + 1.0;
	}
	
	const double ln10 = 2.30258509299;// from web
	double wow = 10.0 - x;
	wow = wow / 10;
	double taylor = 0.0;
	for (double i = 1.0;i<1000.9;i = i + 1.0)// if I can be sure that x >1 the 1000 can be 200 and if x > 2 to 100 
	{
		taylor = taylor + wow /i;
		wow = wow / 10;
		wow = wow * (10 - x);
	}
	taylor = taylor / ln10;
	if (small) 
		return taylor - ans;
		
	return ans - taylor ;
}

double logall (double a,double b)
{
	
	const double eps = 1e-9;
	if (fabs(b - 1.0)<eps) return 0.0;
	if (fabs( a - b )<eps) return 1.0;
	
	//loga(x)/logb(x) = logb (a) 
	// loga(b) / log10(b) = log10(a) ==> loga(b) =...
	
	return logten (b) / logten (a);
	
}

=============================================================================


long long GCD( long long x, long long y){
    if(x <= 0)return y;
    if(y <= 0)return x;
    if(x%y == 0)
        return y;
    return GCD(y,x%y);
}
long long LCM(long long a,long long b)
{
    return (a/(GCD(a,b)))*b;
}

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (a * (b / gcd(a, b))); }
ll POWER(ll x,ll y, ll m){
    if(y==0) return 1;
    if(y%2==0) { ll temp= POWER(x,y/2,m);   temp*=temp; temp%=m;	return temp;}
    ll temp= POWER(x,y-1,m);    temp*=x;	temp%=m;	return temp;
}

ll POWER(ll x,ll y){
    if(y==0) return 1;
    if(y%2==0) { ll temp= POWER(x,y/2);   temp*=temp;  return temp;	}
    ll temp= POWER(x,y-1);    temp*=x;	return temp;
}

============================================================================


long long bc[MAXN+5][MAXN+5]; /* table of binomial coefficients */
ll c(int n, int m)
{
    if (n < m) return 0;
    if (n-m <= m)
        m = n-m;
    return bc[n][m];
}

void intialize()
{
    int i, j;
    for (i=0; i<=MAXN; i++)
        bc[i][0] = 1;
    for (j=0; j<=MAXN; j++)
        bc[j][j] = 1;
    for (i=1; i<=MAXN; i++)
        for (j=1; j<i; j++)
            bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
}




ll MPOW(ll a,ll p){
    if(p == 0) return 1;
    if(p == 1) return a%mod;
    ll x=MPOW(a,p/2);
    if( p%2 == 0) return ((x%mod)*x)%mod;
    return (((x%mod) *x%mod)*a)%mod;
}

ll Mncr(ll n,ll r)
{
    ll ans1=1,ans2=1;
    for(int i=1 ; i<=n ; i++){
        ans1*=i;
        ans1%=mod;
    }

    for(int i=1 ; i<=r ; i++){
        ans2*=i;
        ans2%=mod;
    }

     for(int i=1 ; i<=(n-r) ; i++){
        ans2*=i;
        ans2%=mod;
    }

    return (ans1*MPOW(ans2,mod-2))%mod;
}


//////////////////////////////////////
 mut[0]=1;
    for(int i=1 ; i<N ; i++) mut[i]=(i*(mut[i-1]))%mod;
ll POW_M(ll a,ll p,ll m)
{
    if(p == 0) return 1;
    if(p == 1) return a%m;
    ll x=POW_M(a,p/2,m);
    if( p%2 == 0) return ((x%m)*x)%m;
    return (((x%m) *x%m)*a)%m;
}

ll ncr_M(ll n,ll r)
{
    ll ans1=1,ans2=1;
    ans1*=mut[n];
    ans1%=mod;

    ans2*=mut[r];
    ans2%=mod;

    ans2*=mut[n-r];
    ans2%=mod;

    return (ans1*POW_M(ans2,mod-2,mod))%mod;
}
//////////////////////////
ll _sieve_size;         // ll is defined as: typedef long long ll;
bitset<10000010> bs;    // 10^7 should be enough for most cases
vector<int> primes;     // compact list of primes in form of vector<int>

void sieve() {         // create list of primes in [0..upperbound]
    _sieve_size = 1000000 + 7;   // add 1 to include upperbound
    bs.set();               // set all bits to 1
    bs[0] = bs[1] = 0;      // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
        /// cross out multiples of i starting from i * i!
        for (ll j = i + i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);   // add this prime to the list of primes
    }
}

bool vis[1000001];

ll primeFactors(ll N)   // remember: vi is vector<int>, ll is long long
{
    set<int> st;
    ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
    while (PF * PF <= N)   // stop at sqrt(N); N can get smaller
    {
        while (N % PF == 0)
        {
            N /= PF;    // remove PF
            st.insert(PF);
        }
        PF = primes[++PF_idx]; // only consider primes!
    }
    if (N != 1) st.insert(N); // special case if N is a prime
    return st.size(); // if N does not fit in 32-bit integer and is a prime
}
////////////////////////////////////////////////////
bool check(ll x,ll y){
	x=abs(x);
	y=abs(y);
	return x<=1.0*(1e18)/y;
}
