#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dbl;

const dbl eps = 1e-9;
const ll mod = 1e9+7;
const ll inf = 1LL<<30;

bool IsPrimeSlow(ll x)
{
    if(x<=1) return false;
    if(x<=3) return true;
    if (!(x%2) | !(x%3)) return false;
    ll s=(ll)(sqrt((double)(x))+eps);
    for(ll i=5 ; i<=s ; i+=6)
        if (!(x%i) || !(x%(i+2)))
            return false;

    return true;
}

ll Cnr(ll n,ll r)
{
    r=min(r,n-r);
    ll ans=1;
    for(ll i=1 ; i<=r ; i++)
    {
        ans*=(n--);
        ans/=i;
    }

    return ans;
}

ll POW(ll a , ll p )
{
    if( p==0 )return 1;
    if( p==1 )return a;
    ll x=POW(a,p/2);
    if( p%2==0) return ((x)*x);
    return (((x)*x)*a);
}


ll POW_M(ll a,ll p,ll m)
{
    if(p == 0) return 1;
    if(p == 1) return a%m;
    ll x=POW_M(a,p/2,m);
    if( p%2 == 0) return ((x%m)*x)%m;
    return (((x%m) *x%m)*a)%m;
}

ll Cnr_M(ll n,ll r)
{
    r=min(r,n-r);
    ll ans1=1,ans2=1;
    for(ll i=1 ; i<=r ; i++)
    {
        ans2*=i;
        ans1*=n--;

        ans2%=mod;
        ans1%=mod;
    }
    return (ans1*POW_M(ans2,mod-2,mod))%mod;
}
