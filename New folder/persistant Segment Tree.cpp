///problem link: https://w...content-available-to-author-only...j.com/problems/MKTHNUM/

// taken the idea of self pointer to avoid handling null pointer from coach fegla
#include <bits/stdc++.h>

using namespace std;
const int MAX = 4e6;
struct node{
    node* l,* r;
    int sz;
    node(){
      l = r = this;
      sz = 0;
    }
    static node* empty;

};
node nodes[MAX];
int nxt = 0;
node* node::empty = &nodes[0];
node* newNode(int sz = 0,node* l = node::empty,node* r = node::empty){
    nxt++;
    node *ret = &nodes[nxt];
    ret->sz = sz;
    ret->l = l;
    ret->r = r;
    return ret;
}
node* insert(node* prev,int val,int tl = -1e9,int tr = 1e9){
    if(val > tr || val < tl)return prev;
    if(tl == tr)return newNode(prev->sz+1);
    int mid = tl+(tr-tl)/2;
    node* l = insert(prev->l,val,tl,mid);
    node* r = insert(prev->r,val,mid+1,tr);
    return newNode(l->sz+r->sz,l,r);
}
int query(node* st,node* en,int k,int tl = -1e9,int tr = 1e9){
    if(tl == tr)return tl;
    int mid = tl+(tr-tl)/2;
    int lsz = en->l->sz - st->l->sz;
    if(k <= lsz)return query(st->l,en->l,k,tl,mid);
    else        return query(st->r,en->r,k-lsz,mid+1,tr);
}
const int N = 1e5+5;
node* roots[N];
int main(){
    roots[0] = newNode();
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n; ++i){
        int x;
        scanf("%d",&x);
        roots[i] = insert(roots[i-1],x);
    }
    for (int i = 0;i < m; ++i){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",query(roots[l-1],roots[r],k));
    }

    return 0;
}


////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100100;
int n , m ;
int val[N];
map<int,int>mp;
int idx[N] , t ;

struct node{
int cnt;
node *L,*R;

node(int c,node *l,node *r):
    cnt(c),L(l),R(r){}

node* add(int l,int r,int v);

};

node * emp=new node(0,NULL,NULL);

node* node::add(int l,int r,int v){

if( v<l || v>r )return this;
if( l == r )return new node(this->cnt+1,emp,emp);

int mid = l+r >>1;

return new node( this->cnt+1,
                 this->L->add( l ,mid,v),
                 this->R->add(mid+1,r,v) );
}

int query(node *a,node *b,int l,int r,int k){

if( l == r )return l;

int mid=l+r>>1;

if( (b->L->cnt) - (a->L->cnt) >=k )return query(a->L,b->L,l,mid,k);
k-=(b->L->cnt) - (a->L->cnt);
return query(a->R,b->R,mid+1,r,k);
}

node * root[N];

int main(){

scanf("%d %d",&n,&m);
for(int i=1;i<=n;i++){
    scanf("%d",val+i);
    mp[val[i]];
}

for(auto v:mp){
    mp[v.first]=++t;
    idx[t]=v.first;
}

emp->L = emp->R =emp;
root[0]=emp;

for(int i=1;i<=n;i++)
    root[i]= (root[i-1]->add(1,n, mp[val[i]] ));

int u , v , k ;
while( m-- ){

scanf("%d %d %d",&u,&v,&k);
int ans = query(root[u-1],root[v],1,n,k);
printf("%d\n",idx[ans]);

}

return 0;
}

