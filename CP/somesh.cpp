#include<iostream>
using namespace std;
typedef
struct bstnode{
struct bstnode *lchild;
int data;
struct bstnode *rchild;}* bstptr;

void create(bstptr t,int d){
    bstptr temp=t;
while(temp!=NULL){
    if(temp->data>d){temp=temp->lchild;}
    else if(temp->data<d){temp=temp->rchild;}}
temp=new(struct bstnode);
temp->data=d;
temp->lchild=NULL;
temp->rchild=NULL;
}

void inorder(bstptr t){
if(t!=NULL){
    inorder(t->lchild);
    cout<<t->data<<" ";
    inorder(t->rchild);
}}

int main(){
int d;
bstptr p=NULL;
cout<<"enter data : ";
cin>>d;
while(d!=-1)
    {create(p,d);
     cout<<"enter data or -1 to stop : ";
     cin>>d;
    }
cout<<"tree ";
inorder(p);
return 0;
}
