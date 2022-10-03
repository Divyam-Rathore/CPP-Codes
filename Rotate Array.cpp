#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={1,2,3,4,5};
	int x=arr[4];
//	cout<<x<<endl;
	int i;
	for( i=4;i>=0;i--)
	{	arr[i]=arr[i-1];cout<<i;}
	cout<<x<<endl;
	
	arr[0]=x;
	for(i=0;i<5;i++)
		cout<<arr[i]<<" ";
	return 0;
}
