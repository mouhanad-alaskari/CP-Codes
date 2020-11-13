#include<bits/stdc++.h>
using namespace std;
const int N = 100100;
int p[N],comp;

int Par(int i){ return p[i]=( i==p[i] )?i:Par(p[i]); }
bool same(int i,int j){ return Par(i)==Par(j); }

void mrg(int i,int j){
    if(same(i,j))return;
    i=Par(i);
    j=Par(j);
    if( rand()&1 )swap(i,j);
    p[i]=p[j];
    comp--;
}

int main(){
    for(int i=1; i<=N; i++)p[i]=i;
    int n;
    scanf("%d",&n);
    comp=n-1;
}
