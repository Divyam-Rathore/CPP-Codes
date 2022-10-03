#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
#define pb push_back
#define mp make_pair

struct tree{
    ll data;
    tree* left, *right;
};

tree* newNode(ll data){
    tree *New=new tree();
    New->data=data;
    New->left=NULL;
    New->right=NULL;
    return New;
}

void printLevelOrder(tree *node, queue<int> q){
    if(node==NULL)
    return;
    q.push(node->left->data);
    q.push(node->right->data);
    printLevelOrder(node->left,q);
    printLevelOrder(node->right,q);
    
    
}

int  main(){
    tree *head=newNode(1);
    head->left=newNode(2);
    head->left=newNode(3);
    head->left->left=newNode(4);
    head->left->right=newNode(5);
    queue<int> q;
    q.push(head->data);
    printLevelOrder(head,q);
    while(!q.empty())
    {cout<<q.front()<<" ";q.pop();}
}
