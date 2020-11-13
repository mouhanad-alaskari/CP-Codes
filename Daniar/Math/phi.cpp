#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
int phi[N+11];
/// O(2*N)

void sieve_phi() {
    for(int i=1; i<=N; i++) { phi[i]=i; }

    for(int i=2; i<N; i++) {
        if ( phi[i] == i ) {
            for ( int j=i; j<N; j+=i ) {
                phi[j]/=1ll*i;
                phi[j]*=1ll*i-1;
            }
        }
    }
}

int main() {
    sieve_phi();

    int x=3521 , cnt=0;
    for(int i=1 ; i<=x ; i++) {
        if(__gcd(x,i) == 1) cnt++;
    }

    cout<<cnt<<endl;
    cout<<phi[x]<<endl;
    return 0;
}
