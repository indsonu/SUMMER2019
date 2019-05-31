#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=100005;
long long int lazy[4*N];
long long int tree[4*N];
void build(int low,int high,int node)
{
    if(low>high)
    return;
    if(low == high)
    {
        tree[node]=0;
        return;
    }
    int mid = low+high>>1;
    build(low,mid,2*node);
    build(mid+1,high,2*node+1);
    tree[node]=tree[2*node]+tree[2*node+1];
}
void updateQuery(int node,int s,int e,int qs,int qe,int inc){
    if(lazy[node]){
        tree[node]+=lazy[node]*(e-s+1);
        if(s!=e){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(qs>e ||s>qe)
    return;
    else if(s==e){
        tree[node]+=inc*(e-s+1);
        if(s!=e){
          lazy[node * 2] += inc;
          lazy[node * 2+1] += inc;
        }
        return;
    }
    int mid=(s+e)>>1;
    updateQuery(node*2,s,mid,qs,qe,inc);
    updateQuery(node*2+1,mid+1,e,qs,qe,inc);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int sumQuery(int node,int s,int e,int qs,int qe){
    if(lazy[node]!=0){
        tree[node]+=lazy[node]*(e-s+1);
        if(s!=e){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(qs>e || s>qe){
        return 0;
    }
    if(s>=qs && e<=qe){
        return tree[node];
    }
    int mid=(s+e)>>1;
    return sumQuery(node*2,s,mid,qs,qe)+sumQuery(node*2+1,mid+1,e,qs,qe);
}
int main(){IOS
    int t;
    scanf("%d",&t);
    int n,q;
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        scanf("%d %d",&n,&q);
        int type;
        int x,y;
        long long int val;
        build(1,n,1);
        while(q--)
        {
            scanf("%d",&type);
            if(type)
            {
                scanf("%d %d",&x,&y);
                printf("%lld\n",sumQuery(1,1,n,x,y));
            }
            else
            {
                scanf("%d %d %lld",&x,&y,&val);
                updateQuery(1,1,n,x,y,val);
            }
        }
         
    }
     
    return 0;
     
}
