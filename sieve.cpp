
bool prime[1000006];
void sieve( int lower){

for(int i=2;i<lower ;i++)prime[i]=1;
prime[0]=prime[1]=0;

for(int i=2;i*i<lower;i++)
    if( prime[i] )
        for(int j=i*i;j<lower;j+=i){
            prime[j]=0;
        }

}

bool prime(int p){
if( p < 2 )return 0;
if( p%2==0)return 0;
if( p%3==0)return 0;
if( p%5==0)return 0;
for(int i=2;i*i<=p;i++)
    if( p%i==0 )
        return 0;
return 1;
}