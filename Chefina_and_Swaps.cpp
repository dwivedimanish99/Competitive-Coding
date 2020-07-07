#include<bits/stdc++.h>
#define ll long long
using namespace std;

void fast()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
}

void solve()
{
    ll n,x;
    cin>>n;
    vector<ll> a,b;
	map<ll,ll> c,d;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        if(c.find(x)==c.end())
        {
           c[x]=1;
        }
        else{
            c[x]++;            
        }
    }
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        if(d.find(x)==d.end())
        {
            d[x]=1;
        }
        else {
            d[x]++;
        }
    }
    if(c==d){cout<<0<<endl;return;}
    for(auto &i:c)
    {
        if(d.find(i.first) == d.end())
        {
            if(i.second%2!=0){cout<<-1<<endl;return;}
            else{
                a.insert(a.end(),i.second/2,i.first);
            }
        }
        else{
            if(i.second > d[i.first])
            {
                x=i.second-d[i.first];
                if(x%2!=0){cout<<-1<<endl;return;}
                else{
                    a.insert(a.end(),x/2,i.first);
                }
            }
            else{
                x=d[i.first]-i.second;
                if(x%2!=0){cout<<-1<<endl;return;}
                else{
                    a.insert(a.end(),x/2,i.first);
                }
            }
        }
    }

    for(auto &i:d)
    {
        if(c.find(i.first)==c.end())
        {
            if(i.second%2!=0){cout<<-1<<endl;return;}
            else b.insert(b.end(),i.second/2,i.first);
        }
        else{
            if(i.second > c[i.first])
            {
                x=i.second-c[i.first];
                if(x%2!=0){cout<<-1<<endl;return;}
                else{
                    b.insert(b.end(),x/2,i.first);
                }
            }
            else{
                x=c[i.first]-i.second;
                if(x%2!=0){cout<<-1<<endl;return;}
                else{
                    b.insert(b.end(),x/2,i.first);
                }
            }
        }
    }
    ll cost1=0,cost2=0,cost=0,ma=c.begin()->first,mb=d.begin()->first;
    ma=min(ma,mb);
    for(int i=0;i<a.size();i++)
    {
        cost1=min(ma*2,a[i]);
        cost2=min(ma*2,b[i]);
        cost+=min(cost1,cost2);
    }

    cout<<cost<<endl;
}

int main()
{
    fast();
    ll t;
    cin>>t;
    while(t--)solve();
    return 0;
}