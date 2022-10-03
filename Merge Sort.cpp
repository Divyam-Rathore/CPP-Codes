#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;

void merge(ll* a, ll s, ll e)
{
	ll mid=(s+e)/2;
	ll i=s;
	ll k=s;
	ll temp[s+e];
	ll j=mid+1;
	while(i<=mid && j<=e)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=e)
		temp[k++]=a[j++];
	for(ll m=s;m<=e;m++)
		a[m]=temp[m];
}

void mergesort(ll* a, ll s, ll e)
{
	ll mid=(s+e)/2;
	if(s>=e)
		return;
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	merge(a,s,e);
}

int main()
{
    ios;
    ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll s=0;
	ll e=n-1;
	mergesort(a, s, e);
	for(ll x=0;x<n;x++)
	{
		cout<<a[x]<<" ";
	}
	return 0;
}
