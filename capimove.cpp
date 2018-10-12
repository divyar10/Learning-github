#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        ll u,v;
        cin>>n;
        map <ll,ll> m;
        vector <ll> adj[n];
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            m.insert(pair<ll,ll>(x,i));
        }
        for(ll i=0;i<n-1;i++)
        {
            cin>>u>>v;
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }
        for(ll i=0;i<n;i++)
        {
            auto it=m.rbegin();
            for(it;it!=m.rend();it++)
            {
                ll flag=0;
                if(it->second==i)
                    flag=1;
            for(ll j=0;j<adj[i].size();j++)
            {
                if(flag==1)
                    break;
                if(it->second==adj[i][j])
                  {
                    flag=1;
                    break;
                   }
            }
            if(flag==1)
               continue;
            else
             {
                cout<<(it->second+1)<<" ";
                break;
             }
           }
        }
     }
    return 0;
}
