#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f(i,a,n) for(ll i=a;i<n;i++)
#define all(a) a.begin(), a.end()
typedef long long ll;
vector<struct node*> v;

ll ma=0;

struct node
{
    ll data;
    node *left, *right;
};

node* newNode(ll data)
{
	node * nod=new node;
	nod->data=data;
	nod->left=nod->right=NULL;
	return nod;
}


void inorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

// node* ternary(string s)
// {
// 	node* root=newNode(s[0]);
//     queue<char> q;
// 	for(ll i=1;i<s.length();i++)
// 	{

// 	}
// }

node* lca(node* root,ll n1,ll n2)
{
	if(root==NULL)
		return NULL;
	if(root->data==n1 || root->data==n2)
		return root;
	node* llca=lca(root->left,n1,n2);
	node* rlca=lca(root->right,n1,n2);
	if(llca && rlca)
		return root;
	return (llca!=NULL)?llca:rlca;
}

int main()
{
    ios;
    // node* root = newNode(-15); 
    // root->left = newNode(5); 
    // root->right = newNode(6); 
    // root->left->left = newNode(-8); 
    // root->left->right = newNode(1); 
    // root->left->left->left = newNode(2); 
    // root->left->left->right = newNode(6); 
    // root->right->left = newNode(3); 
    // root->right->right = newNode(9); 
    // root->right->right->right= newNode(0); 
    // root->right->right->right->left= newNode(4); 
    // root->right->right->right->right= newNode(-1); 
    // root->right->right->right->right->left= newNode(10);
	
	node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 

	string s="a?b?c:d:e";
	node* noot=lca(root,4,5);
	// cout<<"Inorder is"<<endl;
	// inorder(root);
	cout<<(noot->data)<<endl;
	return 0;
}