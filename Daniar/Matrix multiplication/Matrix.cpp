#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 +7;

struct Matrix {
    int N;
    ll a[101][101];

    Matrix(){N=100;}
    Matrix(int n){N=n;clear();}

    void clear(){memset(a,0,sizeof a);}
    void one(){for(int i=0; i<N; i++)a[i][i]=1;}

    Matrix operator *(Matrix B) {
        Matrix  A  = *this;
        Matrix ret = Matrix(N);
        ret.clear();

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++){
                ret.a[i][j]=0;

                for(int k=0; k<N; k++)
                    ret.a[i][j]=( ret.a[i][j] + A.a[i][k]*B.a[k][j]%mod   )%mod;

            }
        }

        return ret;
    }

    Matrix pwr(ll K) {
        Matrix  A  = *this;
        Matrix ret = Matrix(N);
        ret.clear();
        ret.one();

        while( K>0 ) {
            if( K&1 )ret=ret*A;
            A=A*A;
            K>>=1;
        }
        return ret;
    }

};


int main()
{
    int n;
    cin>>n;

    Matrix m=Matrix(2);
    m.a[0][0]=m.a[0][1]=m.a[1][0]=1;
    m.a[1][1]=0;

    m=m.pwr(n-1);
    ll ans = (m.a[0][0]+m.a[0][1])%mod;
    cout<<ans<<endl;

    return 0;
}
