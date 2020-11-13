#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
bool prime[N];

void seive() {
    for(int i=2; i<N; i++) prime[i]=1;
    prime[0]=prime[1]=0;

    for(int i=2; i*i<N; i++) {
        if(prime[i]) {
            for(int j=i*i; j<N; j+=i) prime[j]=0;
        }
    }
}

int main()
{
    seive();
    return 0;
}
