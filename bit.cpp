#include <bits/stdc++.h>
using namespace std;

const int MX= 1<<10;
int n ;
char s[100100] , t[100100] , u[100100];
int bit[MX];

int get(int i){
int ret=0;
while( i ){
    ret+=bit[i];
    i-=i&-i;
}
return ret;
}

void add(int i,int v){
while( i<MX ){
    bit[i]+=v;
    i+=i&-i;
}
}



int main(){

scanf("%s",s);
n=strlen(s);
for(int i=0;i<n;i++)add(s[i],1);

int i=0,j=-1,k=0;
while( k<n ){

    if( i==n ){
        while( j>=0 )u[k++]=t[j--];
            break;
    }

    if( j<0 ){
        t[++j]=s[i];
        add(s[i++],-1);
        continue;
    }

    if( get(t[j]-1) ){
       t[++j]=s[i];
       add(s[i++],-1);
    }else{

    u[k++]=t[j--];

    }

}

for(int i=0;i<n;i++)printf("%c",u[i]);printf("\n");

return 0;
}