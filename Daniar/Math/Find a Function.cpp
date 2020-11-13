#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dbl;

const dbl eps = 1e-4;
const ll mod = 1e9+7;
const ll inf = 1<<30;

const int N=100;
dbl a[N];
vector<dbl>v1,v2,X,D,Y;

/// P.n(x)= y0 + Dy0(x-x0) + D2y0(x-x0)(x-x1) + D3y0(x-x0)(x-x1)(x-x2) + .............

dbl delta(dbl x,int p)
{
    dbl z=1.0;
    for(int i=0 ; i<p ; i++)
        z*=(x-X[i]);

    return z;
}

dbl function1(dbl x)
{
    dbl ans=0.0;
    for(int i=0 ; i<Y.size() ; i++)
        ans+=(Y[i])*delta(x,i);

    return ans;
}

int main()
{
    int d;
    cin>>d;
    for(int i=0 ; i<=d+2 ; i++) cin>>a[i];
    for(int msk=0 ; msk < (1<<(d+3)) ; msk++)
    {
        if(__builtin_popcount(msk) != d+1) continue;
        for(int i=0 ; i<=d+2 ; i++)
        {
            if(msk&(1<<i))
            {
                v1.push_back(a[i]);
                X.push_back(i);
            }
        }

        int P=1;
        while(P <= X.size())
        {
            for(int i=P ; i<X.size() ; i++) D.push_back(X[i]-X[i-P]);
            P++;
        }

        P=0;

        while(v1.size() || v2.size() )
        {
            if(v1.size())
            {
                Y.push_back(v1[0]);
                if(v1.size() > 1) for(int i=1 ; i<v1.size() ; i++) v2.push_back((v1[i]-v1[i-1]) / D[P++] );
                v1.clear();
            }
            else
            {
                Y.push_back(v2[0]);
                if(v2.size() > 1) for(int i=1 ; i<v2.size() ; i++) v1.push_back((v2[i]-v2[i-1]) / D[P++]  );
                v2.clear();
            }
        }


        vector<int>Error;

        for(int i=0 ; i<=d+2 ; i++)
            if(fabs(function1(i)-a[i]) > eps) Error.push_back(i);


        if(Error.size() == 1)
        {
            cout<<Error.back()<<endl;
            break;
        }

        Y.clear();
        X.clear();
        D.clear();
        v1.clear();
        v2.clear();
    }
}
