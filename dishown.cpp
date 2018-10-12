#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll p[100005];

ll par(ll x){
    if(p[x]!=x)  p[x]=par(p[x]);
    return p[x];
}

void dsu(ll u,ll v,ll s[]){
    ll p1=par(u),p2=par(v);
    if(p1==p2)  return;
    else
    {
        if(s[p2]>s[p1])
            p[p1]=p2;
        else if(s[p1]>s[p2])
            p[p2]=p1;
    }
}

int main()
{
    ll t;
    cin>>t;

    while(t--)
    {
        ll n,q;
        cin>>n;

        ll s[n+5];

        for(ll i=1;i<=n;i++)      cin>>s[i];

        for(ll i=1;i<=n;i++){
            p[i]=i;
            //cout<<par(i)<<endl;
        }
        cin>>q;
        while(q--)
        {
            ll x,y,z;
            cin>>x;
            if(x==0)
            {
                 cin>>y>>z;
                 //cout<<par(s[y])<<" "<<par(s[z])<<endl;
                 if(par(y)==par(z))
                  {
                    cout<<"Invalid query!"<<endl;
                    continue;
                  }
                 else   dsu(par(y),par(z),s);
            }
            else
            {
                cin>>y;
                cout<<par(y)<<endl;
            }
        }

    }
    return 0;
}

