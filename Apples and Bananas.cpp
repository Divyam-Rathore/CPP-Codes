#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(a) a.begin(), a.end()
typedef signed long long ll;
 
int main()
{
    ios;
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;
        cin>>n;
        vector<char> v;
        string s;
        int a=0;int b=0;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='A')
                a++;
            else
                b++;
        }
        cout<<"Case #"<<k<<": ";
        if(abs(a-b)>2)
            cout<<'N';
        else
            cout<<'Y';
        cout<<endl;
    }
	return 0;
}
