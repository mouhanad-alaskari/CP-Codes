#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

vector < ll > gen ;

void generatelucky ( ll x )
{
    if (x > (int ) 1e9+3 ) return ;

    gen.push_back((x*10)+4);
    gen.push_back((x*10)+7);
    generatelucky((x*10)+4);
    generatelucky((x*10)+7);

}
int main ()
{
    int n , cnt = 0 ;

    cin>> n;

    generatelucky(0);

  sort(gen.begin() , gen.end());
    for (int i =0 ; i < gen.size() ; i++)
        if(n == gen[i])
        {
            cout<<i+1<<endl;
            break;
        }
    return 0 ;
}





for(int i=1;i<=n;i++){
    scanf("%d",a+i);
 
   if( last[ a[i] ] ){
    nxt[last[a[i]]]=i;
   }
    last[a[i]]=i;
}