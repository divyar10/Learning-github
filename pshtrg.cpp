#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f  first
#define s  second

ll a[100005];
pair <ll,ll> tree[400005];

void build( ll nd , ll si , ll ei ){

   if(si==ei){
     tree[nd].f=a[si];
     tree[nd].s=si;

   }
   else{
   ll mid=( si+ei )/2;

   build( 2*nd , si , mid );
   build( 2*nd+1 , mid+1 , ei );

   if(tree[2*nd].f>tree[2*nd+1].f){
       tree[nd].f=tree[2*nd].f;
       tree[nd].s=tree[2*nd].s;
    }
   else{
       tree[nd].f=tree[2*nd+1].f;
       tree[nd].s=tree[2*nd+1].s;
    }
   }
 }

void update( ll nd , ll si , ll ei , ll pos , ll val ){

   if(si==ei&&si==pos){
      a[pos]=val;
      tree[nd].f=val;
   }
   else{
   ll mid=( si+ei )/2;

   if(si<=pos&&mid>=pos )     update( 2*nd , si , mid , pos , val);
   else                       update( 2*nd+1 , mid+1 , ei , pos , val );

    if(tree[2*nd]>tree[2*nd+1]){
       tree[nd].f=tree[2*nd].f;
       tree[nd].s=tree[2*nd].s;
    }
    else{
       tree[nd].f=tree[2*nd+1].f;
       tree[nd].s=tree[2*nd+1].s;
    }
  }
}

pair <ll,ll> query( ll nd , ll si , ll ei , ll l , ll r ){

   if( r<si || l>ei )       return {-1000000005,100005};
   else if( l<=si && r>=ei )  return tree[nd];

   ll mid=(si+ei)/2;

   pair <ll,ll> p1,p2;

   p1=query( 2*nd , si , mid , l , r );
   p2=query( 2*nd+1 , mid+1 , ei , l , r );

   if(p1.f>p2.f)   return p1;
   else            return p2;

}

int main(){

   ll n,q;
   cin>>n>>q;

   for(ll i=1;i<=n;i++)    cin>>a[i];

   build(1,1,n);

   while(q--){
      ll x,y,z;
      cin>>x>>y>>z;

      if(x==1)    update(1,1,n,y,z);
      else{
        ll flag=0;
        vector < pair <ll,ll> > v;
        pair <ll,ll> max1=query(1,1,n,y,z),max2,max3;
        v.pb(max1);
        update(1,1,n,max1.s,-1);
        max2=query(1,1,n,y,z);
        v.pb(max2);
        update(1,1,n,max2.s,-1);
        max3=query(1,1,n,y,z);
        v.pb(max3);
        update(1,1,n,max3.s,-1);

        while((max2.f+max3.f)<=(max1.f)){
            max1=max2;
            max2=max3;
            max3=query(1,1,n,y,z);

            update(1,1,n,max3.s,-1);
            if(max3.f==(-1)){
                flag=1;
                break;
            }
            v.pb(max3);
        }
        if(!flag)    cout<<max1.f+max2.f+max3.f<<endl;
        else         cout<<0<<endl;

        ll sz=v.size();
        for(ll i=sz-1;i>=0;i--)     update(1,1,n,v[i].s,v[i].f);
        v.clear();
      }

    }
  return 0;
}
