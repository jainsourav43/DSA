#include<iostream>
#define null NULL
using namespace std;
typedef
struct dnode
{
	dnode *left;
	int data;
	dnode *right;
} *dptr;
void addbegin(dptr &d)
{
	cout<<"Enter the data you want to enter\n";
	int d1;
	cin>>d1;
	dptr t1,t2;
	t1=new dnode;
	t1->data=d1;
	t1->left=NULL;
	t1->right=d;
	d=t1;	
}
void addend(dptr d,int n)
{
	dptr t1,t2;
	t1=d;
	while(t1->right!=NULL)
	{
		t1=t1->right;
	}
	t2=t1;
	t1->right=new dnode;
	t1=t1->right;
	t1->data=n;
	t1->right=NULL;
	t1->left=t2;
}
void create(dptr d)
{
	dptr t1,t2;
	t1=d;int n;
	cout<<"\nEnter the first node u want to add\n";
	cin>>n;
	t1->left=NULL;
	t1->data=n;
	t1->right=NULL;
	while(n!=-1)
	{
	cout<<"Enter  the data or -1 to exit\n";
	cin>>n;
	if(n!=-1)
	{
		addend(d,n);
	}
   }
}
void display(dptr d)
{
	dptr t1,t2;
	t1=d;
	while(t1!=NULL)
	{
		cout<<t1->data<<"  ";
		t1=t1->right;
	}
	cout<<endl;
}
void addafter(dptr d,int n)
{
	dptr t1,t2,t3;
	t1=d;int n1;
	cout<<"Enter the data u wanna enter \n";
	cin>>n1;
	while(t1->data!=n)
	{
		t1=t1->right;
	}
	t3=t1;
	t2=t1->right;
	t1->right=new dnode;
	t1=t1->right;
	t1->left=t1;
	t1->data=n1;
	t1->right=t2;
	t1->right->left=t1;
}
void addbefore(dptr d,int n)
{
	dptr t1,t2,t3;
	t1=d;int n1;
	cout<<"ENter the data u wanna enter \n";
	cin>>n1;
	while(t1->data!=n)
	{
		t1=t1->right;
	}
	t2=t1->left;
	t3=t1;
	t1->left=new dnode;
	t1=t1->left;
	t1->data=n1;
	t1->right=t3;
	t1->left=t2;
	t1->left->right=t1;	
}
void deleteend(dptr d)
{
	dptr t1,t2;
	t1=d;
	while(t1->right!=NULL)
	{
		t1=t1->right;
	}
	t1->left->right=NULL;
	t2=t1;
		delete(t2);
}
void deletebegin(dptr &d)
{
	dptr t1,t2;
	t1=d;
	d=d->right;
	d->left=NULL;
	delete(t1);
}
void deleteatpos(dptr d,int n)
{
	dptr t1,t2;
	t1=d;
	while(t1->data!=n)
	{
		t1=t1->right;
	}
	t2=t1;
	t1->left->right=t1->right;
	t1->right->left=t1->left;
	delete(t2);
}
void deletebefore(dptr d,int n)
{
	dptr t1,t2;
	t1=d;
	while(t1->data!=n)
	{
		t1=t1->right;
	}
	t2=t1->left;
	t1->left->left->right=t1;
	t1->left=t1->left->left;
	delete(t2);
}
void deleteafter(dptr d,int n)
{
	dptr t1,t2;
	t1=d;
	while(t1->data!=n)
	t1=t1->right;
	t2=t1->right;
	t1->right->right->left=t1;
	t1->right=t1->right->right;	
	delete(t2);
}
int  check(dptr l1,dptr l2)
{
if(l1==null&&l2==null)
{cout<<"2\n";
	return 1;
}
else if(l1->data!=l2->data)
{
cout<<"1\n";
return 0;

}
else 
{cout<<"\n3\n";
	return check(l1->left,l2->right);
}
}	
int main()
{
	dptr l;int item;int ch;int d;
	l=new struct dnode;
	dptr l1=new  struct dnode;
while(1)
  {
  cout<<"A heartly welcome to the world of linked list\n";
  cout<<"1 for creating the linked list\n";
  cout<<"2 for insert at end \n";
  cout<<"3 for displaying \n";
  cout<<"4 for insert at begigning"<<endl;
  cout<<"5 for add after node \n";
  cout<<"6 for add before node\n";
  cout<<"7 for delete at begigning\n";
  cout<<"8 for delete at end \n";
  cout<<"9 for delete at nth position \n";
  cout<<"10 for delete before\n";
  cout<<"11 for delete after\n";
  cout<<"Please enter your choice"<<endl;
  cin>>ch;
  switch(ch)
  {
  	case 1 :
  		{
  			//node *tmp;
  		create(l);
  		cout<<"Enter the input for second\n";
  		create(l1);
  			break;
		  }
		  case 2 :
		  	{
		  	cout<<"enter the data\n";
			  cin>>d;
			  addend(l,d);	
			  break;
			  }
			  case 3:
			  	{
			  		display(l);
			  		break;
				  }
				  case 4 :
				  	{
				  		//cout<<"Enter the number \n";
				  		//cin>>d;
				  	   addbegin(l);
				  		break;
					  }
					  case 5 :
					  	{
					  		cout<<"enter the item\n";
					  		cin>>item;
					  		addafter(l,item);
					  		break;
						  }
						  case 6 :
						  	{
						  		cout<<"enter the item\n";
						  		cin>>item;
						  		addbefore(l,item);
						  		break;
							  }
							  case 7:
							  	{
							  	
							  		deletebegin(l);
							  		break;
								  }
								  case 8:
								  	{
                                       deleteend(l)	;		
									   	break;
									  }
									  case 9:
									  	{
									  	cout<<"enter the data\n";
									  	cin>>d;
                                          deleteatpos(l,d)	;		
		       						  	break;
										  }
										  case 10:
										  	{
											  cout<<"Enter the number before u wish to delete\n";
										  	  cin>>d;
										  		deletebefore(l,d);
											  }
											  break;
											  case 11:
											  	{
											  		cout<<"Enter the number after  which u wish to delete\n";
											  		cin>>d;
											  		deleteafter(l,d);
												  }
												  break;
												  case 12:
												  	{
												  		while(l->right!=null)
												  		{
												  			l=l->right;
												  			
														  }cout<<"\nL ="<<l->data<<"  ";
														  cout<<"|nl1 ="<<l1->data<<"  ";
														  int y=check(l,l1);
														  cout<<"\nY = "<<y<<endl;
													  }
													  break;
											  default :
											  	cout<<"wrong choice\n";
  }
  }

}
