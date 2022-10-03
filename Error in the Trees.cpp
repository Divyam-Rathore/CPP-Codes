#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;

struct liist
{
	ll num;
	liist* next;
};
struct liist* head;

void Insert(ll x, ll p)
{
	liist* temp=new liist();
	temp->num=x;
	temp->next=NULL;
	liist* temp1=head;
	if(p==1)
	{
		temp->next=head;
		head=temp;
		return;
	}
	for(ll m=0;m<p-2;m++)
	{
		temp1=temp->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}

void del(ll d)
{
	liist* temp=head;
	if(d==1)
	{
		head=temp->next;
		free(temp);
		return;
	}
	for(ll m=0;m<d-2;m++)
	{
		temp=temp->next;
	}
	liist* temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
}

void print()
{
    liist* temp=head;
    while(temp!=NULL)
    {
        cout<<" "<<temp->num<<" ";
    }
    cout<<endl;
}

int main()
{
	ios;
	head=NULL;
	ll n;
	ll i=n;
	cin>>n;
	ll x,p;
	while(i)
	{
	    cout<<"qwert"<<n<<endl;
		cin>>x>>p;
		Insert(x,p);
		print();
		i--;
	}
	ll d;
	cin>>d;
	//del(d);
	print();
	return 0;
}
