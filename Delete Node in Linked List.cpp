#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;

struct liist
{
	ll n;
	liist* next;
};
struct liist* head;

void del(ll d)
{
	liist* temp=head;
	if(d==1)
	{
		head=temp->next;
		free(temp);
		return;
	}
	for(ll t=0;t<d-2;t++)
	{
		temp=temp->next;
	}
	liist* temp1=temp->next;
	temp->next=temp1->next;
	free(temp1);
}

void insert(ll x, ll p)
{
	liist* temp=new liist();
	(*temp).n=x;
	temp->next=NULL;
	if(p==1)
	{
		temp->next=head;
		head=temp;
		return;
	}
	liist* temp1=head;
	for(ll t=0;t<p-2;t++)
	{
		temp1=(*temp1).next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}

void print()
{
	struct liist* temp=head;
	cout<<"The list is now:";
	while(temp!=NULL)
	{
		cout<<" "<<(*temp).n<<" ";
		temp=(*temp).next;
	}cout<<endl;
}

int main()
{
    ios;
	head=NULL;
	ll n,x,p,d;
	cout<<"Enter the number of Elements in List."<<endl;
	cin>>n;
	ll i=n;
	while(i)
	{
		cout<<"Enter the Element:"<<" ";
		cin>>x;
		cout<<"Enter the position where the number should be added:";
		cin>>p;
		insert(x,p);
		cout<<endl;
		
		print();
		i--;
	}
	cout<<"Enter the position of element which should be deleted:";
	cin>>d;
	cout<<endl;
	del(d);
	print();
	return 0;
}
