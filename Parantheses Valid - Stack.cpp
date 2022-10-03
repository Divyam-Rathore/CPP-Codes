#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;

struct liist
{
	ll n;
	liist* next;
};
liist* head=NULL;

void Push()
{
	liist* temp=new liist();
	temp->n=1;
	temp->next=head;
	head=temp;
	return;
}

void Pop()
{
	liist* temp=head;
	head=temp->next;
	free(temp);
	return;
}

void print(void)
{
	liist* temp=head;
	cout<<endl<<"The list is now: ";
	while(temp!=NULL)
	{
		cout<<temp->n<<" ";
		temp=temp->next;
	}cout<<endl;
}

int main()
{
    ios;
	head=NULL;
	ll times;
	cin>>times;
	cout<<"Enter the elements(To Exit Press Enter): "<<endl;
	char ok;
	cin>>ok;
	while(times--)
	{
		if (ok=='(')
			Push();
		//liist* temp=head;
		else if(ok==')' && head->n==1)
			Pop();
		cin>>ok;
	}
	if(head==NULL)
		cout<<"Parantheses Balanced.";
	else
		cout<<"Parantheses Unblanaced.";
	return 0;
}
