#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ll a,b;
    set <ll> s;
    cin>>a>>b;

    ll d=__gcd(a,b);

    for(ll i=1;i<=sqrt(d);i++)
    {
        if(d%i==0)
        {
            s.insert(i);
            s.insert(d/i);
        }
    }

    ll q;
    cin>>q;
    while(q--)
    {
        ll low,high;
        cin>>low>>high;

        auto it=s.lower_bound(high);

        if(*it>=low)    cout<<*it<<endl;
        else            cout<<"-1"<<endl;
    }
    return 0;
}
