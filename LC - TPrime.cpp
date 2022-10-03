#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;

int main()
{
    ios;
    ll n;
    cin>>n;
    while(n)
    {
        ll num;
        cin>>num;
        ll count=0,b=0;
        for (ll i=num;i>0;i--)
        {
            n--;
            if(count==4)
            {
                cout<<"NO"<<endl<<b;
                return 0;
            }
            if(num%i==0)
            count++;
            b++;
            cout<<b<<endl;
        }
        if(count==3)
        cout<<"YES"<<endl;
    }
	return 0;
}
