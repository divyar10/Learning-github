#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll a[100005],b[100005];
ll p[100005],sz[100005];
vector < pair <ll,ll> > v;

ll par(ll x){
    if(p[x]!=x)   p[x]=par(p[x]);
    return p[x];
}

ll dsu(ll u, ll v){

   ll p1=par(u),p2=par(v);
   if(p1==p2)
     return 0;
   else
   {
       if(sz[p2]>sz[p1])   swap(p1,p2);
        sz[p1]+=sz[p2];
        sz[p2]=0;
        p[p2]=p1;
        return 1;
    }

}

int main()
{
    ll n,ans=0;
    string s,t;

    cin>>n>>s>>t;

    for(ll i=0;i<n;i++){
        a[i]=int(s[i]-97);
        b[i]=int(t[i]-97);
    }

    for(ll i=0;i<26;i++){
        p[i]=i;
        sz[i]=1;
    }
     for(ll i=0;i<n;i++){
       ll sum=ans;
       if(a[i]!=b[i]){
           ans+=dsu(a[i],b[i]);
        }
       if(ans!=sum)  v.pb({a[i],b[i]});
    }

    cout<<ans<<endl;

    for(auto it=v.begin();it!=v.end();it++)      cout<<char((it->first)+97)<<" "<<char((it->second)+97)<<endl;

    return 0;
}
